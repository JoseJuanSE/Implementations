#include <stdbool.h>
typedef struct Nodo{
   elem val;
   struct Nodo *next;
} *Lista;
Lista Vacia(){return NULL;}
bool EsVacia(Lista a){return a==NULL;}
elem Cabeza(Lista a){return a->val;} 
Lista Resto(Lista l){return l->next;}
Lista Cons(elem x,Lista resto){
    Lista nuevo=(Lista)malloc(sizeof(struct Nodo));
    nuevo->val=x;
    nuevo->next=resto;
    return nuevo;
}
void ImpListaF(Lista a,FILE *out){
   if(!EsVacia(a)){
       ImpElemF(Cabeza(a),out);       
       ImpListaF(Resto(a),out);
   }
}
void ImpLista(Lista a){
 	ImpListaF(a,stdout);
}
int Size(Lista a){
   if(EsVacia(a))return 0;
   return Size(Resto(a))+1; 
}
Lista PegaListas(Lista l1,Lista l2){
	if(EsVacia(l1))return l2;
	return Cons(Cabeza(l1),PegaListas(Resto(l1),l2));		
}
/* Version iterativa
Lista PegaListas(Lista a,Lista b){
	Lista res=a;
	while(a->next!=Vacia())
		a=Resto(a);	
	a->next=b;
	return res;
}*/
Lista InvLista(Lista l){
	if(l!=Vacia()) return PegaListas(InvLista(Resto(l)),Cons(Cabeza(l),Vacia()));
}
bool EsIgual(elem a,elem b){return a==b;}
bool Esta(elem x,Lista l){
	if(EsVacia(l))
		return false;
	if(EsIgual(Cabeza(l),x))
		return true;
	return Esta(x,Resto(l));
}
bool Comp(Lista a,Lista b){
	if(EsVacia(a) && EsVacia(b))
		return true;	
	if(EsVacia(a) || EsVacia(b) || !EsIgual(Cabeza(a),Cabeza(b)))	
		return false;
	return Comp(Resto(a),Resto(b));
}
bool EsPalindromo(Lista a){
	return Comp(a,InvLista(a));
}

