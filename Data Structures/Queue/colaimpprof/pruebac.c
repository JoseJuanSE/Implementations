#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "Elem.h"
#include "Lista.h"
#include "Cola.h"
int main(){
	Cola C=Nueva();
	int i=1;
	for(i;i<=10;i++){
		C=Formar(C,i);
	}
	while(!EsNueva(C)){
		ImpElem(Primero(C));
		C=Desformar(C);
	}
	return 0;
}
