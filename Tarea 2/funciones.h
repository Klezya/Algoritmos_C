#define infinito 2147000000

typedef int **Matriz;
typedef int *Arreglo;
typedef bool *ArregloBool;

ArregloBool creaArregloBool(int n)
{
    ArregloBool aux;
    int i;

    aux = calloc(n,sizeof(bool));
    if (aux == NULL)
    {
        printf("No hay memoria suficiente. Este programa se cerrar%c.", 160);
        exit(0);
    }
    return aux;
}
Arreglo creaArreglo(int n)
{
    Arreglo aux;
    int i;

    aux = calloc(n,sizeof(int));
    if (aux == NULL)
    {
        printf("No hay memoria suficiente. Este programa se cerrar%c.", 160);
        exit(0);
    }
    return aux;
}
Matriz creaMatriz(int n)
{
    Matriz aux;
    int i;

    aux = calloc(n,sizeof(int *));
    if (aux == NULL)
    {
        printf("No hay memoria suficiente. Este programa se cerrar%c.", 160);
        exit(0);
    }
    for (i=0; i<n; i++)
    {
        aux[i] = calloc(n,sizeof(int));
        if (aux[i] == NULL)
        {
            printf("No hay memoria suficiente. Este programa se cerrar%c.", 160);
            exit(0);
        }
    }
    return aux;
}
Matriz leeArchivo(char nomArchivo[20], int *pn, int *pm, int *ptipo)
{
    FILE *archivo;
    Matriz Grafo;
    int n, m, tipo, i, nodo1, nodo2, costo;

    archivo = fopen(nomArchivo, "r");
    if (archivo == NULL)
    {
        printf("Archivo no encontrado. Este programa se cerrar%c.", 160);
        exit(0);
    }
    fscanf(archivo, "%i", &n);
    fscanf(archivo, "%i", &m);
    fscanf(archivo, "%i", &tipo);
    Grafo = creaMatriz(n);
    for(i=1;i<=m;i++)
    {
        fscanf(archivo, "%i", &nodo1);
        fscanf(archivo, "%i", &nodo2);
        fscanf(archivo, "%i", &costo);
        Grafo[nodo1][nodo2] = costo;
        if (tipo == 2)
            Grafo[nodo2][nodo1] = costo;
    }
    fclose(archivo);
    *pn = n;
    *pm = m;
    *ptipo = tipo;

    return Grafo;
}
void imprimeMatrizGrafo(Matriz Grafo, int n)
{
    int i, j;

    printf("     ");

    for (i=0; i<n; i++)
        printf("%4i", i);

    printf("\n    ");

    for (i=0; i<n; i++)
        printf("----");

    printf("--\n");

    for (i=0; i<n; i++)
    {
        printf("%3i |", i);
        for (j=0; j<n; j++)
            printf("%4i", Grafo[i][j]);
        printf("\n");
    }
}
void reseteaVisitados(ArregloBool Visitados, int n)
{
    int i;

    for (i=0; i<n; i++)
        Visitados[i] = false;
}
void Profundidad(Matriz Grafo, int n, ArregloBool Visitados, int nodo)
{
    int i;

    Visitados[nodo] = true;
    printf("%i ", nodo);
    for (i=0; i<n; i++)
        if (Grafo[nodo][i] != 0 && Visitados[i] == false)
            Profundidad(Grafo, n, Visitados, i);
}
bool estaEnFila(Arreglo Fila, int n, int nodo)
{
    int i;

    for (i=0; i<n; i++)
    {
        if (Fila[i] == nodo)
            return true;
    }
    return false;
}
void Amplitud(Matriz Grafo, int n, ArregloBool Visitados, int v0)
{
    int i, nodo, largoFila, posInicial;
    Arreglo Fila;

    Fila = creaArreglo(n);
    largoFila = 0;
    posInicial = 0;

    Fila[posInicial] = v0;
    largoFila++;

    while (posInicial < largoFila)
    {
        nodo = Fila[posInicial];
        posInicial++;

        if (!Visitados[nodo])
        {
            Visitados[nodo] = true;
            printf("%i ", nodo);

            for (i=0; i<n; i++)
                if (Grafo[nodo][i] != 0 && !Visitados[i] && !estaEnFila(Fila, n, i))
                {
                   Fila[largoFila] = i;
                   largoFila++;
                }
        }
    }
    free(Fila);
}
int numeroNodosSinVisitar(ArregloBool Visitados, int n)
{
    int i, cont;

    cont=0;
    for (i=0; i<n; i++)
    {
        if (!Visitados[i])
            cont++;
    }
   return cont;
}
int nodoDeMinimoCostoSinVisitar(Arreglo Costo, ArregloBool Visitados, int n)
{
    int i, nodo, minimo;
    bool esElPrimero;

    esElPrimero = true;
    for (i=0; i<n; i++)
        if (!Visitados[i])
        {
            if (esElPrimero)
            {
                minimo = Costo[i];
                nodo = i;
                esElPrimero = false;
            }
            else
                if (Costo[i] < minimo)
                {
                    minimo = Costo[i];
                    nodo = i;
                }
        }
    return nodo;
}
void imprimeCaminos(Arreglo Predecesor, Arreglo Costo, ArregloBool Visitados, int n, int v0)
{
    Arreglo Camino;
    int i, j, nodo;

    Camino = creaArreglo(n);
    for (i=0; i<n; i++)
    {
        if (i != v0)
        {
            if (Costo[i] == infinito)
                printf("\nDe %2i a %2i (costo: --): No existe Camino", v0, i);
            else
            {
                Camino[0] = i;
                nodo = Predecesor[i];
                for (j=1; nodo!=v0; j++)
                {
                    Camino[j] = nodo;
                    nodo = Predecesor[nodo];
                }
                Camino[j] = nodo;
                printf("\nDe %2i a %2i (costo: %2i):", v0, i, Costo[i]);
                for (; j>=0; j--)
                    printf(" %i", Camino[j]);
            }
        }
    }
    free(Camino);
}
void Dijkstra(Matriz Grafo, int n, int v0)
{
    int i, w=0;
    ArregloBool Visitados;
    Arreglo Costo, Predecesor;

    Visitados = creaArregloBool(n);
    Costo = creaArreglo(n);
    Predecesor = creaArreglo(n);

    Visitados[v0] = true;
    for (i=0; i<n; i++)
    {
        if (Grafo[v0][i] == 0)
            Costo[i] = infinito;
        else
            Costo[i] = Grafo[v0][i];
        Predecesor[i] = v0;
    }
    while (numeroNodosSinVisitar(Visitados, n) > 1 && w != -1)
    {
        w = nodoDeMinimoCostoSinVisitar(Costo, Visitados, n);
        if (w != -1)
        {
            Visitados[w] = true;
            for (i=0; i<n; i++)
                if (Grafo[w][i] != 0 && !Visitados[i])
                    if (Costo[w] + Grafo[w][i] < Costo[i])
                    {
                        Costo[i] = Costo[w] + Grafo[w][i];
                        Predecesor[i] = w;
                    }
        }
    }
    imprimeCaminos(Predecesor, Costo, Visitados, n, v0);
    free(Visitados);
    free(Costo);
    free(Predecesor);
}
