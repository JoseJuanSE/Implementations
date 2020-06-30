#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Elem.h"
#include"Lista.h"
#include"TablaH.h"
int main(){
    TablaH t=consH(55);
    int i=0;
    for(i;i<54;i++)
        t[i]=vacia();

    while(1){
        system("cls");
        printf("Menu:\n");
        printf("1.- Preguntar por elemento\n");
        printf("2.- Dar de alta elemento\n");
        printf("3.- Eliminar elemento\n");
        printf("Seleccione una opcion: ");
        int n;
        scanf("%d",&n);
        switch(n){
            case 1:{
                printf("\nIngresa el nombre del elemento de interes: ");
                Elem nue;
                scanf("%s",nue.nom);
                if(!estaenH(nue,t))printf("El elemento no existe...\n");
                else{
                    nue=consulta(nue,t);
                    ImpElem(nue);
                }
                break;
            }
            case 2:{
                Elem nue2;
                printf("\nIngresa el nombre de tu elemento: ");
                scanf("%s",nue2.nom);
                printf("Ingresa el simbolo de tu elemento: ");
                scanf("%s",nue2.sim);
                printf("Ingresa el numero atomico de tu elemento: ");
                scanf("%d",&nue2.Atn);
                printf("Elemento insertado...\n");
                t=insertaH(nue2,t);
                break;
            }
            case 3:{
                Elem nue3;
                printf("\nIngresa el nombre del elemento que deseas eliminar: ");
                scanf("%s",nue3.nom);
                if(!estaenH(nue3,t))printf("El elemento no existe...\n");
                else {
                    t=elimina(nue3,t);
                    printf("Elemento Eliminado...\n");
                }
                break;
            }
            default:
                printf("Ingrese una opcion valida...\n");
        }
        printf("Ingrese 1 para continuar, cualquier otro para salir: ");
        int g;
        scanf("%d",&g);
        if(g!=1)return 0;
    }
}
