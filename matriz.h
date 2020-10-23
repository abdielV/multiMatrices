#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int ** val;
    int fils;
    int cols;
} Matriz;

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

void multiConHilos(Matriz * matrizA, Matriz * matrizB, Matriz * matrizR, int filaInicial, int numFilas){
    for(int i = filaInicial; i < filaInicial + numFilas - 1; i++){
        for(int j = 0; j < matrizB -> fils; j++){
            for(int k = 0; k < matrizR ->cols; k++){
                matrizR -> val[i][k] += matrizA -> val[i][j] * matrizB->val[j][k];
                //printf("R[%d][%d](%d) += A[%d][%d](%d) + B[%d][%d](%d)\n", i, k, matrizR -> val[i][k], i, j, matrizA -> val[i][j], j, k, matrizB->val[j][k]);
            }
        }
    }
}

void liberarMatriz(Matriz * matriz){
	for(int i = 0; i < matriz -> fils; i++){
		free(matriz -> val [i]);
	}
	free(matriz -> val);
    free(matriz);
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
    
	
    //Para mantenimiento
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			printf("%i ", auxMatriz[i][j]);
		printf("\n");
	}
	printf("\n");
    
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
    
	
    //Para mantenimiento
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			printf("%i ", auxMatriz[i][j]);
		printf("\n");
	}
	printf("\n");
    
    Matriz * matriz = (Matriz *)malloc(sizeof(matriz));
    matriz -> val = auxMatriz;
    matriz -> fils = m;
    matriz -> cols = n;
    return matriz;
}

void multiSinHilos(Matriz * matrizA, Matriz * matrizB, Matriz * matrizR){
    for(int i = 0; i < matrizA -> fils; i++){
        for(int j = 0; j < matrizB -> fils; j++){
            for(int k = 0; k < matrizR ->cols; k++){
                matrizR -> val[i][k] += matrizA -> val[i][j] * matrizB->val[j][k];
                //printf("R[%d][%d](%d) += A[%d][%d](%d) + B[%d][%d](%d)\n", i, k, matrizR -> val[i][k], i, j, matrizA -> val[i][j], j, k, matrizB->val[j][k]);
            }
        }
    }
}