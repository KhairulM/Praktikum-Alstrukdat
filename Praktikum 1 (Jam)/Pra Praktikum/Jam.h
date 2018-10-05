#include "BOOLEAN_H.h"

typedef struct {
    int HH;
    int MM;
    int SS;
}Jam;

//*Validasi*//
boolean IsJamValid(int HH, int MM, int SS);

//*Konstruktor*//
Jam MakeJam(int HH, int MM, int SS);

//*Selektor*//
int GetHour(Jam J);

int GetMinute(Jam J);

int GetSecond(Jam J);



//*perubahan nilai*//
void SetHH(Jam* J, int newHH);

void SetMM(Jam* J, int newMM);

void SetSS(Jam* J, int newSS);

//*baca tulis*//
void BacaJam(Jam* J);

void TulisJam(Jam J);

int JamToDetik (Jam J);

Jam DetikToJam(int D);

boolean JEQ (Jam J1, Jam J2);

boolean JNEQ (Jam J1, Jam J2);

boolean JLT(Jam J1, Jam J2);

boolean JGT (Jam J1, Jam J2);

Jam NextDetik(Jam J);

Jam NextNDetik (Jam J, int N);

Jam PrevDetik(Jam J);

Jam PrevNDetik (Jam J, int N);

int Durasi (Jam Jaw, Jam Jakh);
