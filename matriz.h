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
Matriz * generarMatrizPruebaA();
Matriz * generarMatrizPruebaB();

Matriz * generarMatrizAleatoria( int m, int n){
    int ** auxMatriz = (int **)malloc(sizeof(int*) * m);
    for(int i = 0; i < m; i++)
        auxMatriz[i] = (int *)malloc(sizeof(int) * n);

    srand(time(NULL));
    for( int i = 0; i < m; i++)
        for( int j = 0; j < n; j++)
            auxMatriz[i][j] = rand() % 2;
    
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

Matriz * generarMatrizPruebaA()
{
    int m = 3, n = 4;
    int ** auxMatriz = (int **)malloc(sizeof(int*) * m);
    for(int i = 0; i < m; i++)
        auxMatriz[i] = (int *)malloc(sizeof(int) * n);

    auxMatriz[0][0] = 1;
    auxMatriz[0][1] = 0;
    auxMatriz[0][2] = 1;
    auxMatriz[0][3] = 1;
    auxMatriz[1][0] = 0;
    auxMatriz[1][1] = 1;
    auxMatriz[1][2] = 0;
    auxMatriz[1][3] = 0;
    auxMatriz[2][0] = 0;
    auxMatriz[2][1] = 1;
    auxMatriz[2][2] = 0;
    auxMatriz[2][3] = 1;
    
    Matriz * matriz = (Matriz *)malloc(sizeof(matriz));
    matriz -> val = auxMatriz;
    matriz -> fils = m;
    matriz -> cols = n;
    return matriz;
}

Matriz * generarMatrizPruebaB()
{
    int m = 4, n = 2;
    int ** auxMatriz = (int **)malloc(sizeof(int*) * m);
    for(int i = 0; i < m; i++)
        auxMatriz[i] = (int *)malloc(sizeof(int) * n);

    auxMatriz[0][0] = 1;
    auxMatriz[1][0] = 0;
    auxMatriz[2][0] = 0;
    auxMatriz[3][0] = 1;
    auxMatriz[0][1] = 0;
    auxMatriz[1][1] = 1;
    auxMatriz[2][1] = 1;
    auxMatriz[3][1] = 1;
    
    Matriz * matriz = (Matriz *)malloc(sizeof(matriz));
    matriz -> val = auxMatriz;
    matriz -> fils = m;
    matriz -> cols = n;
    return matriz;
}