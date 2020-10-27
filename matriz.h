#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int ** val;
    int fils;
    int cols;
} Matriz;

Matriz * generarMatrizAleatoria( int, int);
Matriz * generarMatrizVacia( int, int);
void imprimirMatriz(Matriz *);
void liberarMatriz(Matriz *);
void liberarMatrices(Matriz **);
void multiplicacion(Matriz **);

Matriz * generarMatrizAleatoria( int m, int n){
    int ** auxMatriz = (int **)malloc(sizeof(int*) * m);
    for(int i = 0; i < m; i++)
        auxMatriz[i] = (int *)malloc(sizeof(int) * n);

    srand(time(NULL));
    for( int i = 0; i < m; i++)
        for( int j = 0; j < n; j++)
            auxMatriz[i][j] = rand() % 6;
    
    Matriz * matriz = (Matriz *)malloc(sizeof(matriz));
    matriz -> val = auxMatriz;
    matriz -> fils = m;
    matriz -> cols = n;
    return matriz;
}

Matriz * generarMatrizVacia( int m, int n){
    int ** auxMatriz = (int **)malloc(sizeof(int*) * m);
    for(int i = 0; i < m; i++)
        auxMatriz[i] = (int *)calloc(n, sizeof(int));

    Matriz * matriz = (Matriz *)malloc(sizeof(matriz));
    matriz -> val = auxMatriz;
    matriz -> fils = m;
    matriz -> cols = n;

	return matriz;
}

void imprimirMatriz(Matriz * matriz){
    for(int i = 0; i < matriz -> fils; i++){
        for (int j = 0; j < matriz -> cols; j++)
            printf("%d ", matriz -> val [i][j]);
        printf("\n");
    }
    printf("\n");
    fflush(stdout);
}

void liberarMatriz(Matriz * matriz){
	for(int i = 0; i < matriz -> fils; i++)
		free(matriz -> val [i]);
	free(matriz -> val);
    free(matriz);
}

void liberarMatrices(Matriz **matrices){
    liberarMatriz(matrices[0]);
    liberarMatriz(matrices[1]);
    liberarMatriz(matrices[2]);
}

void multiplicacion(Matriz ** matrices){
    for(int i = 0; i < matrices[0] -> fils; i++)
        for(int j = 0; j < matrices[1] -> fils; j++)
            for(int k = 0; k < matrices[2] ->cols; k++)
                matrices[2] -> val[i][k] += matrices[0] -> val[i][j] * matrices[1]->val[j][k];
}