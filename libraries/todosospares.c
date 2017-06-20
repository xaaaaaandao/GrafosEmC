#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "opcao.h"
#include "lista.h"

long int minimo(long x, long y){
	if(x < y){
		return x;
	}
	return y;
}

void floyd(){
	int i, j, k, l, m;
	long int matriz[5][5] = { 0, 3, 8, INT_MAX, -4,
						INT_MAX, 0, INT_MAX, 1, 7,
						INT_MAX, 4, 0, INT_MAX, INT_MAX,
						2, INT_MAX, -5, 0, INT_MAX,
						INT_MAX, INT_MAX, INT_MAX, 6, 0};

	long int matrizZero[5][5], matrizZeroR[5][5];

	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			if(i == j || matriz[i][j] == INT_MAX){
				matrizZero[i][j] = -1;
			} else if(i != j && matriz[i][j] < INT_MAX){
				matrizZero[i][j] = i;
			}
		}
	}
/*
	for(l = 0; l < 5; l++){
		for(m = 0; m < 5; m++){
			printf("%ld ", matrizZero[l][m]);
		}
		printf("\n");
	}
*/
	long int matrizR[5][5];

	for(k = 0; k < 5; k++){
		for(i = 0; i < 5; i++){
			for(j = 0; j < 5; j++){
				if(i == j){
					matrizR[i][j] = 0;
				} else {
					matrizR[i][j] = minimo(matriz[i][j], matriz[i][k] + matriz[k][j]);	
				}
				if(matriz[i][j] > matriz[i][k] + matriz[k][j]){
					matrizZeroR[i][j] = matrizZero[k][j];
				} else if(matriz[i][j] <= matriz[i][k] + matriz[k][j]){
					matrizZeroR[i][j] = matrizZero[i][j];
				}
			}
		}
		for(l = 0; l < 5; l++){
			for(m = 0; m < 5; m++){
				matriz[l][m] = matrizR[l][m];
			}
			//printf("\n");
		}
		for(l = 0; l < 5; l++){
			for(m = 0; m < 5; m++){
				matrizZero[l][m] = matrizZeroR[l][m];
			}
			//printf("\n");
		}
		//exit(1);
	}

	for(l = 0; l < 5; l++){
		for(m = 0; m < 5; m++){
			printf("%ld ", matriz[l][m]);
		}
		printf("\n");
	}
	printf("\n");
	for(l = 0; l < 5; l++){
		for(m = 0; m < 5; m++){
			printf("%ld ", matrizZero[l][m]);
		}
		printf("\n");
	}
//	predescessores(matriz);

}