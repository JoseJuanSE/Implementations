typedef struct Nodo{
   elem val;
   struct Nodo *next,*last;
} *Queue;
Queue Empty(){return NULL;}
bool IsEmpty(Queue q){return q==NULL;}
elem Front(Queue q){return q->val;} 

Queue Pop(Queue q){
	q->next->last=q->last;
	return q->next;
}

Queue Push(Queue res,elem x){
   Queue nuevo=(Queue)malloc(sizeof(struct Nodo));	
	if(IsEmpty(res)){
		nuevo->val=x;
		nuevo->last=nuevo;
		nuevo->next=NULL;
	   return nuevo;	
	}else{
		nuevo->val=x;
		res->last->next=nuevo;
		res->last=nuevo;		
		nuevo->next=NULL;
		nuevo->last=nuevo;
		return res;
	}
}
/*--Espec Queue
nueva:->Cola;
formar:cola,elem->cola;
esnueva:cola->Bool;
primero:Cola->Elem;
desformar:Cola->Cola;

--Axiomas: Elem e,Cola p;
[p1]	EsNueva(Nueva())=Cierto;
[p2]	EsNueva(push(e,p))=false;
[p3]	Primero(empty())->Error
[p4]	Primero(push(e,p))=e;
[p5]	Desformar(nueva())->Error
[p6]	Desformar(formar(q,e))=Si es nueca q(q) ret q;


*/
