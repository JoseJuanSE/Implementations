typedef struct Node{
   Elem val;
   struct Node *next;
} *List;

List Empty(){return NULL;}

bool Is_Empty(List a){return a==NULL;}

Elem Head(List a){return a->val;} 

List Remain(List l){return l->next;}

List Cons(Elem x,List Remain){
    List _new=(List)malloc(sizeof(struct Node));
    _new->val=x;
    _new->next=Remain;
    return _new;
}

void PrintListF(List a,FILE *out){
   if(!Is_Empty(a)){
       ImpElemF(Head(a),out);       
       PrintListF(Remain(a),out);
   }
}

void PrintList(List a){
 	PrintListF(a,stdout);
}

int Size(List a){
   if(Is_Empty(a))return 0;
   return Size(Remain(a))+1; 
}

List PasteLists(List l1,List l2){
	if(Is_Empty(l1))return l2;
	return Cons(Head(l1),PasteLists(Remain(l1),l2));		
}

/* Iterative Version
List PasteLists(List a,List b){
	List remain=a;
	while(a->next!=Empty())
		a=Remain(a);	
	a->next=b;
	return res;
}*/

List ReverList(List l){
	if(l!=Empty())
		return PasteLists(ReverList(Remain(l)),Cons(Head(l),Empty()));
}

List InsOrd(Elem e,List l){
	if(Is_Empty(l))
		return  Cons(e,l);
	else if(Less_Than(e,Head(l)))
		return Cons(e,l);
	else
		return Cons(Head(l),InsOrd(e,Remain(l)));
}

List SortList(List l){
	if(Is_Empty(l))
		return l;
	return InsOrd(Head(l),SortList(Remain(l)));
}

bool Is_Inlist(Elem x,List l){
	if(Is_Empty(l))
		return false;
	if(Is_Equal(Head(l),x))
		return true;
	return Is_Inlist(x,Remain(l));
}

bool Comp(List a,List b){
	if(Is_Empty(a) && Is_Empty(b))
		return true;	
	if(Is_Empty(a) || Is_Empty(b) || !Is_Equal(Head(a),Head(b)))	
		return false;
	return Comp(Remain(a),Remain(b));
}

bool Is_Palindrome(List a){
	return Comp(a,ReverList(a));
}

