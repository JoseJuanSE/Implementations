#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Elem.h"
#include "deque.h"
int main(){
   int n;
   //scanf("%d",&n);
   BiCola c=FormarBd(FormarBi(5,FormarBd(FormarBi(3,FormarBi(1,Nueva())),2)),4);
   for(n=0;n<=10;n++)
   		c=FormarBd(c,n);
   ImpBi(c);   
}
