#include<stdio.h>
#include "Queue.h"
int main(){
	Queue cola=Empty();
	int x=25;
	//Collatz
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
	sysmte("pause");
	return 0;
}
