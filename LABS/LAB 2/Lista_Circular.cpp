#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Se declara la estructura que vamos a utilizar para crear los nodos con sus data y puntero
struct nodoNumero{
	int numero;
	nodoNumero *sig;
};

typedef struct nodoNumero *lista;

//METODO UTILIZADO PARA CREAR LOS NODOS
nodoNumero *crearNodo(int n){
	nodoNumero *aux = new (struct nodoNumero);
	aux->numero=n;
	aux->sig=NULL;
	return aux;
}


void agregarInicio(lista &cab,int n){
	nodoNumero *nuevo;
	nuevo=crearNodo(n);
	lista aux;
	if(cab==NULL){
		cab=nuevo;
		nuevo->sig=nuevo;
	}		
	else{
		aux=cab;
		while(aux->sig!=cab)
		aux=aux->sig;
		aux->sig=nuevo;
		nuevo->sig=cab;
		cab=nuevo;
	}
	cout << num << " ha sido agregado correctamente" << endl;
	cout << " " << endl;
}

void agregarFinal(lista &cab,int n){
	nodoNumero *nuevo;
	nuevo=crearNodo(n);
	lista aux;
	if(cab==NULL){
		cab=nuevo;
		nuevo->sig=nuevo;
	}		
	else{
		aux=cab;
		while(aux->sig!=cab)
		aux=aux->sig;
		aux->sig=nuevo;
		nuevo->sig=cab;
		nuevo=cab;
	}
	cout << num << " ha sido agregado correctamente" << endl;
	cout << " " << endl;
}

void agregarMedio(lista &cab,int n){
	nodoNumero *nuevo;
	nuevo=crearNodo(n);
	lista aux;
	if(cab==NULL){
		cab=nuevo;
	}
	else{
		nuevo->sig = cab->sig;
   		cab->sig = nuevo;
	}
	out << num << " ha sido agregado correctamente" << endl;
	cout << " " << endl;
}

void buscarUnNumero(lista cab,int n){
    lista aux;
    bool encontrado=false;
   
    if(cab==NULL){
    	cout <<"Lista vacia" << endl;
	}
    else{
        aux=cab;
		do{
			if(aux->numero == n){
				cout <<"Se encontro el numero: "<< n << endl;
				encontrado=true;
				break;
			}
			aux=aux->sig;
		}
		while(aux!=cab);
		if(!encontrado){
			cout <<"No encontro el numero: "<< n << endl;
		}
	}
}

void mostarLista(lista cab){
	lista aux;
	if(cab==NULL){
		cout <<"Lista vacia" << endl;
	}
	else{
		aux=cab;
		do{
			cout << "Numero: " << aux->numero<<endl;
			cout << "----------------------------" <<endl;
			aux=aux->sig;
		}
		while(aux!=cab);
	}

}


void menu(){
		lista List=NULL;
		int opc,num;
	do{   
		system("cls");
		cout <<"-----MENU PRINCIPAL------"<<endl;
		cout <<"1. Agregar Inicio"<<endl;
		cout <<"2. Agregar Final"<<endl;
		cout <<"3. agregar en medio de dos numeros"<<endl;
		cout <<"4. Buscar un numero"<<endl;
		cout <<"5. Mostrar la lista"<<endl;
		cout <<"6. Eliminar un numero"<<endl;
		cout <<"7. Mostrar los numeros pares"<<endl;
		cout <<"8. Mostrar los numeros impares"<<endl;
		cout <<"9. Mostrar el promedio"<<endl;
		cout <<"10. Salir"<<endl;
		cout <<"Digite la opcion que desea: ";
		cin >> opc;
		switch (opc){
			
			case 1:{
			  system("cls");
			  cout << "Digite el numero: ";
			  cin >> num;
			  agregarInicio(List,num);
			  cout << "Numero almacenado" <<endl;
			  system("pause");
			  break;
			}
			case 2:{
				system("cls");
			  cout << "Digite el numero: ";
			  cin >> num;
			  agregarFinal(List,num);
			  cout << "Numero almacenado" <<endl;
			  system("pause");
			  break;
			}
			case 3:{
				system("cls");
			  cout << "Digite el numero: ";
			  cin >> num;
			  agregarMedio(List,num);
			  cout << "Numero almacenado" <<endl;
			  system("pause");
			  break;
			}
			case 4:{
				system("cls");
			  cout << "Digite el numero a buscar: ";
			  cin >> num;
			  buscarUnNumero(List,num);
			  system("pause");
			  break;
			}
			case 5:{
				system("cls");
			  mostarLista(List);
			  system("pause");
			  break;
			}
		}
	}while(opc!=10);
}

int main(){
	menu();
}
