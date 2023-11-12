#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};

typedef struct nodo tNodo;
typedef tNodo *ABO;

/// INICIO Funciones para imprimir el ABO: debes usar "imprimeArbol(A);".
int maximo(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int profundidad(ABO A)
{
    if (A == NULL)
        return 0;
    else
        return maximo(profundidad(A->izq), profundidad(A->der)) + 1;
}

void imprimeElementosNivel(ABO A, int nivel)
{
    if (A == NULL)
        printf("-");
    else
    {
        if (nivel == 0)
            printf("%i", A->info);
        else
        {
            imprimeElementosNivel(A->izq, nivel-1);
            printf("|");
            imprimeElementosNivel(A->der, nivel-1);
        }
    }
 }

void imprimeArbol(ABO A)
{
    int h, i;

    h = profundidad(A);
    for(i=0;i<h;i++)
    {
        printf("\n");
        imprimeElementosNivel(A, i);
    }
}
/// FIN Funciones para imprimir
/*
Entradas: entero
Salida: ABO
Proceso: crea en memoria y retorna un puntero a nodo (e.d. un ABO) con el entero recibido como información
         (en el campo "info"), y con los punteros a izquierdo y direcho apuntando a NULL (campos izq y der.
Validación Externa: -
*/
ABO creaNodo(int valor)
{
    ABO aux;

    aux = malloc(sizeof(tNodo));
    if (aux == NULL)
    {
        printf("No hay memoria suficiente. Este programa se cerrar%c.", 160);
        exit(0);
    }
    aux->info = valor;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

/*
Entradas: ABO, entero
Salida: ABO
Proceso: inserta el entero en el ABO recibido, siguiendo las reglas de un ABO.
Validación Externa: el entero NO debe estar en el ABO.
*/
ABO insertaABO(ABO A, int valor)
{

}

/*
Entradas: ABO, entero
Salida: bool
Proceso: Retorna true si el entero está en el ABO, y false en caso contrario
Validación Externa: -
*/
bool estaEnABO(ABO A, int valor)
{

}

/*
Entradas: ABO
Salida: entero
Proceso: retorna el peso (cantidad de nodos) del ABO.
Validación Externa: -
*/
int peso(ABO A)
{

}

/*
Entradas: ABO
Salida: entero
Proceso: retorna la altura del ABO.
Validación Externa: -
*/
int altura(ABO A)
{

}

/*
Entradas: ABO
Salida: entero
Proceso: Retorna el menor elemento presente en el ABO.
Validación Externa: El ABO no puede estar vacío.
*/
int menorABO(ABO A)
{

}

/*
Entradas: ABO
Salida: entero
Proceso: Retorna el mayor elemento presente en el ABO.
Validación Externa: El ABO no puede estar vacío.
*/
int mayorABO(ABO A)
{

}

/*
Entradas: ABO
Salida: entero
Proceso: retorna la suma de los elementos contenidos en el ABO.
Validación Externa: el ABO no puede estar vacío.
*/
int suma(ABO A)
{

}

/*
Entradas: ABO
Salida: -
Proceso: imprime por pantalla hacia el lado y separado por un espacio cada elemento, el recorrido en preorden del ABO.
Validación Externa: -
*/
void preOrden(ABO A)
{

}

/*
Entradas: ABO
Salida: -
Proceso: imprime por pantalla hacia el lado y separado por un espacio cada elemento, el recorrido en inorden del ABO.
Validación Externa: -
*/
void inOrden(ABO A)
{

}

/*
Entradas: ABO
Salida: -
Proceso: imprime por pantalla hacia el lado y separado por un espacio cada elemento, el recorrido en postorden del ABO.
Validación Externa: -
*/
void postOrden(ABO A)
{

}

/*
Entradas: ABO
Salida: bool
Proceso: retorna true si el ABO recibido es una hoja. El proceso NO es recursivo.
Validación Externa: el ABO no puede estar vacío.
*/
bool esHoja(ABO A)
{

}

/*
Entradas: ABO, entero
Salida: entero
Proceso: retorna el nivel en el que está el entero recibido dentro del ABO.
Validación Externa: el entero debe estar en el ABO.
*/
int nivelDeUnNodoABO(ABO A, int valor)
{

}

/*
Entradas: ABO, entero
Salida: bool
Proceso: imprime por pantalla el padre del entero recibido.
Validación Externa: el entero debe estar en el ABO y NO debe ser la raíz.
*/
void padreNodoABO(ABO A, int valor)
{

}

/*
Entradas: ABO, entero
Salida: -
Proceso: imprime por pantalla los antecesores entero recibido.
Validación Externa: el entero debe estar en el ABO y NO debe ser la raíz.
*/
void antecesoresNodoABO(ABO A, int valor)
{

}

/*
Entradas: ABO, entero
Salida: bool
Proceso: imprime por pantalla los hijos (si tiene) del entero recibido. Si no tiene hijos imprime un mensaje
         indicándolo. Además, retorna true si el ABO tiene al menos un hijo y false en caso contrario.
Validación Externa: el entero debe estar en el ABO.
*/
bool hijosNodoABO(ABO A, int valor)
{

}

/*
Entradas: ABO, entero
Salida: bool
Proceso: imprime por pantalla los descendientes del entero recibido.
Validación Externa: el entero debe estar en el ABO.
*/
void DescendientesNodoABO(ABO A, int valor)
{

}

/*
Entradas: ABO
Salida: -
Proceso: imprime por pantalla la información solicitada por el enunciado de la tarea, llamando a las funciones descritas
         arriba, cuidando el realizar las validaciones mencionadas en cada función. Esto incluye la solicitud de un elemento
         del ABO que SI esté en él
Validación Externa: -
*/
void analizaArbolBinarioOrdenado(ABO A)
{
    int valor;
    bool valorValido, tieneHijos;

    if (A == NULL)
    {
        printf("\n\tEl %crbol no tiene elementos.", 160);
        return;
    }

///Análisis para el ABO completo:

    printf("\nINFORMACI%cN DEL %cRBOL: \n", 224, 181);
    printf("\nPeso: %i", peso(A));
    printf("\nAltura: %i", altura(A));
    printf("\nMenor: %i", menorABO(A));
    printf("\nMayor: %i", mayorABO(A));
    printf("\nSuma elementos: %i", suma(A));
    printf("\nPreOrden: ");
    preOrden(A);
    printf("\nInOrden: ");
    inOrden(A);
    printf("\nPostOrden: ");
    postOrden(A);

    if (altura(A) < 11)
    {
        printf("\n\nEl %crbol es: ", 160);
        imprimeArbol(A);
    }
    else
        printf("\n\nEl %crbol no se imprimir%c: tiene m%cs de 10 niveles.", 160, 160, 160);

///Análisis para un elemento del ABO:

    valorValido = false;
    while (!valorValido)
    {
        printf("\n\nIngresa un elemento del %crbol: ", 160);
        scanf("%i", &valor);
        if (!estaEnABO(A, valor))
            printf("El elemento %i no est%c en el %crbol.", valor, 160, 160);
        else
            valorValido = true;
    }

    printf("\nINFORMACI%cN DEL ELEMENTO: \n", 224);

    printf("\nNivel: %i", nivelDeUnNodoABO(A, valor));
    if (A->info == valor)
        printf("\nEs la ra%cz (sin padre ni antecesores)", 161);
    else
    {
        padreNodoABO(A, valor);
        printf("\nAntecesores: ", valor);
        antecesoresNodoABO(A, valor);
    }
    tieneHijos = hijosNodoABO(A, valor);
    if (tieneHijos)
    {
        DescendientesNodoABO(A, valor);
    }
}

/*
Entradas: arreglo de 50 caracteres
Salida: ABO
Proceso: procesa el archivo cuyo nombre es recibido como parámetro, y cada entero leído lo inserta en un ABO, que finalmente
         retorna. Si el archivo no existe en la misma carpeta de este programa, envía mensaje correspondiente y cierra la ejecución.
Validación Externa: -
*/
ABO leeArchivo(char nombreArchivo[50])
{
    FILE *archivo;
    ABO A;
    int valor;

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        printf("No se puede abrir el archivo. Revisa su ubicaci%cn.", 163);
        printf("\n\n");
        exit(0);
    }
    A = NULL;
    while (feof(archivo) == false)
    {
        fscanf(archivo, "%i\n", &valor);
        if (!estaEnABO(A, valor))
            A = insertaABO(A, valor);
    }
    fclose(archivo);
    return A;
}

/*
Entradas: -
Salida: entero
Proceso: Función Prinicipal. Solicita al usuario el nombre del archivo, ejecuta la función para leerlo y el ABO que
         recibe de la lectura del archivo, lo entrega a la función que analiza al ABO.
Validación Externa: -
*/
int main()
{
    char nombreArchivo[50];
    ABO A;

    printf("Ingresa el nombre del archivo: ");
    scanf("%s", &nombreArchivo);
    A = leeArchivo(nombreArchivo);
    analizaArbolBinarioOrdenado(A);

    printf("\n\n");
    system("pause");
    printf("\n\n");
    return 0;
}

