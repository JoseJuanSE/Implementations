#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "Elem.h"
#include "BT.h"
int main(){
    Arbin ar=Vacioab(); ar=Consab(1,Consab(3,Consab(4,Vacioab(),Vacioab()),Consab(5,Vacioab(),Vacioab())),Consab(2,Vacioab(),Vacioab()));
    printf("%d\n",Peso(ar));
    InOr(ar);
}
