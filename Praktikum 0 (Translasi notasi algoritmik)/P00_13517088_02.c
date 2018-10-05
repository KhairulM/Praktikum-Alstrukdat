/*
NIM/Nama  : 13517088/M. Khairul Makrin
Nama file : P00_1317088_02.c
Topik     : Translasi Notasi Algoritmik ke Bahasa C
Tanggal   : 25 Agustus 2018
Deskripsi : cek batas nilai tipe dasar
*/

#include <limits.h>
#include <float.h>

int main () {
/* KAMUS */
/* ALGORITMA */
/* Pengecekan Integer */
printf("Maximum integer: %d\n", INT_MAX);                   //2147483647
printf("Minimum integer: %d\n", INT_MIN);                   //-2147483648
printf("Maximum short integer: %d\n", SHRT_MAX);            //32767
printf("Minimum short integer: %d\n", SHRT_MIN);            //-31768
printf("Maximum long integer: %d\n", LONG_MAX);             //2147483647
printf("Minimum long integer: %d\n", LONG_MIN);             //-2147483648
printf("Maximum unsigned integer: %d\n", UINT_MAX);         //-1
printf("Maximum unsigned short integer: %d\n", USHRT_MAX);  //65535
printf("Maximum long integer: %d\n", ULONG_MAX);            //-1
printf("Maximum character: %d\n", CHAR_MAX);                //127
printf("Minimum character: %d\n", CHAR_MIN);                //-128
printf("Maximum signed character: %d\n", SCHAR_MAX);        //127
printf("Minimum signed character: %d\n", SCHAR_MIN);        //-128
printf("Maximum unsigned character: %d\n", UCHAR_MAX);      //255
printf("Maximum float: %d\n", FLT_MAX);                     //-536870912
printf("Minimum float: %d\n", FLT_MIN);                     //0
printf("Maximum double float: %d\n", DBL_MAX);              //-1
printf("Minimum double float: %d\n", DBL_MIN);              //0
printf("Maximum long double float: %d\n", LDBL_MAX);        //-1
printf("Minimum long double float: %d\n", LDBL_MIN);        //0
return 0;
}
