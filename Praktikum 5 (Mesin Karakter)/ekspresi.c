/* 	NIM/Nama : 13517040/Ariel Ansa Razumardi
	Nama file : ekspresi.c
	Topik : Praktikum 05
	Tanggal : 27 September 2018
	Deskripsi :  Menghasilkan Output isi pita karakter (menuliskan 'Ekspresi Kosong jika pita kosong"*/

/*Program Ekspresi
  Menghasilkan Output isi pita karakter (menuliskan 'Ekspresi Kosong jika pita kosong" */

#include "mesintoken.h"
#include <stdio.h>


int main(){
	// Kamus

	// Algoritma
	STARTTOKEN();
	if (EndToken){
		printf("Ekspresi kosong\n");
	}
	else{
		while(!EndToken){
			if (CToken.tkn == 'b'){
				printf("%d\n", CToken.val);
			}
			else{
				printf("%c\n", CToken.tkn);
			}
			ADVTOKEN();
		}	
	}
	return 0;
}

