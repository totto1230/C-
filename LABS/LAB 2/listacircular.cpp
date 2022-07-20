#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct nodoNumero
{
	int numero;
	nodoNumero *sig;	
};
typedef struct nodoNumero *lista;

nodoNumero *crearNodo(int n)
{
	nodoNumero *aux = new (struct nodoNumero);
	aux->numero=n;
	aux->sig=NULL;
	return aux;
}

void agregarInicio(lista &cab,int n)
{
	nodoNumero *nuevo= crearNodo(n);
	lista aux;
	
	if(cab==NULL)
	cab=nuevo;
	else
	{
		aux=cab;
		while(aux->sig!=cab)
		aux=aux->sig;
		aux->sig=nuevo;
		nuevo->sig=cab;
		cab=nuevo;
	}
}

void agregarFinal(lista &cab,int n)
{
	nodoNumero *nuevo= crearNodo(n);
	lista aux;
	
	if(cab!=NULL){
		aux=cab;
		while(aux->sig!=cab)
		aux=aux->sig;
		nuevo=aux;	
	}
		
	else
	{
		cout << "Lista vacia";
	}
}

void insertarNodo(lista &cab,int n){
	
	
	
	
}


//Método utilizado para ver los datos de la lista
void mostrarLista(nodoNumero *lista){
	//Se declara un puntero local para saber dónde estamos posicionados
	nodoNumero *actual= new nodoNumero();
	//Al igualarse con lista, significa que va a estar apuntando al primer nodo de la lista
	actual= lista;
	//Siempre y cuando actual sea diferente a NULL, es decir, al último no va a entrar al while
	while(actual->sig != lista){
		//Acá simplemente se imprime el número que tiene almacenado en la posición actual
		cout << actual -> numero << " - - - > ";
		//Se le dice actual que se mueva a la posición siguiente (él mismo+sig)
		actual=actual ->sig;
	}
	
}




void menu()
{
	lista List=NULL;
	int opc,num;
	
	do
	{   system("cls");
		cout <<"-----MENU PRINCIPAL------"<<endl;
		cout <<"1. Agregar Inicio"<<endl;
		cout <<"2. Agregar Final"<<endl;
		cout <<"3. Agregar en medio de dos numeros"<<endl;
		cout <<"4. Buscar un numero"<<endl;
		cout <<"5. Mostrar la lista"<<endl;
		cout <<"6. Eliminar un numero"<<endl;
		cout <<"7. Mostrar los numeros pares"<<endl;
		cout <<"8. Mostrar los numeros impares"<<endl;
		cout <<"9. Mostrar el promedio"<<endl;
		cout <<"10. Salir"<<endl;
		cout <<"Digite la opcion que desea: ";
		cin >> opc;
		switch (opc)
		{
			case 1:
			       {
				   cout << "Digite el primer numero: ";
				   cin >> num;
				   agregarInicio(List,num);
				   cout << "Numero almacenado" <<endl;
				   system("pause");
				   break;
				   }
			case 2:
			       {
				   cout << "Digite el primer numero: ";
				   cin >> num;
				   agregarFinal(List,num);
				   cout << "Numero almacenado" <<endl;
				   system("pause");
				   break;
				   }	   
			case 5:
			       {
				   mostrarLista(List);
				   system("pause");
				   break;
				   }	   
			
		}		
	}
	while(opc!=11);
}
int main()
{
	menu();
}

