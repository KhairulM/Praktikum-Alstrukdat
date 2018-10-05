/*
NAMA	 :	M. Khairul Makirin
NIM		 :	13517088
TOPIK	 :	ADT QUEUE
DESKRIPSI:	Internet lambat beuttt
*/

#include "queue.h"
#include "stdio.h"

int main(){
	/*KAMUS*/
	int Max;
	int Kode;
	address i;
	infotype Menit;
	infotype DelElmt;
	float Sum=0;
	int NBQ=0;
	Queue Q;
	
	/*ALGORITMA*/
	scanf("%d", &Max);
	CreateEmpty(&Q, Max);
	scanf("%d", &Kode);
	while (Kode!=0){
		
		switch (Kode){
			case 1	:
				if (!IsFull(Q)){
					scanf("%d", &Menit);
					Add(&Q, Menit);
					Sum+=Menit;
					NBQ++;
				}else {
					printf("Antrian penuh\n");
				}
				break;
			case 2	:
				if (!IsEmpty(Q)){
					Del(&Q, &DelElmt);
					Sum-=DelElmt;
					NBQ--;
				}else {
					printf("Antrian kosong\n");
				}
				break;
			
			
		}
		scanf("%d", &Kode);
		
	}
	printf("%d\n", NBQ);
	
	
	//Mencari rata-rata waktu mengantri
	if (NBQ!=0){
	
		printf("%.2f\n", Sum/NBQ);
		
	}else{
		printf("Tidak bisa dihitung\n");
	}
	
	
	DeAlokasi(&Q);
	
	
return 0;	
}
