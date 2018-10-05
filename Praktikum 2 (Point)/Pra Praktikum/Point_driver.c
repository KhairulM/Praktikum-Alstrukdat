#include <stdio.h>
#include "Point.c"
#include "BOOLEAN_H.h"

int main(){
    Point P, P2;

    BacaPoint(&P);
    TulisPoint(P);

    if(EQ(P, NextX(P))){
        printf("\n1\n");
    }else if (NEQ(P, NextY(P))){
        printf("\n0\n");
    }

    Mirror(&P, false);
    TulisPoint(P);

    Putar(&P, (-90));
    TulisPoint(P);

    GeserKeSbX(&P);
    TulisPoint(P);

    GeserKeSbY(&P);
    TulisPoint(P);

    Geser(&P, 1, 2);
    TulisPoint(P);

    /*printf("%.2f\n", Jarak0(P));
    P2=PlusDelta(P, 0, 4);
    printf("%.2f\n", Panjang(P, P2));
    printf("%.2f\n", Jarak0(P2));
    */




    return 0;
}
