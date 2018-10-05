/*
NIM/Nama  : 13517088/M. Khairul Makrin
Nama file : P00_1317088_01c.c
Topik     : Translasi Notasi Algoritmik ke Bahasa C
Tanggal   : 24 Agustus 2018
Deskripsi : tipe bentukan
*/



int main(){
    //Membentuk Tipe Jam
    typedef struct{
        int HH;
        int MM;
        int DD;

    }Jam;

    //Kamus
    Jam JamAwal, JamAkhir;
    int Durasi;

    //Algoritma
    scanf("%d %d %d %d %d %d", &JamAwal.HH, &JamAwal.MM, &JamAwal.DD, &JamAkhir.HH, &JamAkhir.MM,&JamAkhir.DD);


    Durasi=((JamAkhir.HH*3600+JamAkhir.MM*60+JamAkhir.DD) - (JamAwal.HH*3600+JamAwal.MM*60+JamAwal.DD));

    printf("%d\n", Durasi);

    return 0;
}
