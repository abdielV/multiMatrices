#include<stdlib.h>
#include"matriz.h"
#include<pthread.h>

void * hiloSaluda(void *);
void multiConHilos(int idHilo);

Matriz ** matrices;
int filasPorHilo;
int numHilos;

void * hiloSaluda(void * auxIdHilo)
{
	int idHilo = * (int *)auxIdHilo;

    multiConHilos(idHilo);

	pthread_exit(NULL);
}

void multiConHilos(int idHilo){
    int filaInicial = idHilo * filasPorHilo;
    int filaFinal = filaInicial + filasPorHilo - 1;
    if(idHilo + 1 == numHilos){
        filaFinal = matrices[0] -> fils - 1;
    }

    for(int i = filaInicial; i <= filaFinal; i++)
        for(int j = 0; j < matrices[1] -> fils; j++)
            for(int k = 0; k < matrices[2] ->cols; k++)
                matrices[2] -> val[i][k] += matrices[0] -> val[i][j] * matrices[1]->val[j][k];

    return ;
}