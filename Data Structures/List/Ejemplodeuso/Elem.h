#include <stdbool.h>
typedef char *Elem;
ImpElemF(Elem x,FILE *out){
	fprintf(out,"%d ",x);
}
void ImpElem(Elem e){
   ImpElemF(e,stdout);
}
bool Is_Equal(Elem a,Elem b){return a==b;}
bool Less_Than(Elem e1,Elem e2){
	return strcmp(e1,e2)<0; use if elem is string
	//return e1<e2;
}
