#include<stdlib.h>
#include<stdbool.h>
#include "Elem.h"
typedef struct Nodo{
	elem val;
	struct Nodo *next;
}*ApNodo;
typedef struct CNodo{
	ApNodo Prim;	
	ApNodo Ult;
}*Queue;
Queue Empty(){
	Queue colan= (Queue)malloc(sizeof(struct CNodo));
	colan->Prim=colan->Ult=NULL;
	return colan;
}
bool IsEmpty(Queue x){return x->Prim==NULL;}
Queue Push(Queue res,elem x){
	//en vez de inicializar en empty se hace aqui
	/*struct Nodo nuevo= (Nodo*)malloc(sizeof(struct Nodo));
	if(IsEmpty(res)){
		
		nuevo->val=x;
		nuevo->next=NULL;
		colan->Prim=nuevo;
		colan->Ult=nuevo;
		return colan;
	}*/
	ApNodo nuevo= (ApNodo)malloc(sizeof(struct Nodo));
	nuevo->val=x;
	if(IsEmpty(res)){
		res->Prim=res->Ult=nuevo;
	}else{
		nuevo->next=NULL;
		res->Ult->next=nuevo;	
		res->Ult=nuevo;	
	}
	return res;
}
elem Front(Queue x){return x->Prim->val;}
Queue Pop(Queue x){
	ApNodo t=x->Prim;
	if(x->Prim==x->Ult)
		x->Prim=x->Ult=NULL;
	else
		x->Prim=x->Prim->next;
	free(t);
	return x;
}
