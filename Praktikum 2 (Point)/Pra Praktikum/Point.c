#include "BOOLEAN_H.h"
#include <stdio.h>
#include "Point.h"
#include <math.h>

//Konstruktor
Point MakePoint (float x, float y){
    Point P;

    Absis(P)=x;
    Ordinat(P)=y;

    return P;

}

//Selektor
float GetAbsis (Point P){
    return (Absis(P));
}
float GetOrdinat (Point P){
    return (Ordinat(P));
}

void SetAbsis (Point *P, float Newx){
    (*P).x=Newx;
}
void SetOrdinat (Point *P, float Newy){
    (*P).y=Newy;
}

void BacaPoint (Point *P){
    float x, y;

    scanf("%f,%f", &x, &y);

    (*P)=MakePoint(x, y);

}
void TulisPoint (Point P){
    printf("(%.2f,%.2f)\n", Absis(P), Ordinat(P));
}

//Operasi Boolean
boolean EQ (Point P1, Point P2){
    return ((P1.x==P2.x) && (P1.y==P2.y));
}
boolean NEQ (Point P1, Point P2){
    return ((P1.x!=P2.x)||(P1.y!=P2.y));
}
boolean IsOrigin (Point P){
    return (Absis(P)==0 && Ordinat(P)==0);
}
boolean IsOnSbX (Point P){
    return (Ordinat(P)==0);
}
boolean IsOnSbY (Point P){
    return (Absis(P)==0);
}
int Kuadran (Point P){
    int K;

    if (P.x>0 && P.y>0){
        K=1;
    }else if (P.x<0 && P.y>0){
        K=2;
    }else if (P.x<0 && P.y<0){
        K=3;
    }else{  //P.x>0 P.y<0
        K=4;
    }

    return K;
}

//Operasi aritmatik
Point NextX (Point P){
    SetAbsis(&P, P.x+1);

    return P;
}
Point NextY (Point P){
    SetOrdinat(&P, P.y+1);

    return P;
}
Point PlusDelta (Point P, float deltaX, float deltaY){
    SetAbsis(&P, P.x+deltaX);
    SetOrdinat(&P, P.y+deltaY);

    return P;

}
Point MirrorOf (Point P, boolean SbX){
    if (SbX) {
        SetOrdinat(&P, (-P.y));
        if (Ordinat(P)==-0){
            Ordinat(P)=Ordinat(P)*(-1);
        }
    }else { //sumbu y
        SetAbsis(&P, (-P.x));
        if (Absis(P)==-0){
            Absis(P)=Absis(P)*(-1);
        }
    }

    return P;
}
float Jarak0 (Point P){
    return(sqrt((P.x*P.x)+(P.y*P.y)));
}
float Panjang (Point P1, Point P2){
    float PanjangX=P2.x-P1.x;
    float PanjangY=P2.y-P1.y;
    float Sum=sqrt((PanjangX*PanjangX)+(PanjangY*PanjangY));

    return (Sum);
}
void Geser (Point *P, float deltaX, float deltaY){
    (*P)=PlusDelta(*P, deltaX, deltaY);
}
void GeserKeSbX (Point *P){
    SetAbsis(P, 0);
}
void GeserKeSbY (Point *P){
    SetOrdinat(P, 0);
}
void Mirror (Point *P, boolean SbX){
    (*P)=MirrorOf(*P, SbX);
}
void Putar (Point *P, float Sudut){
    float newX, newY;
    Sudut=Sudut*PI/180;

    newX=(*P).x*cos(Sudut)-(*P).y*sin(Sudut);
    newY=(*P).y*cos(Sudut)+(*P).x*sin(Sudut);

    (*P).x=newX;
    (*P).y=newY;

}

