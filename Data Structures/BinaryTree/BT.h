typedef struct Nodo{
    elem value;
    struct Nodo *i,*d;
}*Arbin;
Arbin Vacioab(){return NULL;}
Arbin Consab(elem x, Arbin a, Arbin b){
    Arbin t=(Arbin)malloc(sizeof(struct Nodo));
    t->value=x;
    t->i=a;
    t->d=b;
    return t;
}
bool EsVacioab(Arbin a){return a==NULL;}
elem Raiz(Arbin a){return a->value;}
Arbin Derecho(Arbin a){return a->d;}
Arbin Izquierdo(Arbin a){return a->i;}
int Peso(Arbin a){
    if(EsVacioab(a))return 0;
    return Peso(Izquierdo(a))+Peso(Derecho(a))+1;
}
void PreOr(Arbin a){
    if(!EsVacioab(a)){
        ImpElem(Raiz(a));
        PreOr(Izquierdo(a));
        PreOr(Derecho(a));        
    }
}
void InOr(Arbin a){
    if(!EsVacioab(a)){
        InOr(Izquierdo(a));
        ImpElem(Raiz(a));
        InOr(Derecho(a));        
    }
}
void PosOr(Arbin a){
    if(!EsVacioab(a)){
        PosOr(Izquierdo(a));
        PosOr(Derecho(a));        
        ImpElem(Raiz(a));
    }
}
int Altura(Arbin a){
    if(EsVacioab(a))return 0;
    return 1+max(Altura(Izquierdo(a)),Altura(Derecho(a)));
}
