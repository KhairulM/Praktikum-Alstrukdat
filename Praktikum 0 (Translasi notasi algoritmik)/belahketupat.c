/*
NIM/Nama  : 13517088/M. Khairul Makrin
Nama file : belahketupat.c
Topik     : Praktikum 1
Tanggal   : 30 Agustus 2018
Deskripsi : 
*/

#include <stdio.h>
#define boolean unsign char
#define true 1
#define false 0

int main(){
	//fungsi dan prosedur
	boolean IsValid (int n){
		return (n%2!=0);	
	}
	
	char GambarBelahKetupat (int n){
		//kamus
		int i, j, baris;
		int spasi;
		
		//algoritma
		for (baris=1;baris<=n;baris++){
			spasi=(n-baris)/2;
			
		}
		
	}
	
	//kamus
	int n;

	//algoritma
	scanf("%d", &n);
	if(IsValid(n)){
		GambarBelahKetupat(n)
	}else {
		printf("Masukan tidak valid\n");
	}

	return 0;
}
