typedef struct Elemento{
    char nom[30];
    char sim[5];
    int Atn;
}Elem;

void ImpElem(Elem e){printf("Nombre: %s\nSimbolo: %s\nNumero atomico: %d\n",e.nom,e.sim,e.Atn);}

int Hash(Elem e){
    int s=0,i;
    for(i=0;i<strlen(e.nom);i++){
        s+=(int)e.nom[i];
    }
    return s%53;
}
