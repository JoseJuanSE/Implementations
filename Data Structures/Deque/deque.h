typedef struct Nodo{
    int val;
    struct Nodo *izq,*der;
} *ApNodo;
typedef struct CNodo{
  ApNodo Prim,Ult;
} *BiCola;
BiCola Nueva(){
	BiCola n=(BiCola)malloc(sizeof(struct CNodo));
	n->Prim=n->Ult=NULL;
	return n;
}
bool EsNueva(BiCola x){return x->Prim==NULL;}
BiCola FormarBi(elem x,BiCola res){
	ApNodo nuevo= (ApNodo)malloc(sizeof(struct Nodo));
	nuevo->val=x;
	nuevo->izq=nuevo->der=NULL;
	if(EsNueva(res)){
		res->Prim=res->Ult=nuevo;
	}else{
		nuevo->der=res->Prim;
		res->Prim->izq=nuevo;
		res->Prim=nuevo;
	}
	return res;
}
BiCola FormarBd(BiCola res,elem x){
	ApNodo nuevo= (ApNodo)malloc(sizeof(struct Nodo));
	nuevo->val=x;
	nuevo->izq=nuevo->der=NULL;
	if(EsNueva(res)){
		res->Prim=res->Ult=nuevo;
	}else{
		nuevo->izq=res->Ult;
		res->Ult->der=nuevo;
		res->Ult=nuevo;
	}
	return res;
}
BiCola DesformarBi(BiCola x){
	ApNodo t=x->Prim;
	if(x->Prim==x->Ult)
		x->Prim=x->Ult=NULL;
	else
		x->Prim=x->Prim->der;
	free(t);
	return x;
}
BiCola DesformarBd(BiCola x){
	ApNodo t=x->Ult;
	if(x->Prim==x->Ult)
		x->Prim=x->Ult=NULL;
	else
		x->Ult=x->Prim->izq;
	free(t);
	return x;
}
elem IzquierdoB(BiCola x){return x->Prim->val;}
elem DerechaB(BiCola x){return x->Ult->val;}
/*
BiCola Copia(BiCola q){
	BiCola aux=Nueva();
	while(!EsNueva(q)){
		aux=FormarBd(aux,IzquierdoB(q));
		q=DesformarBi(q);
	}
	return aux;
}
void Impi(BiCola q){
	if(EsNueva(q))return ;
	ImpElem(IzquierdoB(q));
	Impi(DesformarBi(q));
}
*/
BiCola ImpBi(BiCola q){
	/*
	BiCola aux=Copia(q)
	Impi(aux);
	*/
	BiCola aux=Nueva();
	while(!EsNueva(q)){
		ImpElem(IzquierdoB(q));
		aux=FormarBd(aux,IzquierdoB(q));
		q=DesformarBi(q);
	}
	return aux;
}
BiCola ImpBd(BiCola q){
	BiCola aux=Nueva();
	while(!EsNueva(q)){
		ImpElem(DerechoB(q));
		aux=FormarBd(aux,DerechoB(q));
		q=DesformarBd(q);
	}
	return aux;
}
/*
Espec BiCola
NuevaB:->BiCola;
FormarBi: Elem, BiCola->BiCola;
FormarBd: BiCola,Elem->BiCola;
EsNuevaB: BiCola -> bool;
IzquierdoB: BiCola->Elem;
DerechoB: BiCola->Elem;
DesformarBi: BiCola->BiCola;
DesformarBd: BiCola->BiCola;

Axiomas: Elem e1,e2; BiCola q1;
[b1] EsNuevaB(NuevaB())=Cierto;
[b2] EsNuevaB(FormarBi(e1,q1))=Falso;
[b3] EsNuevaB(FormarBd(q1,e1))=Falso;
[b4] IzquierdoB(NuevaB())=Error;
[b5] IzquierdoB(FormarBi(e1,q1))=e1;
[b6] IzquierdoB(FormarBd(q1,e1))=Si q1 es nueva = e1 si no IzquierdoB(q1);
[b7] DerechoB(NuevaB())=Error;
[b8] DerechoB(FormarBi(e1,q1))=Si q1 es nueva = e1 si no DerechoB(q1);
[b9] DerechoB(FormarBd(q1,e1))=e1;
[b10] DeformarBi(NuevaB())=ERROR;
[b11] DesformarBi(FormarBi(e1,q1))=q1;
[b12] DesformarBi(FormarBd(q1,e1)) si q1 es vacia return q1, si no return FormarBd(DesformarBi(q1),e1);
[b13] DeformarBd(NuevaB())=ERROR;
[b14] DesformarBd(FormarBi(e1,q1))=si q1 es vacia return q1, si no return FormarBi(DesformarBd(q1),e1);
[b15] DesformarBd(FormarBd(q1,e1))=q1; 
*/
