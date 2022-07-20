#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
struct nodoProceso
{
	string nombre;
	int memoria;
	int pid;
	string estado;
	nodoProceso *sig;
	nodoProceso *ant;
};
typedef struct nodoProceso *lista;

nodoProceso *crearNodo(string n)
{
	nodoProceso *aux = new (struct nodoProceso);
	aux->nombre=n;
	aux->memoria=rand()%100;
	aux->pid=rand()%1000;
	aux->estado="activo";
	aux->sig=NULL;
	aux->ant=NULL;
	return aux;
}

nodoProceso *crearNodoR(string nom,int mem,int pid,string est)
{
	nodoProceso *aux = new (struct nodoProceso);
	aux->nombre=nom;
	aux->memoria=mem;
	aux->pid=pid;
	aux->estado=est;
	aux->sig=NULL;
	aux->ant=NULL;
	return aux;
}

void Poner(lista &cab,string nombre)
{	lista aux;
	nodoProceso *nuevo;
	
	nuevo=crearNodo(nombre);
	
	if(cab==NULL)
	cab=nuevo;
	else
	{
		aux=cab;
		while(aux->sig!=NULL)
		aux=aux->sig;
		
		aux->sig=nuevo;	
		nuevo->ant=aux;
	}
}

void PonerRestriccion(lista &cab, string nom,int mem,int pid,string est)
{
	nodoProceso *nuevo;
	
	nuevo=crearNodoR(nom,mem,pid,est);
	
	if(cab==NULL)
	cab=nuevo;
	else
	{
		nuevo->sig=cab;
		cab->ant=nuevo;
		cab=nuevo;
	}
}

nodoProceso *Sacar(lista &cab)
{
	nodoProceso *temp;
	lista aux;

	if(cab==NULL)
	return NULL;
	else
	{
		aux=cab;
		temp = new (struct nodoProceso);
		temp->nombre=aux->nombre;
		temp->memoria=aux->memoria;
		temp->estado="inactivo";
		temp->pid=aux->pid;
		cab=aux->sig;
		aux->sig=NULL;
		delete(aux);
	}
	return temp;
}

void mostrar(lista &cab)
{
	lista aux;
	
	if(cab==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cab;
		while(aux!=NULL)
		{
			cout << "Proceso: " <<aux->nombre <<endl;
			cout << "PID: " <<aux->pid <<endl;
			cout << "MEMORIA: " <<aux->memoria <<"MB" <<endl;
			cout << "ESTADO: " <<aux->estado <<endl;
			cout << "***********************"<<endl;
			aux=aux->sig;
		}
	}
}

void procesoMayor(lista &cab){
	
	lista aux;
	int mayor;
	string name;
	mayor=cab->memoria;
	aux=cab;

	while(aux!=NULL){
		if(aux->memoria>mayor){
			mayor= aux->memoria;
			name= aux->nombre;
		}
	aux= aux->sig;		
	}
	cout <<"El proceso con mayor memoria es: " << name << " con " << mayor << " MB" << endl;		
}

void procesoMenor(lista &cab){
	
	lista aux;
	int menor;
	string name;
	menor=cab->memoria;
	aux=cab;

	while(aux!=NULL){
		if(aux->memoria<menor){
			menor= aux->memoria;
			name= aux->nombre;
		}
	aux= aux->sig;		
	}
	cout <<"El proceso con mayor memoria es: " << name << " con " << menor << " MB" << endl;		
}


void buscarPID(lista &cab, int pidd){
	lista aux;
	if(cab==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cab;
		while(aux!=NULL){
			if(aux->pid==pidd){
				cout << "Proceso: " <<aux->nombre <<endl;
				cout << "PID: " <<aux->pid <<endl;
				cout << "MEMORIA: " <<aux->memoria <<"MB" <<endl;
				cout << "ESTADO: " <<aux->estado <<endl;
				cout << "***********************"<<endl;
				aux=NULL;
			}
		aux= aux->sig;	
		}
		cout<<"NO HAY UN PROCESO CON ESE PID"<< endl;
	}
}


int main()
{
	lista Cola=NULL;
	lista ColaAtendidos=NULL;
	
	int opcion,pid;
	string nombre;
	nodoProceso *aux=NULL;
	
	
	do
	{	system("cls");
		system("color 0A");
		cout <<"------MENU PRINCIPAL-------"<<endl;
		cout <<"1. Ingresar Proceso"<<endl;
		cout <<"2. Antender Proceso"<<endl;
		cout <<"3. Verificar Procesos activos"<<endl;
		cout <<"4. Verificar Proceso inactivos"<<endl;
		cout <<"5. Verificar el proceso que consume mas memoria"<<endl;
		cout <<"6. Verificar el proceso que consume menos memoria"<<endl;
		cout <<"7. Buscar Proceso por PID"<<endl;
		cout <<"8. Salir"<<endl;
		cout <<"----------------------------"<<endl;
		cout <<"La opcion seleccionada es: ";
		cin >> opcion;
		
		switch(opcion)
		{
			case 1: {
				system("cls");
				cout <<"Digite el nombre del proceso:"<<endl;
				cin >> nombre;
				Poner(Cola,nombre);
				cout <<"Proceso creado"<<endl;
				system("Pause");
			}break;
			case 2: {
				aux=Sacar(Cola);
				system("cls");
				cout <<"--Proceso Atendido--"<<endl;
				cout <<"NOMBRE: "<< aux->nombre<<endl;
				cout <<"PID: "<< aux->pid<<endl;
				cout <<"MEMORIA: "<< aux->memoria <<"MB"<<endl;
				cout <<"ESTADO: "<< aux->estado<<endl;
				cout <<"----------------------"<<endl;
				system("Pause");
				PonerRestriccion(ColaAtendidos,aux->nombre,aux->memoria,aux->pid,aux->estado);
				
			}break;
			case 3: {
				system("cls");
				cout <<"----Lista de procesos activos----"<<endl;
				mostrar(Cola);
				system("Pause");
			}break;
			case 4: {
				system("cls");
				cout <<"----Lista de procesos inactivos----"<<endl;
				mostrar(ColaAtendidos);
				system("cls");
				
			}break;
			case 5: {
				system("cls");
				procesoMayor(Cola);
				system("Pause");
				system("cls");
			}break;
			case 6: {
				system("cls");
				procesoMenor(Cola);
				system("Pause");
				system("cls");
			}break;
			case 7: {
				system("cls");
				cout<<"INGRESE EL PID: " << endl;
				cin>>pid;
				buscarPID(Cola, pid);
				system("Pause");
				system("cls");
			}break;
		}		
	}
	while (opcion!=8);
	system("color 4F");
	cout <<"Fin del administrador de procesos"<<endl;	
}
