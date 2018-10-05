#include "BOOLEAN_H.h"
#include "Jam.h"

//*Validasi*//
boolean IsJamValid(int HH, int MM, int SS){
    if (HH<=24 && MM<=60 && SS<60){
        return true;
    }else{
        return false;
    }
}

//*Konstruktor*//
Jam MakeJam(int HH, int MM, int SS){
    Jam J;

   SetHH(&J, HH);
   SetMM(&J, MM);
   SetSS(&J, SS);

   return J;
}

//*Selektor*//
int GetHour(Jam J){
    return (J.HH);
}

int GetMinute(Jam J){
    return (J.MM);
}

int GetSecond(Jam J){
    return (J.SS);
}

//*perubahan nilai*//
void SetHH(Jam* J, int newHH){
    (*J).HH=newHH;
}

void SetMM(Jam* J, int newMM){
    (*J).MM=newMM;
}

void SetSS(Jam* J, int newSS){
    (*J).SS=newSS;
}

//*baca tulis*//
void BacaJam(Jam* J){
    int HH, MM, SS;
    boolean valid=false;

    while (!valid){
        scanf("%d %d %d", &HH, &MM, &SS);

        if (IsJamValid(HH, MM, SS)){
            *J=MakeJam(HH, MM, SS);
            valid=true;
        }
    }
}

void TulisJam(Jam J){
    printf("%d:%d:%d\n", J.HH, J.MM, J.SS);
}

int JamToDetik (Jam J){
    return((J.HH*3600)+(J.MM*60)+(J.SS));
}

Jam DetikToJam(int D){
    Jam J;
    if (D>86400){
        D=D%86400;
    }
    J = MakeJam((D/3600), ((D%3600)/60), ((D%3600)%60)) ;
    return J;
}

boolean JEQ (Jam J1, Jam J2){
    return(JamToDetik(J1)==JamToDetik(J2));
}

boolean JNEQ (Jam J1, Jam J2) {
    return(!(JamToDetik(J1)==JamToDetik(J2)));
}

boolean JLT(Jam J1, Jam J2){
    return(JamToDetik(J1)<JamToDetik(J2));
}

boolean JGT (Jam J1, Jam J2){
    return(JamToDetik(J1)>JamToDetik(J2));
}

Jam NextDetik(Jam J){
    J.SS++;
    if (J.SS==60) {
     J.SS=0;
     J.MM+=1;
     if (J.MM==60){
        J.MM=0;
        J.HH+=1;
        if (J.HH==24){
            J.HH=0;
        }
     }
    }
    return J;
}

Jam NextNDetik (Jam J, int N){
    for(int i=1;i<=N;i++){
        J=NextDetik(J);
    }

    return J;
}

Jam PrevDetik(Jam J){
    J.SS--;
    if (J.SS==(-1)){
        J.SS=59;
        J.MM--;
        if (J.MM==(-1)){
            J.MM=59;
            J.HH--;
            if (J.HH==(-1)) {
                J.HH=23;
            }
        }
    }

    return J;
}

Jam PrevNDetik (Jam J, int N){
     for(int i=1;i<=N;i++){
        J=PrevDetik(J);
    }

    return J;
}

int Durasi (Jam Jaw, Jam Jakh){
    if (JamToDetik(Jaw) > JamToDetik(Jakh)) { //BedaHari
        return (24*3600-(JamToDetik(Jaw)-JamToDetik(Jakh)));
    } else {
        return (JamToDetik(Jakh)-JamToDetik(Jaw));
    }
}
