typedef Lista Cola;
Cola Nueva(){return Vacia();}
bool EsNueva(Cola q){return EsVacia(q);}
Cola Formar(Cola q,elem e){
	if(EsNueva(q))return Cons(e,q);
	return Cons(Cabeza(q),Formar(Resto(q),e));
}
Cola Desformar(Cola q){return Resto(q);}
elem Primero(Cola q){return Cabeza(q);}
