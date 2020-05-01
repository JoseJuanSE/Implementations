#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Elem.h"
#include "Stack.h"
char n[100];
int Pre(char a) { 
    if(a=='^') return 3; 
    else if(a== '*' || a=='/') return 2; 
    else if(a=='+' || a == '-') return 1; 
    else return -1; 
} 
bool OPE(char a){
	return (a >= 'a' && a <= 'z')||(a >= 'A' && a <= 'Z');
}
/*bool IsGreater(char a,char b){
	return Pre(a)>Pre(b);
}*/
bool IsGreatere(char a,char b){
	return Pre(a)>=Pre(b);
}
void InaPos(char *in){
	int len=strlen(in),i;
	Stack pila=Empty();
	for(i=0;i<len;i++){
		if(OPE(in[i]))
			ImpElem(in[i]);
		else if(in[i]=='('){
			pila=Push('(',pila);
		}
		else if(in[i]==')'){
			while(!IsEmpty(pila) && Top(pila)!='('){
				ImpElem(Top(pila));
				pila=Pop(pila);
			}
			if(Top(pila)=='(')pila=Pop(pila);
		}
		else{
			while(!IsEmpty(pila) && IsGreatere(Top(pila),in[i])){
				//if(Top(pila)=='(' || Top(pila)==')')break;
				ImpElem(Top(pila));
				pila=Pop(pila);
			}
			pila=Push(in[i],pila);
		}
	}
	while(!IsEmpty(pila)){
		ImpElem(Top(pila));
		pila=Pop(pila);
	}
}
int main(int a,char *argv[]){
	//scanf("%s",n);
	InaPos(++argv);
}
//b+(b^2-4*a*c)^(1/2)/2*a

