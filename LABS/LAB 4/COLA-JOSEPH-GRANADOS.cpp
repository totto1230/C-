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

int  buscarMenor(lista cab)
{
	lista ColaAux=NULL;
	nodoPersona *aux=NULL;
	int menor;
	
	aux=Quitar(cab);
	menor=aux->boleto;

	while(aux!=NULL)
	{
		
		if(menor > aux->boleto)
		 menor=aux->boleto;
		
		Poner(ColaAux,aux->nombre,aux->boleto);	
		aux=Quitar(cab);
	}
	
	aux=Quitar(ColaAux);
	while(aux!=NULL)
	{	
		Poner(cab,aux->nombre,aux->boleto);	
		aux=Quitar(ColaAux);
	}
	
	cout <<"El boleto menor es: " <<menor<<endl;
	return menor;
}

void PonerEnLista(lista &cab,string n,int b)
{
	lista atendidos;
	nodoPersona *nuevo;
	
	nuevo=crearNodo(n,b);
	
	if(cab==NULL)
	cab=nuevo;
	
		else
			{
				atendidos=cab;
				while(atendidos->siguiente!=NULL)
				atendidos=atendidos->siguiente;
				
				atendidos->siguiente=nuevo;
			}		
}

int random(){
	int a;
	a=rand()% (50);
	return a;
}

int main()
{
	lista Lista=NULL;
	lista Atendidos=NULL;
	int opc,boleto,menor;
	string name;
	do
	{   system("cls");
		cout <<"-----MENU PRINCIPAL------"<<endl;
		cout <<"1. Ingresar una persona con su respectivo boleto aleatorio"<<endl;
		cout <<"2. Cual es el menor de los boletos"<<endl;
		cout <<"3. Sacar el boleto menor y guardarlo en ATENDIDOS"<<endl;
		cout <<"4. Mostrar la lista total"<<endl;
		cout <<"5. Salir"<<endl;
		cin >> opc;
		switch (opc){
			case 1:
			boleto=random();
			cout<< "INGRESE EL NOMBRE "<< endl;
			cin>> name;
			Poner(Lista,name,boleto);	
			break;
			
			case 2:
			buscarMenor(Lista);	
			system("pause");
			break;
			
			case 3:
			menor=buscarMenor(Lista);
			PonerEnLista(Atendidos,"TEST",menor);
			Mostrar(Atendidos);
			system("pause");
			break;
			
			case 4:
			Mostrar(Lista);	
			system("pause");
			break;
		}

	}
	while(opc != 5);
	cout<<"HAS SALIDO"<< endl;
}
