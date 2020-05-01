#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "Elem.h"
#include "ABB.h"
int main(){
    ABB niu=Vacioab();
    niu=InsOrdab(3,niu);
    niu=InsOrdab(2,niu);
    niu=InsOrdab(1,niu);
    niu=InsOrdab(5,niu);
    InOr(niu);
}
