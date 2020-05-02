//Resolviendo practica con nuestra estructura lista

/*
Práctica: Haciendo uso del TDA Lista, y de la función:

Lista OrdenaLista(Lista);

definir una función que reciba como argumento dos listas ordenadas, y devuelva una lista, también ordenada, que contenga los elementos de ambas listas.

En realidad, la práctica no es otra cosa que programar una "versión" del algoritmo de ordenamiento "Merge Sort" u Ordenamiento por Mezcla. Este ordenamiento consiste en tomar una lista de elementos desordenados, llamémosle 'l', formar formar dos listas (li, ls), cada una conteniendo la mitad de los elementos de la 'l'. Luego, ordenamos recursivamente 'li' y 'ls' para, finalmente, mezclarlas en una sola lista ordenada, 'lo'. Sin embargo, en nuestro caso, nosotros implementaremos una versión un poco diferente, en la que la función:

Lista OrdenaListaMezcla(Lista l){
Lista li, ls;

li=MitadInferior(l);
ls=MitadSuperior(l);

devolver Mezclar(OrdenaLista(li), OrdenaLista(ls));
};

o, alternativamente:

Lista OrdenaListaMezcla(Lista l){
devolver Mezclar(OrdenaLista(MitadInferior(l)), OrdenaLista(MitadSuperior(l)));
};

donde Lista Mezclar(Lista, Lista) no la implementaremos de forma recursiva, sino iterativa.

Ejemplo:

Sea Lista l=[3,1,6,4,8,9,7,2,0]. Entonces:

Lista lo=OrdenaListaMezcla(l) = Mezclar(OrdenaLista(MitadInferior([3,1,6,4,8,9,7,2,0])), OrdenaLista(MitadSuperior([3,1,6,4,8,9,7,2,0])));
= Mezclar(OrdenaLista([3,1,6,4,8]), OrdenaLista([9,7,2,0]));
= Mezclar([1,3,4,6,8],[0,2,7,9])= [0,1,2,3,4,6,7,8,9].

Es evidente lo que las funciones Mezclar, MitadInferior y MitadSuperior, deben de realizar.

Consieraciones:

1.- Elem lo definiremos como int.
2.- Para que se facilite la evaluación del ejercicio, al momento de enviar la tarea deberán de proporcionarme sus archivos Lista.h, Elem.h y practica1.c. Con el fin de que yo pueda compilar y ejecutar su práctica y no tener problemas con los nombres de las funciones, en el caso en el que hayan usado nombres diferentes a los que yo use en la clase. Por ejemplo, que hayas usado "ordenalista", en lugar de "OrdenaLista".
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include "Elem.h"
#include "List.h"

int random(){return rand()%1000;}
List GetRanList(){
	List aux=Empty();
	
	srand(time( NULL ));
	int i,size=rand()%20+10;
	for(i=0;i<size;i++)
		aux=Cons(random(),aux);
	return aux;
}

//Funciones de la tarea
List Ms(List a){
	List ans=Empty();
	struct Node *sentinel=a; 
	int tam=Size(a),i;
	for(i=0;i<tam/2;i++)sentinel=sentinel->next;
	while(sentinel!=NULL){
		ans=Cons(sentinel->val,ans);
		sentinel=sentinel->next;
	}
	printf("\n\nLista Ms: \n\n");
	PrintList(ReverList(ans));
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
	printf("\n\nLista Mi: \n\n");
	PrintList(ReverList(ans));
	return ans;
}
List Mezclar(List a1,List a2){
	List ans=Empty();
	while(!Is_Empty(a1) || !Is_Empty(a1)){
		Elem n;
		if(Is_Empty(a1)){
			n=Head(a2);
			a2=Remain(a2);
		}else if(Is_Empty(a2)){
			n=Head(a1);
			a1=Remain(a1);
		}
		else if(Head(a1)<Head(a2)){
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
List OrdenaListaMezcla(List a){
	return Mezclar(SortList(Mi(a)),SortList(Ms(a)));
}
//----------------------
int main(){
	List a;
	a=GetRanList();
	printf("Lista Antes de Ordenar: \n");
	PrintList(a);
	a=OrdenaListaMezcla(a);
	printf("\n\nLista despues de Ordenar: \n\n");
	PrintList(a);
	return 0;
}

