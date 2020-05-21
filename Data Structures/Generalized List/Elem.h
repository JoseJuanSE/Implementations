typedef int Elem;
void PrintElemF(Elem x,FILE *out){
	fprintf(out,"%d\n",x);
}
void PrintElem(Elem e){
   PrintElemF(e,stdout);
}
void ImpElemaux(Elem e){
	printf("%d ",e);
}
