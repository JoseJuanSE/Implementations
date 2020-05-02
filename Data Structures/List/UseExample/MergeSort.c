#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include "Elem.h"
#include "List.h"

int random(){return rand()%1000;}
List GetRanList(){
	List aux=Empty();
	
	srand(time( NULL ));
	int i,size=rand()%4+4;
	for(i=0;i<size;i++)
		aux=Cons(random(),aux);
	return aux;
}

List Ms(List a){
	List ans=Empty();
	struct Node *sentinel=a; 
	int tam=Size(a),i;
	for(i=0;i<tam/2;i++)sentinel=sentinel->next;
	while(sentinel!=NULL){
		ans=Cons(sentinel->val,ans);
		sentinel=sentinel->next;
	}
	return ans;
}
List Mi(List a){
	List ans=Empty();
	struct Node *sentinel=a; 
	int tam=Size(a),i;
	for(i=0;i<tam/2;i++){
		ans=Cons(sentinel->val,ans);
		sentinel=sentinel->next;
	}
	return ans;
}
List Mix(List a1,List a2){
	List ans=Empty();
	while(!Is_Empty(a1) || !Is_Empty(a2)){
		Elem n;
		if(Is_Empty(a1)){
			n=Head(a2);
			a2=Remain(a2);
		}else if(Is_Empty(a2)){
			n=Head(a1);
			a1=Remain(a1);
		}else if(Head(a1)<Head(a2)){
			n=Head(a1);
			a1=Remain(a1);
		}else{
			n=Head(a2);
			a2=Remain(a2);
		}
		ans=Cons(n,ans);
	}
	return ReverList(ans);
}
List MergeSort(List a){
	if(Size(a)<2)return a;
	return Mix(MergeSort(Mi(a)),MergeSort(Ms(a)));
}

int main(){
	List a;
	a=GetRanList();
	printf("List before sort: \n");
	PrintList(a);
	a=MergeSort(a);
	printf("\n\nList after sort: \n\n");
	PrintList(a);
	return 0;
}
