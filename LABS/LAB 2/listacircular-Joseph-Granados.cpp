#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;

//Se declara la estructura que vamos a utilizar para crear los nodos con sus data y puntero
struct Nodo{
	int numero;
	Nodo *sig;
	Nodo *prim;	
};
//Ac� es importante declarar este puntero en NULL para indicar que la lista est� vac�a y tiene que empezar en la primera posici�n.
Nodo *lista=NULL;

//M�todo utilizado para meter datos a la lista
void insertarLista (Nodo *&lista, int num){
	//Se crea el nuevo nodo guardando memoria con el operador new y llamando a la estructura de arriba
	Nodo *nuevo_nodo= new Nodo();
	//Se indica la data que se quiere introducir en este nuevo nodo
	nuevo_nodo -> numero=num;
	//Se declara el puntero local aux igual a lista (en nulo) para especificar que tiene que apuntar a NULL y as� poder apuntar a la derecha  
	Nodo *aux1= lista;
	Nodo *aux2;
	Nodo *auxp;
	//Se comprueba si el puntero local y la lista son iguales
	if (lista==aux1){
		//Al ser iguales, significa que ambos est�n en NULL y est� vac�a por lo que lista ahora tiene que moverse a la posici�n en la que est� el nuevo nodo (al inicio o final del nodo)
		lista= nuevo_nodo;
		auxp=lista;
	}
	else{
		//Si no entr� en la primera condici�n significa que la lista tiene m�s de un elemento por lo que este segundo puntero tiene que saber d�nde est� el mismo
		aux2->sig= nuevo_nodo;
	}
	//Se tiene que indicar la siguiente posici�n del nuevo_nodo que evidentemente tiene que apuntar a NULL a ser el �ltimo en ser agregado
	nuevo_nodo -> sig= aux1;
	cout << num << " ha sido agregado correctamente" << endl;
	cout << " " << endl;
}
	

void mostrarLista(Nodo *lista){
	//Se declara un puntero local para saber d�nde estamos posicionados
	Nodo *actual= new Nodo();
	//Al igualarse con lista, significa que va a estar apuntando al primer nodo de la lista
	actual= lista;
	//Siempre y cuando actual sea diferente a NULL, es decir, al �ltimo no va a entrar al while
	while(actual != NULL){
		//Ac� simplemente se imprime el n�mero que tiene almacenado en la posici�n actual
		cout << actual -> numero << " - - - > ";
		//Se le dice actual que se mueva a la posici�n siguiente (�l mismo+sig)
		actual=actual ->sig;
	}
	
}



int main (){
    Nodo *lista= NULL;
    int num;
    cout << "INGRESE NUM"<<endl;
    cin>> num;
	insertarLista(lista,num);
	 int num0;
    cout << "INGRESE NUM"<<endl;
    cin>> num0;
	insertarLista(lista,num0);
	 int num2;
    cout << "INGRESE NUM"<<endl;
    cin>> num2;
	insertarLista(lista,num2);
	mostrarLista(lista);

}





















/*system("cls");
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
		cin >> opc;*/
