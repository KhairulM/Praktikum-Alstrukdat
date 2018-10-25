#include "listlinier.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	List NilaiMhs;
	address nilaiP, P;
	infotype Min, Nilai;
	float Sum=0;
	
	
	
	CreateEmpty(&NilaiMhs);
	scanf("%d", &Nilai);
	while (Nilai>=1 && Nilai<=100){
		nilaiP=Alokasi(Nilai);
		InsertFirst(&NilaiMhs, nilaiP);
		scanf("%d", &Nilai);
	}
	if (!IsEmpty(NilaiMhs)){
		printf("%d\n", NbElmt(NilaiMhs));
		printf("%d\n", Max(NilaiMhs));
		
		P=First(NilaiMhs);
		Min=Info(P);
		Sum+=Min;
		while (Next(P)!=Nil){
			P=Next(P);
			Sum+=Info(P);

			if (Info(P)<Min){
				Min=Info(P);
			}
		}
		
		printf("%d\n", Min);
		printf("%.2f\n", Sum/NbElmt(NilaiMhs));
		//sorting min-max
		address pass1, i1;
		infotype minNilai, temp1;
		for (pass1=First(NilaiMhs);Next(pass1)!=Nil;pass1=Next(pass1)){
			minNilai=Info(pass1);
			for (i1=Next(pass1);i1!=Nil;i1=Next(i1)){
				if (Info(i1)<=minNilai){
					temp1=Info(i1);
					Info(i1)=minNilai;
					Info(pass1)=temp1;
					minNilai=Info(pass1);
				}
			}
			
		}
		PrintInfo(NilaiMhs);
		printf("\n");
		
		//Sorting max-min
		address pass2, i2;
		infotype temp2;
		for (pass2=First(NilaiMhs);Next(pass2)!=Nil;pass2=Next(pass2)){
			for (i2=Next(pass2);i2!=Nil;i2=Next(i2)){
				if (Info(i2)>=Info(pass2)){
					temp2=Info(i2);
					Info(i2)=Info(pass2);
					Info(pass2)=temp2;
				}
			}
			
		}
		PrintInfo(NilaiMhs);
		printf("\n");
		
	}
	else{
		printf("Daftar nilai kosong\n");
	}
	
	
	return 0;
}

