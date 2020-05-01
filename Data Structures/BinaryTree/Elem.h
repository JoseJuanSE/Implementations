typedef int elem;

void ImpElemF(elem x,FILE *out){
	fprintf(out,"%d\n",x);
}
void ImpElem(elem e){
   ImpElemF(e,stdout);
}

