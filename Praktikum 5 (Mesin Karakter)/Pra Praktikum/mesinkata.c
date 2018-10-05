#include "mesinkata.h"
#include "mesinkar.h"
#include <stdio.h>

Kata CKata;
boolean EndKata;

void IgnoreBlank(){
	while ((CC==BLANK) && (CC!=MARK)){
		ADV();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(){

	START();
	IgnoreBlank();
	if (CC!=MARK){
		EndKata=false;
		CKata.Length=0;
		SalinKata();
	}else{
		EndKata=true;
	}

}
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){

	CKata.Length=0;
	SalinKata();
	IgnoreBlank();
	EndKata=(CC==MARK);
	
		
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(){
	int i=1;
	CKata.Length=0;
	while (CC!=MARK && CC!=BLANK){
		if (i<=NMax){
			CKata.TabKata[i]=CC;
			CKata.Length++;
			i++;
		}
		
		ADV();
	}
	
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
