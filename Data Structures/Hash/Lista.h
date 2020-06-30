typedef struct Nodo{
      Elem dato;
      struct Nodo *sig;
} *Lista;


Lista vacia(){return NULL;}
Lista cons(Elem e, Lista l){
     Lista temp =(Lista)malloc(sizeof(struct Nodo));
     temp->dato=e;
     temp->sig=l;
     return temp;
}

int esvacia(Lista l){ return l==NULL;}

Elem cabeza(Lista l){return l->dato;}

Lista resto(Lista l ){return l->sig;}

void ImpLista(Lista l){
     if(!esvacia(l)){
          ImpElem(cabeza(l));
          ImpLista(resto(l));
     }
}
