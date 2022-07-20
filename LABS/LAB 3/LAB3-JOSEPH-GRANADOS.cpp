/*Ingresar las letras de la A a la Z
Un método que borre una palabra de la lista.
Un método que cuente cuantas palabras hay por letras.
Realizar un menú que realice lo siguiente:
Ingresar palabras.
Borrar Palabras.
Contar cantidad de letras por palabra.
Salir*/


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

void BorrarPalabraLista (lista &cab, string pal){
		lista aux;
		aux= cab;
		nodoPalabra *aux1;
			while(aux!=NULL){
				if(aux->letra==toupper(pal[0]))
				{
						aux1=aux->pal;
						if (aux1->palabra==pal){
						cout << aux1->palabra <<" REMOVIDO " << endl;
						cout<< " " << endl;
						delete aux1;
						aux1->sig=NULL;
						}
						else {
							aux1=aux1->sig;
						}
				}
				else{
					aux=aux->sig;
				}
	}
}

void ContarPalabrasPorLetra (lista &cab,char let){
		lista aux;
		aux= cab;
		nodoPalabra *aux1;
		int contador;
			while(aux!=NULL){
				if(aux->letra==let){
					aux1=aux->pal;
					while (aux1->sig==NULL){
						aux1=aux1->sig;
						contador=contador+1;
					}
				}
				else{
					cout<<"No hay palabras para esas letras";
					aux=aux->sig;
				}
				
				}
		cout<< "La letra: " << aux->letra << " contiene " << contador << " letras "<< endl;
}



void menu()
{
	lista Lista=NULL;
	int opc;
	string palabraInsertar;
	string palabraBorrar;
	char letra;
	char letraToFind;
	
	do
	{   system("cls");
		cout <<"-----MENU PRINCIPAL------"<<endl;
		cout <<"1. Agregar Letra Manual"<<endl;
		cout <<"2. Agregar Palabra"<<endl;
		cout <<"3. Mostrar"<<endl;
		cout <<"4. Borrar una palabra de la lista."<<endl;
		cout <<"5. Contar palabras por letras."<<endl;
		cout <<"6. Agregar letras de la A-Z"<<endl;
		cin >> opc;
		switch (opc)
		{
			case 1:
			       {
				   cout << "Digite la letra: ";
				   cin >> letra;
				   toupper(letra);
				   AgregarLetra(Lista,letra);
				   cout << "Letra almacenada" <<endl;
				   system("pause");
				   break;
				   }
			case 2:
			       {
				   cout << "Digite la palabra: ";
				   cin >> palabraInsertar;
				   AgregarPalabra(Lista,palabraInsertar);
				   cout << "Palabra almacenada" <<endl;
				   system("pause");
				   break;
				   }	   
			case 3:
			       {
				   Mostrar(Lista);
				   system("pause");
				   break;
				   }
			case 4:
			       {
			       cout<<"Digite la palabra que desea eliminar"<< endl;
			       cin>>palabraBorrar;
				   BorrarPalabraLista(Lista,palabraBorrar);
				   cout << "Palabra Eliminada" <<endl;
				   system("pause");
				   break;
				   }
		    case 5:
			       {
			       cout << "Digite la letra en la que quiere revisar el #"<< endl;
			       cin >> letraToFind;
			       ContarPalabrasPorLetra(Lista,letraToFind);
				   system("pause");
				   break;
				   }
				   
		    case 6:
			       {
					AgregarLetra(Lista,'A');
					AgregarLetra(Lista,'B');
					AgregarLetra(Lista,'C');
					AgregarLetra(Lista,'D'); 
					AgregarLetra(Lista,'E');
					AgregarLetra(Lista,'F');
					AgregarLetra(Lista,'G');
					AgregarLetra(Lista,'H'); 
				    AgregarLetra(Lista,'I');
					AgregarLetra(Lista,'J');
					AgregarLetra(Lista,'K');
					AgregarLetra(Lista,'L'); 
					AgregarLetra(Lista,'M');
					AgregarLetra(Lista,'N');
					AgregarLetra(Lista,'O');
					AgregarLetra(Lista,'P'); 
					AgregarLetra(Lista,'Q');
					AgregarLetra(Lista,'R');
					AgregarLetra(Lista,'S');
					AgregarLetra(Lista,'T'); 
					AgregarLetra(Lista,'U');
					AgregarLetra(Lista,'V');
					AgregarLetra(Lista,'W');
					AgregarLetra(Lista,'X'); 
					AgregarLetra(Lista,'Y');
					AgregarLetra(Lista,'Z');
					cout << "LETRAS AGREGADAS" << endl;
				    system("pause");
				   break;
				   }		   	   
			
		}		
	}
	while(opc!=7);
}


int main()
{
	menu();
}

/*
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
*/

