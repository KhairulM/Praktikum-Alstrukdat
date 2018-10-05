/*
NIM/Nama  : 13517088/M. Khairul Makrin
Nama file : jumlahderet.c
Topik     : Praktikum 1
Tanggal   : 30 Agustus 2018
Deskripsi : menghitung jumlah deret 1+2+3+...+n
*/

#include <stdio.h>

int main(){
	//kamus
	int n;
	int i;
	int sum=0;

	//algoritma
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		sum+=i;	
	}
	
	printf("%d\n", sum);


	return 0;
}
