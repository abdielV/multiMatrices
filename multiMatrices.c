#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "matriz.h"


void instructivo(){
	printf("----------------------------------------------\n");
	printf("Esta aplicación multiplica matrices a traves del uso de hilos.\n");
	printf("\tLos argumentos usados son los siguientes:\n");
	printf("1er -> número de filas de la matriz A.\n");
	printf("2do -> número de columnas de la matriz A.\n");
	printf("3er -> número de filas de la matriz B.\n");
	printf("4to -> número de columnas de la matriz B.\n");
	printf("5to -> número de hilos a usar en la ejecución del programa.\n");
	printf("\tEl número de filas de la matriz A(arg 1) debe ser mayor o igual al numero de hilos(arg 5)\n");
	printf("\tPor razones matematicas, el numero de columnas de la matriz A(arg 2) y el numero de filas de la matriz B(arg 3) debe ser igual\n\n");
	printf("----------------------------------------------\n");
}

void validarArgumentos(int argc, char *argv[]){
	if(argc!=6){
		printf("**Error. Número de argumentos erroneo.\n**");
		instructivo();
		exit(1);
	}
	int aux = 0;
	for(int i = 1; i < 6; i++){
		for(int j = 0; j < strlen(argv[i]); j++){
			fflush(stdout);
			if(!isdigit(argv[i][j]))
				aux = i;
		}
		if (aux){
			printf("**Error. Valor de argunto incorrecto en posicion (%d).**\n\n", i);
			instructivo();
			exit(1);
		}
	}
	if(atoi(argv[2]) != atoi(argv[3])){
		printf("**Error. El numero de columnas de A(arg 2) y el numero de filas de la matriz B(arg 3) son distintos**\n\n");
		instructivo();
		exit(1);
	}
	if(atoi(argv[5]) > atoi(argv[1])){
		printf("**Error. Cantidad de hilos es superior a las filas de A(arg 1)**\n\n");
		instructivo();
		exit(1);
	}
}


void * hiloSaluda(void * auxFilaInicial)
{
	int filaInicial = (int) auxFilaInicial;
	imprimirMatriz(matrizA);
	/* int numFilas = filasPorHilo;
	if(filaInicial == matrizA -> fils * numHilos)
		numFilas =	matrizA -> fils % numHilos;
	multiConHilos(matrizA, matrizB, matrizR, filaInicial, numFilas); */
	pthread_exit(NULL);
}

int main(int argc, char * argv[])
{
	validarArgumentos(argc, argv);
	Matriz ** matrices = (Matriz **) malloc(sizeof(Matriz *) * 3);
    matrices[0] = generarMatrizAleatoria(atoi(argv[1]), atoi(argv[2]));
	matrices[1] = generarMatrizAleatoria(atoi(argv[3]), atoi(argv[4]));
	matrices[2] = generarMatrizVacia(atoi(argv[1]), atoi(argv[4]));
	// int numHilos = atoi(argv[5]);
	// pthread_t * arrHilos = (pthread_t *)malloc(sizeof(pthread_t) * numHilos);
	// int * idHilos;
	// for(int i = 0; i < numHilos; i++)
	// 	idHilos[i] = i;
	
	// int filasPorHilo = matrices[0] -> fils / numHilos;
	// for(int i = 0; i < numHilos; i++){
	// 	pthread_create(&arrHilos[i], NULL, hiloSaluda, (void *) /*Parametro*/);
	// }

	// for(int i = 0; i < numHilos; i++){
	// 	pthread_join(arrHilos[i], NULL);
	// }
	imprimirMatriz(matrices[0]);
	imprimirMatriz(matrices[1]);
	imprimirMatriz(matrices[2]);

	// free(arrHilos);
	liberarMatriz(matrices[0]);
	liberarMatriz(matrices[1]);
	liberarMatriz(matrices[2]);
	return 0;
}
