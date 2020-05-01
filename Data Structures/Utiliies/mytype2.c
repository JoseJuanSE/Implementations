#include<stdio.h>
int main(int argc,char *argv[]){
	FILE *in=fopen(*++argv,"r");
	FILE *out=fopen(*++argv,"w");
	char pal[80];
/*	while(argc--)
		printf("%s\n",*argv++);*/
	while(fscanf(in,"%s",pal)==1)
		fprintf(out,"%s\n",pal);
	fclose(in);
	fclose(out);
	return 0;
}
