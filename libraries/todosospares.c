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



	for(l = 0; l < 5; l++){
		for(m = 0; m < 5; m++){
			printf("%ld ", matriz[l][m]);
		}
		printf("\n");
	}

	printf("\n");
	long int matrizR[5][5];

	for(k = 0; k < 5; k++){
		for(i = 0; i < 5; i++){
			for(j = 0; j < 5; j++){
				if(i == j){
					matrizR[i][j] = 0;
				} else {
					printf("i: %d\n", i);
					printf("j: %d\n", j);
					printf("mat: %d\n", matriz[i][j]);
					printf("mat: %d/%d\n", matriz[i][k], matriz[k][j]);					
					matrizR[i][j] = minimo(matriz[i][j], matriz[i][k] + matriz[k][j]);	
				}
			}
		}
		for(l = 0; l < 5; l++){
			for(m = 0; m < 5; m++){
				matriz[l][m] = matrizR[l][m];
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

}