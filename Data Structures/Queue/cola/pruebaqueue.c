#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "Queue.h"
int main(){
	Queue cola=Empty();
	int x=25;
	while(x!=1){
		if(x%2)x=x*3+1;
		else x/=2;
		//x--;
		cola=Push(cola,x);
	}
	while(!IsEmpty(cola)){
		ImpElem(Front(cola));
		cola=Pop(cola);
	}
}
