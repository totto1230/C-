#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct nodoPalabra
{
	string palabra;
	nodoPalabra *sig;
};

struct nodoLetra 
{
	char letra;
	nodoLetra *sig;
	nodoPalabra *pal;
};
typedef struct nodoLetra *lista;

nodoLetra *crearNodoLetra(char letra)
{
	nodoLetra *aux = new (struct nodoLetra);
	aux->letra=letra;
	aux->sig=NULL;
	aux->pal=NULL;
	
	return aux;
}

nodoPalabra *crearNodoPalabra(string p)
{
	nodoPalabra *aux = new (struct nodoPalabra);
	aux->palabra=p;
	aux->sig=NULL;
	
	return aux;
}

void AgregarLetra(lista &cab,char Ltr)
{
	nodoLetra *nuevo;
	lista aux;
	nuevo= crearNodoLetra(Ltr);
	
	
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

void AgregarPalabra(lista &cab,string palabra)
{
	lista aux;
	nodoPalabra *aux1;
	nodoPalabra *nuevo;
	nuevo=crearNodoPalabra(palabra);
	
	if(cab==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cab;
		while(aux!=NULL)
		{
			if(aux->letra==toupper(palabra[0]))
			{
				if(aux->pal==NULL)
				aux->pal=nuevo;
				else
				{
					aux1=aux->pal;
					while(aux1->sig!=NULL)
					aux1=aux1->sig;
					
					aux1->sig=nuevo;
				}
				
				aux1=NULL;
			}
			aux=aux->sig;
		}
	}
}




void Mostrar(lista cab)
{
	lista aux;
	nodoPalabra *aux1;
	
	if(cab==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cab;
		while(aux!=NULL)
		{
			cout<<"Letra: "<<aux->letra<<endl;
			cout<<"**********"<<endl;
			if(aux->pal==NULL)
			cout <<"no hay palabra"<<endl;
			else
			{
				aux1=aux->pal;
				while(aux1!=NULL)
				{
					cout<<"Palabra: "<<aux1->palabra<<endl;
					cout<<"**********"<<endl;	
					aux1=aux1->sig;
				}
			}			
			aux=aux->sig;
		}
	}
}


int main()
{
	lista Lista=NULL;
	
	AgregarLetra(Lista,'A');
	AgregarLetra(Lista,'B');
	AgregarLetra(Lista,'C');
	AgregarLetra(Lista,'D'); 
	AgregarPalabra(Lista,"casa");
	AgregarPalabra(Lista,"dedo");
	AgregarPalabra(Lista,"bola");
	AgregarPalabra(Lista,"Avion");
	AgregarPalabra(Lista,"Abaco");
	Mostrar(Lista);
	system("Pause");
	
}
