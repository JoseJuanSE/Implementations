#include <stdbool.h>
typedef struct Nodo{
   elem val;
   struct Nodo *next;
} *Circular;
Circular NuevaC(){return NULL;}

bool EsNuevaC(Circular a){return a==NULL;}

elem Cabeza(Circular a){return a->next->val;} 

Circular RestoC(Circular l){
	if(l->next==l)	return NuevaC();
	return l->next->next;
}
Circular Rotar(Circular l){
	return l->next;
}
Circular FormarC(Circular c,elem x){
   Circular nuevo=(Circular)malloc(sizeof(struct Nodo));
	nuevo->val=x;
	if(EsNuevaC(c)){
		nuevo->next=nuevo;
	}
	else{
		nuevo->next=c->next;
		c->next=nuevo;
	}	
   return nuevo;
}
//como jugar ruleta
//haremos una ruleta
