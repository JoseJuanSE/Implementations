#include<stdio.h>
#include<stdlib.h>

#include "Elem.h"
#include "List.h"
#define endl printf("\n");
int main(){
   List a=Empty(),b=Empty();
   printf("Is empty? %s\n", (Is_Empty(a)) ? "true" : "false");
   a=Cons(5,a);
   printf("Is empty? %s\n", (Is_Empty(a)) ? "true" : "false");
   a=Cons(6,a);  
   printf("Current head is %d\n",Head(a));
   printf("Current size is %d\n",Size(a));
   a=Cons(7,a);
	b=Cons(10,b);	b=Cons(11,b);	b=Cons(12,b);
	List gg=PasteLists(a,b);   
	endl
	PrintList(gg);
	endl
	PrintList(ReverList(gg));
	endl
	PrintList(InsOrd(24,InsOrd(6,InsOrd(27,InsOrd(17,InsOrd(13,InsOrd(6,Empty())))))));
	endl
	List c=Empty(),d=Empty();
	int i=7;
	while(i!=1){
		c=Cons(i,c);
		if(i%2)i=i*3+1;
		else i/=2;
	}
	i=13;
	while(i!=1){
		d=Cons(i,d);
		if(i%2)i=i*3+1;
		else i/=2;
	}
	printf("Collatz conjeture with 7: ");
	endl
	PrintList(c);
	endl
	printf("Collatz conjeture with  13: ");
	endl
	PrintList(d);
	endl
	PrintList(ReverList(SortList(PasteLists(c,d))));
	endl
	printf("Is 7 in Collatz conjeture with 13?: %s",(Is_Inlist(7,d))?"YES":"NO");
	endl
	printf("Is 40 in Collatz conjeture with 13 13?: %s",(Is_Inlist(40,d))?"YES":"NO");
	endl
	b=Cons(7,Cons(6,Cons(5,Empty())));
	printf("Is equal a and b?: %s",(Comp(a,b))?"YES":"NO");
	endl
	printf("Is equal a and c?: %s",(Comp(a,c))?"YES":"NO");
	endl
	printf("Is a an palindrome?: %s",(Is_Palindrome(a))?"YES":"NO");
	endl
	List palindromo=Empty();
	for(i=0;i<10;i++)
		palindromo=Cons(i,palindromo);
	for(i=10;i>=0;i--)
		palindromo=Cons(i,palindromo);	
	printf("Is the palindrome an palindrome?: %s",(Is_Palindrome(palindromo))?"YES":"NO");
	endl
	return 0;
}
