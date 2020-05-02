# List
Elemental Funtions:

### Specifications: 
```
Funtion(): Parameters recived->what the function returns;
```
```
Empty():->List;
```
```
Cons():Elem,List->List
```
```
Is_Empty:List->Bool;
```
```
Head:List->Elem;
```
```
Remain:List->List;
```
### Axioms:
* Axioms: Elem e,List p;
- Is_Empty(Empty())=>True;
- Is_Empty(Cons(e,p))=>False;
- Head(Empty())->Error
- Head(Cons(e,p))=>e;
- Remain(Empty())->Error
- Remain(Cons(e,p))=>p;

### Other Funtions:
* PrintListF -> Print a List in a given file
* PrintList -> Print a List on the screen
* Size -> Returns size of a given list
* PasteLists -> Returns a list formed of two given lists
* ReverList -> Returns a given list in inverted order
* InsOrd -> Insert a given element, such that if we inset all the element we wantwhen we finish, we will have a list sorted, from least to greatest.
* SortList -> Returns a given list sorted from least to greatest
* Is_Inlist -> Returns a bool value depending on whether a given element is in a given list
* Comp -> Given two lists, returns true if both of these are equal
* Is_Palindrome -> Returns true if he given list is a palindrome



# Lista
Funciones Elementeales:

### Especificaciones: 
```
Funcion():Parametros que recibe->lo que regresa;
```
```
Vacia():->Lista;
```
```
Cons():Elem,Lista->Lista
```
```
EsVacia:Lista->Booleano;
```
```
Cabeza:Lista->Elem;
```
```
Resto:Lista->Lista;
```
### Axiomas:
* Axiomas: Elem e,Lista p;
- EsVacia(Vacia())=>Cierto;
- EsVacia(Cons(e,p))=>false;
- Cabeza(Vacia())->Error
- Cabeza(Cons(e,p))=>e;
- Resto(Vacia())->Error
- Resto(Cons(e,p))=>p;

### Otras Funciones:
* ImprimirListaF -> imprime lista en un archivo dado
* ImprimirLista -> imprime lista en la pantalla
* Tamaño -> Regresa el tamaño de una lista dada
* PegaLista -> Regresa una lista dadas dos, estas son pegadas de forma adyacente
* InvierteLista -> gira la lista, fin es el principio y viceversa
* InsOrd -> Inserta en orden un elemento, de forma que si todo elemento se inserta con esta funcion, queda ordenada la lista
* OrdenaLista -> Ordena la lista de forma creciente
* Esta -> Se le da un elemento y una lista, la funcion regresa un true si esta en la lista y viceversa.
* Comp -> dadas dos listas se regresa un true si son iguales
* Espalind -> Dice si la lista dada es un palindromo

