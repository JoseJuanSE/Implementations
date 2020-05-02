#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Elem.h"
#include "Lista.h"
int main(int argc,char *argv[]){
	/*En este programa tienes que escrinbir por consola el nombre de un archivo txt, este tiene que estar en la misma
		carpeta que el .c . Este programa te imprimira en el archivo que tu le digas todas las palabras dadas en el primer
		archivo pero esta vez ordenada de forma lexicografica
	*/
	FILE *in=fopen(*++argv,"r");
	FILE *out=fopen(*++argv,"w");
	char pal[80],*pala;
	Lista l=Vacia();
	while(fscanf(in,"%s",pal)==1){
		pala =(char*)malloc(sizeof(char)*80);
		strcpy(pala,pal);
		l=Cons(pala,l);
	}
	ImpListaF(OrdLista(l),out);
	fclose(in);
	fclose(out);
	return 0;
}
