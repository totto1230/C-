#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct num{
	int a;
	char b;
	num *ant;
	num *sig;
};
typedef struct num *lista;

num *crearNodo(int aa, char bb){
	num *aux= new (struct num);
	aux->a=aa;
	aux->b=bb;
	aux->ant=NULL;
	aux->sig=NULL;
	return aux;
}

void ingresarInicio(lista &ant, lista &sig, int aa, char bb){
	num *nuevo= crearNodo(aa, bb);
	lista aux;
	
	if(ant==NULL){
		ant=nuevo;
		sig=nuevo;
		nuevo->ant=NULL;
		nuevo->sig=NULL;
	}
	else{
		nuevo->ant=sig;
		nuevo->sig=nuevo;
		sig = sig->sig;
	}	
}

void mostrar(lista listaa){
	if (listaa==NULL){
		cout<<"LISTA VACIA"<< endl;
	}
	else{
		listaa;
		while(listaa!=NULL){
			cout<< "  <------" << listaa->a << " " << listaa->b << "------>  ";
			listaa=listaa->sig;
		}	
	}
}

int main (){
	lista sig=NULL;
	lista ant=NULL;
	lista listaa=NULL;
	int a= 15;
	char b= 'n';
	ingresarInicio(sig, ant, a, b);
	int nba= 25;
	char ba= '4';
	ingresarInicio(sig, ant, nba, ba);
	int nbaa= 255;
	char baa= 'a';
	ingresarInicio(sig, ant, nbaa, baa);
	listaa=ant;
    mostrar(listaa);
	
	
}
