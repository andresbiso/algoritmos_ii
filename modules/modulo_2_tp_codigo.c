// https://www.onlinegdb.com/

/*
10)
Desarrollar un algoritmo y luego codificarlo en C para representar un grafo utilizando listas de adyacencia. Mostrarlo.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NodoVertice {
	int valor;
	struct NodoVertice *proximoVertice;
	struct NodoConexion *proximaConexion;
} NodoVertice;

typedef struct NodoConexion {
    int valor;
    struct NodoConexion *proximo;
} NodoConexion;

void agregarNodoVertice(NodoVertice **nodoVerticeInicial, int valor) {
    NodoVertice *nodoVerticeTemp, *nodoVerticeActual;
    nodoVerticeTemp = malloc(sizeof(NodoVertice));
    nodoVerticeTemp->valor = valor;
    nodoVerticeTemp->proximoVertice = NULL;
	nodoVerticeTemp->proximaConexion = NULL;

    if((*nodoVerticeInicial) == NULL) {
        (*nodoVerticeInicial) = nodoVerticeTemp;
    } else {
        nodoVerticeActual = (*nodoVerticeInicial);
        while(nodoVerticeActual->proximoVertice != NULL){
            nodoVerticeActual = nodoVerticeActual->proximoVertice;
        }
        nodoVerticeActual->proximoVertice = nodoVerticeTemp;
    }
}

void agregarNodoConexion(NodoConexion **nodoConexionInicial, int valor) {
	NodoConexion *nodoConexionTemp, *nodoConexionActual;
    nodoConexionTemp = malloc(sizeof(NodoConexion));
    nodoConexionTemp->valor = valor;
    nodoConexionTemp->proximo = NULL;

    if((*nodoConexionInicial) == NULL) {
        (*nodoConexionInicial) = nodoConexionTemp;
    } else {
        nodoConexionActual = (*nodoConexionInicial);
        while(nodoConexionActual->proximo != NULL){
            nodoConexionActual = nodoConexionActual->proximo;
        }
        nodoConexionActual->proximo = nodoConexionTemp;
    }
}

int existeValorNodoVertice(NodoVertice **nodoVerticeInicial, int valor) {
    NodoVertice *nodoVerticeActual;

    if((*nodoVerticeInicial) == NULL) {
        return 0;
    }
	
	nodoVerticeActual = (*nodoVerticeInicial);
	while(nodoVerticeActual != NULL){
		if(nodoVerticeActual->valor == valor) {
			return 1;
		}
		nodoVerticeActual = nodoVerticeActual->proximoVertice;
	}
	return 0;
}

int existeValorNodoConexion(NodoConexion **nodoConexionInicial, int valor) {
    NodoConexion *nodoConexionActual;

    if(nodoConexionActual == NULL) {
        return 0;
    }
	
	nodoConexionActual = (*nodoConexionInicial);
	while(nodoConexionActual != NULL){
		if(nodoConexionActual->valor == valor) {
			return 1;
		}
		nodoConexionActual = nodoConexionActual->proximo;
	}
	return 0;
}

void mostrar(NodoVertice **nodoVerticeInicial){
    NodoVertice *nodoVerticeActual;
    nodoVerticeActual = (*nodoVerticeInicial);
    while(nodoVerticeActual != NULL) {
        printf("Vértice %d", nodoVerticeActual->valor);
		NodoConexion *nodoConexionActual = nodoVerticeActual->proximaConexion;
        while(nodoConexionActual != NULL) {
            printf(" -> %d", nodoConexionActual->valor);
            nodoConexionActual = nodoConexionActual->proximo;
        }
        nodoVerticeActual = nodoVerticeActual->proximoVertice;
        printf("\n");
    }
}

int main() {
    NodoVertice *nodoVerticeInicial = NULL;
	
	int valorNodo = 0;
	while(valorNodo > -1) {
		printf("Ingrese valor del nodo (o -1 para finalizar):\n");
		scanf("%d", &valorNodo);
		
		if (valorNodo <= -1) {
			break;
		}
		
		if(existeValorNodoVertice(&nodoVerticeInicial, valorNodo) == 0) {
			agregarNodoVertice(&nodoVerticeInicial, valorNodo);
		} else {
			printf("Ya existe un nodo con valor %d:\n", valorNodo);
		}
	}

	NodoVertice *nodoVerticeActual = nodoVerticeInicial;
	while(nodoVerticeActual != NULL) {
		int valorRelacion = 0;
		while(valorRelacion > -1) {
			printf("Ingrese valor del nodo que se relaciona con nodo %d (o -1 para finalizar):\n", nodoVerticeActual->valor);
			scanf("%d", &valorRelacion);	
	
			if (valorRelacion <= -1) {
				break;
			}
		
			if(existeValorNodoVertice(&nodoVerticeInicial, valorRelacion) != 0) {
				if(existeValorNodoConexion(&(nodoVerticeActual->proximaConexion), valorRelacion) == 0) {
					agregarNodoConexion(&(nodoVerticeActual->proximaConexion), valorRelacion);
				} else {
					printf("Ya existe una relacion con el nodo con valor %d:\n", valorRelacion);
				}
			} else {
				printf("El nodo con valor %d no existe \n", valorRelacion);
			}
		}
		
		nodoVerticeActual = nodoVerticeActual->proximoVertice;
	}

    mostrar(&nodoVerticeInicial);
    return 0;
}

/*
11)
Desarrollar un algoritmo y luego codificarlo en C que permita calcular el grado de salida y el grado de entrada de cada vértice utilizando listas de adyacencia.
*/

/*
12)
Desarrollar un algoritmo y luego codificarlo en C que permita añadir, modificar o eliminar un vértice o una arista dada de un grafo utilizando listas de adyacencia.(Realizar el programa con un menú de posibilidades)
*/

/*
13)
Desarrollar un algoritmo y luego codificarlo en C que permita obtener el vértice sobre el cual incidan todos los otros elementos del grafo
*/

/*
14)
Desarrollar un algoritmo y luego codificarlo en C que permita determinar si un vértice es fuente. (Un vértice es fuente si solo salen de él aristas ) 
*/

/*
15)
Desarrollar un algoritmo y luego codificarlo en C que permita determinar si el grafo es completo
*/

/*
16)
Desarrollar un algoritmo y luego codificarlo en C que permita determinar si dos grafos son isomorfos. 
*/
