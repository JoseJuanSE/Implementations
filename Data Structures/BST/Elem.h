typedef int elem;

void ImpElemF(elem x,FILE *out){
	fprintf(out,"%d\n",x);
}
void ImpElem(elem e){
   ImpElemF(e,stdout);
}
bool EsMenor(elem e1,elem e2){return e1>e2;}
bool EsMayor(elem e1,elem e2){return e1<e2;}
