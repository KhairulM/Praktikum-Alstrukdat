#include "BOOLEAN_H.h"
#ifndef Absis(P)
#define Absis(P)    P.x
#endif // Absis
#ifndef Ordinat(P)
#define Ordinat(P)  P.y
#endif // Ordinat
#define PI 3.14159265

typedef struct{
    float x;
    float y;

}Point;

//Konstruktor
Point MakePoint (float x, float y);

//Selektor
float GetAbsis (Point P);
float GetOrdinat (Point P);

void SetAbsis (Point *P, float Newx);
void SetOrdinat (Point *P, float Newy);

void BacaPoint (Point *P);
void TulisPoint (Point P);

//Operasi Boolean
boolean EQ (Point P1, Point P2);
boolean NEQ (Point P1, Point P2);
boolean IsOrigin (Point P);
boolean IsOnSbX (Point P);
boolean IsOnSbY (Point P);
int Kuadran (Point P);

//Operasi aritmatik
Point NextX (Point P);
Point NextY (Point P);
Point PlusDelta (Point P, float deltaX, float deltaY);
Point MirrorOf (Point P, boolean SbX);
float Jarak0 (Point P);
float Panjang (Point P1, Point P2);
void Geser (Point *P, float deltaX, float deltaY);
void GeserKeSbX (Point *P);
void GeserKeSbY (Point *P);
void Mirror (Point *P, boolean SbX);
void Putar (Point *P, float Sudut);

