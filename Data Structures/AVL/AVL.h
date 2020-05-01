typedef struct Nodo{
    elem value;
    struct Nodo *i,*d;
}*AVL;
AVL Vacioab(){return NULL;}
AVL Consab(elem x, AVL a, AVL b){
    AVL t=(AVL)malloc(sizeof(struct Nodo));
    t->value=x;
    t->i=a;
    t->d=b;
    return t;
}
bool EsVacioab(AVL a){return a==NULL;}
elem Raiz(AVL a){return a->value;}
AVL Derecho(AVL a){return a->d;}
AVL Izquierdo(AVL a){return a->i;}
int Peso(AVL a){
    if(EsVacioab(a))return 0;
    return Peso(Izquierdo(a))+Peso(Derecho(a))+1;
}
void PreOr(AVL a){
    if(!EsVacioab(a)){
        ImpElem(Raiz(a));
        PreOr(Izquierdo(a));
        PreOr(Derecho(a));        
    }
}
void InOr(AVL a){
    if(!EsVacioab(a)){
        InOr(Izquierdo(a));
        ImpElem(Raiz(a));
        InOr(Derecho(a));        
    }
}
void PosOr(AVL a){
    if(!EsVacioab(a)){
        PosOr(Izquierdo(a));
        PosOr(Derecho(a));        
        ImpElem(Raiz(a));
    }
}
AVL InsOrdab(elem x, AVL a){
    if(EsVacioab(a))
        return Consab(x,Vacioab(),Vacioab());
    if(EsMenor(Raiz(a),x))
        return Consab(Raiz(a),InsOrdab(x,Izquierdo(a)),Derecho(a));
    if(EsMayor(Raiz(a),x))
        return Consab(Raiz(a),Izquierdo(a),InsOrdab(x,Derecho(a)));        
}
int Altura(AVL a){
    if(EsVacioab(a))return 0;
    return 1+max(Altura(Izquierdo(a)),Altura(Derecho(a)));
}
int FactBal(AVL a){return Altura(Izquierdo(a))-Altura(Derecho(a));}
bool EsAVL(AVL a){return abs(FactBal(a))<=1 && EsAVL(Izquierdo(a)) && EsAVL(Derecho(a));}
AVL RotarDer( AVL a ){
    return Consab(Raiz(Izquierdo(a)),Izquierdo(Izquierdo(a)),Consab(Raiz(a),Derecho(Izquierdo(a))Derecho(a)));
}
//bst balanciado por alt
