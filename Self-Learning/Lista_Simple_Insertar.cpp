# include <iostream>
# include <stdio.h>
# include <stdlib.h>

using namespace std;

struct num {
	int a;
	char b;
	num *sig;
};
typedef struct num *lista;


num *crearEstructura(int a, char b){
	num *nuevo_nodo= new (struct num);
	nuevo_nodo->a=a;
	nuevo_nodo->b=b;
	nuevo_nodo->sig=NULL;
	return nuevo_nodo;
}

void ingresar(lista &lista,int a, char b){
	num *nuevo_nodo= crearEstructura(a,b);
	if (lista==NULL){
		lista=nuevo_nodo;
	}
	else{
		nuevo_nodo->sig=lista;
		lista=nuevo_nodo;
	}
}


void ingresarFinal (lista &cab, int a, char b){
	num *nuevo;
	lista aux;
	nuevo=crearEstructura(a,b);
	
	if(cab==NULL)
	cab=nuevo;
	else
	{
		aux=cab;
		while(aux->sig!=NULL)
		aux=aux->sig;
		
		aux->sig=nuevo;
	}
}

void mostrar(lista listaa){
	if (listaa==NULL){
		cout<<"LISTA VACIA"<< endl;
	}
	else{
		listaa;
		while(listaa!=NULL){
			cout<< "------" << listaa->a << " " << listaa->b << "------"<< endl;
			listaa=listaa->sig;
		}	
	}
}


int main (){
	lista listaa=NULL;
	int a= 15;
	char b= 'n';
	ingresarFinal(listaa, a, b);
	int nba= 25;
	char ba= '4';
	ingresarFinal(listaa, nba, ba);
	int nbaa= 255;
	char baa= 'a';
	ingresarFinal(listaa, nbaa, baa);
    mostrar(listaa);
    
}



