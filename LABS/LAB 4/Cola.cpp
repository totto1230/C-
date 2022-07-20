/*Realizar un método que indique cual es el menor de los boletos.
Realizar un método que atienda el boleto menor y lo saque de la cola y lo guarde en una cola llamada atendidos
Realizar un menú que contenga lo siguiente:
Ingresar una persona con su respectivo boleto, el boleto lo debe ingresar manera aleatoria
Mostrar la lista de personas con su boleto.
Atender persona.
Atender persona con el boleto menor.
Mostrar personas atendidas.
Salir del sistema*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct nodoPersona
{
	int boleto;
	string nombre;
	nodoPersona *siguiente;
};
typedef struct nodoPersona *lista;

nodoPersona *crearNodo(string n,int b)
{
	nodoPersona *aux = new (struct nodoPersona);
	aux->boleto=b;
	aux->nombre=n;
	aux->siguiente=NULL;
	return aux;
}

void Poner(lista &cab,string n,int b)
{
	lista aux;
	nodoPersona *nuevo;
	
	nuevo=crearNodo(n,b);
	
	if(cab==NULL)
	cab=nuevo;
	
		else
			{
				aux=cab;
				while(aux->siguiente!=NULL)
				aux=aux->siguiente;
				
				aux->siguiente=nuevo;
			}		
}

void Mostrar(lista cab)
{
	lista aux;
	if(cab==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cab;
		while(aux!=NULL)
		{
			cout<<"Nombre: "<<aux->nombre<<endl;
			cout<<"Boleto: "<<aux->boleto<<endl;
			cout<<"*********************"<<endl;
			aux=aux->siguiente;
		}
	}
}

nodoPersona *Quitar(lista &cab)
{
	lista aux;
	nodoPersona *temp=NULL;
	
	if(cab==NULL)
	return NULL;
	
	else
	{
		aux=cab;
		cab=aux->siguiente;
		aux->siguiente=NULL;
		temp=crearNodo(aux->nombre,aux->boleto);
		delete(aux);
	}
	return temp;
}

void  buscarMayor(lista cab)
{
	lista ColaAux=NULL;
	nodoPersona *aux=NULL;
	int mayor;
	
	aux=Quitar(cab);
	mayor=aux->boleto;

	while(aux!=NULL)
	{
		
		if(mayor < aux->boleto)
		 mayor=aux->boleto;
		
		Poner(ColaAux,aux->nombre,aux->boleto);	
		aux=Quitar(cab);
	}
	
	aux=Quitar(ColaAux);
	while(aux!=NULL)
	{	
		Poner(cab,aux->nombre,aux->boleto);	
		aux=Quitar(ColaAux);
	}
	
	cout <<"El boleto mayor es: " <<mayor<<endl;
}



int main()
{
	lista Cola=NULL;
	int b=rand()%100;
	Poner(Cola,"Luis",b);
	b=rand()%100;
	Poner(Cola,"Juan",152);
 	Poner(Cola,"Cristina",80);
 	Poner(Cola,"Carlos",32);
 	Poner(Cola,"Marco",70);
 
	
	Mostrar(Cola);
	system("pause");
	cout<<"Nombre: "<<Quitar(Cola)->nombre<<endl;
	system("pause");
	Mostrar(Cola);
	system("pause");
	buscarMayor(Cola);
	system("Pause");
	Mostrar(Cola);
	system("pause");
	
}





