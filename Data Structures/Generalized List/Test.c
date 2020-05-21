#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "GenList.h"
int main(){
	GenList lg1, lg2, lg3, lg4;
	lg1=Empty();
	IsEmpty(lg1)?puts("\nYes\n"):puts("\nNo\n");
	
	//bulding the lists:  lg2=[3,4,5], lg3=[8,9], lg4=[7,lg3,10], y lg1=[1,2,lg2,6,[7,lg3,10],11,12] using funtions of ADT Genlist
	lg2=InsElem(3,InsElem(4,InsElem(5,Empty())));
	lg3=InsElem(8,InsElem(9,Empty()));
	lg4=InsElem(7,InsList(lg3,InsElem(10,Empty())));
	lg1=InsElem(1,InsElem(2,InsList(lg2,InsElem(6,InsList(lg4,InsElem(11,InsElem(12,Empty())))))));
	
	IsEmpty(lg1)?puts("\nYes\n"):puts("\nNo\n");
	
	IsList(lg2)?puts("Yes"):puts("No");
	
	printf("\n%d\n",NumElements(lg2));
	printf("\n%d\n",NumElements(lg3));
	printf("\n%d\n",NumElements(lg4));
	printf("\n%d\n",NumElements(lg1));
	
	puts("Elements in lg1 are:");
	PrintGenList(lg1);
	return 0;
}
