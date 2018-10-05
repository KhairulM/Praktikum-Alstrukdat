/*
NIM/Nama  : 13517088/M. Khairul Makrin
Nama file : P00_1317088_01f.c
Topik     : Translasi Notasi Algoritmik ke Bahasa C
Tanggal   : 25 Agustus 2018
Deskripsi : procedure
*/
#include <stdio.h>

int main(){
    //Kamus
    int a, b, c;

    //Procedure
    void PROCTUKAR (int *px, int *py){
       int temp;

       temp=*px;
       *px=*py;
       *py=temp;
    }

    //Algoritma
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    PROCTUKAR (&a, &c);
    PROCTUKAR (&b, &c);

    printf("%d \n", a);
    printf("%d \n", b);
    printf("%d", c);

return 0;
}
