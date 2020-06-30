typedef Lista *TablaH;


TablaH consH(int n){
    TablaH t=(TablaH)malloc(sizeof(Lista)*n);
    return t;
}
//Si hay colision, varios elementos tendran la misma llave
//Por lo que tambien necesitamos de la palabra en las funciones no solo la llave
//por esta razon, enviare el elemento y obtendre la llave dentro de las fuciones

TablaH insertaH(Elem e, TablaH t){
    int llave=Hash(e);
    t[llave]=cons(e,t[llave]);
    return t;
}

int estaenH(Elem e, TablaH t){
    int llave=Hash(e);
    Lista r=t[llave];
    while(!esvacia(r)){
        if(strcmp(r->dato.nom,e.nom) == 0)return 1;
        r=r->sig;
    }
    return 0;
}

Elem consulta(Elem e, TablaH t){
    int llave=Hash(e);
    Lista r=t[llave];
    while(!esvacia(r)){
        if(strcmp(r->dato.nom,e.nom) == 0)return r->dato;
        r=r->sig;
    }
}

TablaH elimina(Elem e, TablaH t){
    int llave=Hash(e);
    while(!esvacia(t[llave]))
        if(strcmp(t[llave]->dato.nom,e.nom) == 0){
            t[llave]=t[llave]->sig;
            return t;
        }
}
