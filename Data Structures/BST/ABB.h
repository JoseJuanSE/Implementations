typedef struct Nodo{
    elem value;
    struct Nodo *i,*d;
}*ABB;
ABB Vacioab(){return NULL;}
ABB Consab(elem x, ABB a, ABB b){
    ABB t=(ABB)malloc(sizeof(struct Nodo));
    t->value=x;
    t->i=a;
    t->d=b;
    return t;
}
bool EsVacioab(ABB a){return a==NULL;}
elem Raiz(ABB a){return a->value;}
ABB Derecho(ABB a){return a->d;}
ABB Izquierdo(ABB a){return a->i;}
int Peso(ABB a){
    if(EsVacioab(a))return 0;
    return Peso(Izquierdo(a))+Peso(Derecho(a))+1;
}
void PreOr(ABB a){
    if(!EsVacioab(a)){
        ImpElem(Raiz(a));
        PreOr(Izquierdo(a));
        PreOr(Derecho(a));        
    }
}
void InOr(ABB a){
    if(!EsVacioab(a)){
        InOr(Izquierdo(a));
        ImpElem(Raiz(a));
        InOr(Derecho(a));        
    }
}
void PosOr(ABB a){
    if(!EsVacioab(a)){
        PosOr(Izquierdo(a));
        PosOr(Derecho(a));        
        ImpElem(Raiz(a));
    }
}
//BST
ABB InsOrdab(elem x, ABB a){
    if(EsVacioab(a))
        return Consab(x,Vacioab(),Vacioab());
    if(EsMenor(Raiz(a),x))
        return Consab(Raiz(a),InsOrdab(x,Izquierdo(a)),Derecho(a));
    if(EsMayor(Raiz(a),x))
        return Consab(Raiz(a),Izquierdo(a),InsOrdab(x,Derecho(a)));        
}
