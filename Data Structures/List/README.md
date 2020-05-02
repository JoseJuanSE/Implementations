##List
#Elemental Funtions:

#Specifications: 

Funtion(): Parameters recived->what the function returns;
Empty():->List;
Cons():Elem,List->List
Is_Empty:List->Bool;
Head:List->Elem;
Remain:List->List;

#Axioms:
--Axioms: Elem e,List p;
[p1]	Is_Empty(Empty())=>True;
[p2]	Is_Empty(Cons(e,p))=>False;
[p3]	Head(Empty())->Error
[p4]	Head(Cons(e,p))=>e;
[p5]	Remain(Empty())->Error
[p6]	Remain(Cons(e,p))=>p;

#Otras Funciones:
PrintListF -> Print a List in a given file
PrintList -> Print a List on the screen
Size -> Returns size of a given list
PasteLists -> Returns a list formed of two given lists
ReverList -> Returns a given list in inverted order
InsOrd -> Insert a given element, such that if we inset all the element we want
          when we finish, we will have a list sorted, from least to greatest
SortList -> Returns a given list sorted from least to greatest
Is_Inlist -> Returns a bool value depending on whether a given element is in a given list
Comp -> Given two lists, returns true if both of these are equal
Is_Palindrome -> Returns true if he given list is a palindrome

#¿What is Elem.h?
This library is a helpful way to modificated fast and easy with which element our structure will works, so if we want a list int, we set elem to int, o if we want a queue's list, we just do it, set elem to queue.

#¿How to use this structure?
You have to have always Elem.h and List.h at the same binder that you .c that you will use.Feel you free to modified what you want and use this as you wish, to homework or development that you want.

##Lista
Funciones Elementeales:

#Especificaciones: 
Funcion():Parametros que recibe->lo que regresa;
Vacia():->Lista;
Cons():Elem,Lista->Lista
EsVacia:Lista->Booleano;
Cabeza:Lista->Elem;
Resto:Lista->Lista;

#Axiomas:
--Axiomas: Elem e,Lista p;
[p1]	EsVacia(Vacia())=>Cierto;
[p2]	EsVacia(Cons(e,p))=>false;
[p3]	Cabeza(Vacia())->Error
[p4]	Cabeza(Cons(e,p))=>e;
[p5]	Resto(Vacia())->Error
[p6]	Resto(Cons(e,p))=>p;

#Otras Funciones:
ImprimirListaF -> imprime lista en un archivo dado
ImprimirLista -> imprime lista en la pantalla
Tamaño -> Regresa el tamaño de una lista dada
PegaLista -> Regresa una lista dadas dos, estas son pegadas de forma adyacente
InvierteLista -> gira la lista, fin es el principio y viceversa
InsOrd -> Inserta en orden un elemento, de forma que si todo elemento se inserta con esta
          funcion, queda ordenada la lista
OrdenaLista -> Ordena la lista de forma creciente
Esta -> Se le da un elemento y una lista, la funcion regresa un true si esta en la lista y viceversa.
Comp -> dadas dos listas se regresa un true si son iguales
Espalind -> Dice si la lista dada es un palindromo

#¿Que es Elem.h?
Este archivo cabecera sirve para modificar de forma rapida con que elemento trabajara nuestra estructura de forma que si queremos una lista de int, modificamos elem, o si queremos una lista de colas, modificamos elem.

#¿Como usar las estructuras?
Ten siempre Elem.h y List.h, estas en la misma carpeta que tengas el archivo .c de prueba que vayas a usar. Sietete con la libertad de modificarlas y usarlas a tu antojo, para la tarea o proyecto que desees.
