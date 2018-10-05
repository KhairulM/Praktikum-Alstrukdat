/*
NIM/Nama  : 13517088/M. Khairul Makrin
Nama file : P00_1317088_01b.c
Topik     : Translasi Notasi Algoritmik ke Bahasa C
Tanggal   : 24 Agustus 2018
Deskripsi : sekuens
*/

int main(){
    //Kamus
    float V, I, R;

    //Algoritma
    printf("Input nilai arus : ");
    scanf("%f", &I);
    printf("Input nilai hambatan : ");
    scanf("%f", &R);

    V=I*R;

    printf("Tegangan listrik = %f volt\n", V);


    return 0;


}

