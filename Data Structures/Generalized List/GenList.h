#include<stdbool.h>
typedef struct NodeGenList{
	bool IsList;
	union {
		Elem Chunk;
		struct NodeGenList *GenListElem ;
	} value;
	struct NodeGenList *next;
}*GenList;

GenList Empty(){return NULL;}

GenList InsElem(Elem e, GenList lg){
	GenList temp = (GenList)malloc(sizeof(struct NodeGenList));
	temp->IsList = 0;
	temp->value.Chunk = e;
	temp->next = lg;
	return temp;
}

GenList InsList(GenList e, GenList lg){
	GenList temp = (GenList)malloc(sizeof(struct NodeGenList));
	temp->IsList = 1;
	temp->value.GenListElem = e;
	temp->next = lg;
	return temp;
}

bool IsEmpty(GenList lg){return lg==NULL;}

Elem TopElem(GenList lg){ return lg->value.Chunk;}

GenList TopList(GenList lg){ return lg->value.GenListElem;}

GenList Pop(GenList lg){ return lg->next;}

int IsList(GenList lg){ return lg->IsList;}

int NumElements(GenList lg){
	if(IsEmpty(lg))return 0;
	return NumElements(Pop(lg))+1;
}
void ImpLGinside(GenList a,bool sal){
    if(IsEmpty(a)){
        if(sal)printf("\n");
        return;
    }
    if(IsList(a)){
        printf("| ");
        ImpLGinside(TopList(a),0);
        printf("| ");
    }else{
        //print the element without endl and print and space 
        ImpElemaux(TopElem(a));
    }
    ImpLGinside(Pop(a),sal);
}
void PrintGenList(GenList a){
    if(IsEmpty(a))return;
    if(IsList(a)){
        ImpLGinside(TopList(a),1);
    }else{
        //print element with an endl
        PrintElem(TopElem(a));
    }
    PrintGenList(Pop(a));
}
/*
Espec GenList
Empty: -> GenList;
InsElem: Elem, GenList -> GenList;
InsList: GenList, GenList -> GenList;
IsEmpty: Elem -> bool;
IsList: GenList -> bool;
Topchunk: GenList -> Elem;
TopList: GenList -> GenList;
Pop: GenList -> GenList;

Axioms: GenList l1, l2; Elem e;
[lg1] IsEmpty(Empty()) = True;
[lg2] IsEmpty(ConsElem(e, l1)) = False;
[lg3] IsEmpty(InsList(l1, l2)) = False;
[lg4] IsList(Empty()) = Error;
[lg5] IsList(ConsElem(e, l1)) = False;
[lg6] IsList(InsList(l1, l2)) = True;
[lg7] Topchunk(Empty()) = Error;
[lg8] Topchunk(ConsElem(e,l1)) = e;
[lg9] Topchunk(InsList(l1,l2)) = Error;
[lg10] TopList(Empty()) = Error;
[lg11] TopList(ConsElem(e, l1)) = Error;
[lg12] TopList(InsList(l1, l2)) = l1;
[lg13] Pop(Empty()) = Error;
[lg14] Pop(ConsElem(e, l1)) = l1;
[lg15] Pop(InsList(l1, l2)) = l2;
*/
