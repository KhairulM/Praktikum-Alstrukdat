#include <stdio.h>
#include "Jam.c"
#include "BOOLEAN_H.h"

int main(){
    Jam J;
    BacaJam(&J);
    printf("%d:%d:%d", GetHour(J), GetMinute(J), GetSecond(J));
    printf("%d\n, JamToDetik(J));

    printf("%d\n", Durasi(J, NextNDetik(J,5)));
    printf("%d\n", Durasi(NextNDetik(J,5), J));
    return 0;
}
