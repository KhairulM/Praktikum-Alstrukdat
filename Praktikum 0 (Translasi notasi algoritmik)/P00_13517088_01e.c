/*
NIM/Nama  : 13517088/M. Khairul Makrin
Nama file : P00_1317088_01e.c
Topik     : Translasi Notasi Algoritmik ke Bahasa C
Tanggal   : 24 Agustus 2018
Deskripsi : fungsi
*/

//pre-proses
#define boolean unsigned char
#define true 1
#define false 0


int main(){
    //kamus
    char CC;

    //Fungsi-fungsi
    int KarakterToInteger (char x){
        switch (x){
            case '0' :
                return 0;
                break;
            case '1' :
                return 1;
                break;
            case '2' :
                return 2;
                break;
            case '3' :
                return 3;
                break;
            case '4' :
                return 4;
                break;
            case '5' :
                return 5;
                break;
            case '6' :
                return 6;
                break;
            case '7' :
                return 7;
                break;
            case '8' :
                return 8;
                break;
            case '9' :
                return 9;
                break;
            default :
                return 10;
                break;
        }
    }

    boolean IsAnA (char x){
        if (x=='A'){            //X adalah A
            return true;
        }else {                 //X bukan A
            return false;
        }
    }

    //Program utama
    scanf("%c", &CC);
    if (KarakterToInteger (CC) != 10) { //CC adalah sebuah angka
        printf("%d\n", KarakterToInteger (CC));
    } else if (IsAnA (CC) == true){     //CC bukan angka
        printf("Bukan angka, tapi merupakan karakter A\n");
    } else {                            //CC bukan karakter A
        printf("Bukan angka dan bukan karakter A\n");
    }

return 0;
}
