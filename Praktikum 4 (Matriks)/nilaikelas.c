#include "matriks.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	void TulisNilaiX (MATRIKS M, indeks j, ElType X){
		indeks Brs;
		int Count=0;
		
			printf("[");
			for (Brs=GetFirstIdxBrs(M);Brs<=GetLastIdxBrs(M);Brs++){
				if (Elmt(M,Brs,j)==X && Count==0){
					printf("%d", Brs);
					Count++;
				}else if (Count>0){
					printf(",%d", Brs);
				}
			}
			printf("]");
	
	}
	
	void TulisStatistikMhs(MATRIKS M, indeks i){
		int Max, Min;
		
		MaxMinBrs(M, i, &Max, &Min);
		printf("[%d] %.2f %d %d\n", i, RataBrs(M, i), Max, Min);
	}
	
	void TulisStatistikMK(MATRIKS M, indeks j){
		int Max, Min;
		
		MaxMinKol(M, j, &Max, &Min);
		printf("[%d] %.2f [%d %d ", j, RataKol(M, j), Max, CountXKol(M, j, Max));
		TulisNilaiX(M, j, Max);
		printf("] [%d %d ", Min, CountXKol(M, j, Min));
		TulisNilaiX(M, j, Min);
		printf("]\n");
	}
	
	
	int NB, NK;
	indeks i, j;
	MATRIKS M;
	
	scanf("%d", &NB);
	scanf("%d", &NK);
	
	BacaMATRIKS(&M, NB, NK);
	
	printf("STATISTIK PER MAHASISWA\n");
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
		TulisStatistikMhs(M, i);
	}
	printf("STATISTIK PER MATA KULIAH\n");
	for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
		TulisStatistikMK(M, j);
	}
	
	return 0;
}

