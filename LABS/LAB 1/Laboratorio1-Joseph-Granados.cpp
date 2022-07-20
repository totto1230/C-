#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;

//Se declara la estructura que vamos a utilizar para crear los nodos con sus data y puntero
struct Nodo{
	int numero;
	Nodo *sig;	
};

//Acá es importante declarar este puntero en NULL para indicar que la lista está vacía y tiene que empezar en la primera posición.
Nodo *lista=NULL;

//Método utilizado para meter datos a la lista
void insertarLista (Nodo *&lista, int num){
	//Se crea el nuevo nodo guardando memoria con el operador new y llamando a la estructura de arriba
	Nodo *nuevo_nodo= new Nodo();
	//Se indica la data que se quiere introducir en este nuevo nodo
	nuevo_nodo -> numero=num;
	//Se declara el puntero local aux igual a lista (en nulo) para especificar que tiene que apuntar a NULL y así poder apuntar a la derecha  
	Nodo *aux1= lista;
	Nodo *aux2;
	//Se comprueba si el puntero local y la lista son iguales
	if (lista==aux1){
		//Al ser iguales, significa que ambos están en NULL y está vacía por lo que lista ahora tiene que moverse a la posición en la que está el nuevo nodo (al inicio o final del nodo)
		lista= nuevo_nodo;
	}
	else{
		//Si no entró en la primera condición significa que la lista tiene más de un elemento por lo que este segundo puntero tiene que saber dónde está el mismo
		aux2->sig= nuevo_nodo;
	}
	//Se tiene que indicar la siguiente posición del nuevo_nodo que evidentemente tiene que apuntar a NULL a ser el último en ser agregado
	nuevo_nodo -> sig= aux1;
	cout << num << " ha sido agregado correctamente" << endl;
	cout << " " << endl;
}

//Método utilizado para ver los datos de la lista
void mostrarLista(Nodo *lista){
	//Se declara un puntero local para saber dónde estamos posicionados
	Nodo *actual= new Nodo();
	//Al igualarse con lista, significa que va a estar apuntando al primer nodo de la lista
	actual= lista;
	//Siempre y cuando actual sea diferente a NULL, es decir, al último no va a entrar al while
	while(actual != NULL){
		//Acá simplemente se imprime el número que tiene almacenado en la posición actual
		cout << actual -> numero << " - - - > ";
		//Se le dice actual que se mueva a la posición siguiente (él mismo+sig)
		actual=actual ->sig;
	}
	
}

//Método utilizado para eliminar el primer nodo
void eliminarInicio(Nodo *&lista, int n){
	//Se verifica que la lista no esté vacía revisando el puntero "lista"
	if (lista!=NULL){
		//Se declaran dos punteros locales
		Nodo *aux_delete;
		Nodo *prev= NULL;
		//Al igualarse el aux_delete nodo con lista nos permite posicionarnos en el primer nodo
		aux_delete= lista;
		
		if (prev == NULL){
			//El punter local va a ser eliminado (y el nodo) por lo que es necesario mover el puntero lista una posición hacia la derecha porque de lo contrario quería en NULL
			lista= lista -> sig;
			cout<< " " << endl;
			cout << n <<" REMOVIDO " << endl;
			cout<< " " << endl;
			delete aux_delete;
		}
		
	}
	
	else {
		cout << "LISTA VACIA" << endl;
	}	
}

//Método utilizado para eliminar el último nodo
void eliminarFinal(Nodo *&lista, int n){
	//Primero de todo se verifica si la lista no está vacía comprobando que el puntero lista esté apuntando a otra cosa que no sea NULL (otro nodo)
	if (lista!=NULL){
		//Se declara un puntero locales y se iguala con lista para posicionarnos en el primer nodo
		Nodo *aux_delete;
		aux_delete= lista;
		
		//Se verifica que el siguiente no sea NULL, al hacerlo de esta manera nos posicionamos en el penúltimo nodo y podemos indicarle
		while ((aux_delete->sig) -> sig != NULL){
			//Se le dice actual que se mueva a la posición siguiente (él mismo+sig)
			aux_delete=	aux_delete->sig;
		}
		cout<< " " << endl;
		cout << aux_delete->numero <<" REMOVIDO " << endl;
		cout<< " " << endl;
		delete aux_delete;
		aux_delete->sig=NULL;
		
	}
	
	else {
		cout << "LISTA VACIA" << endl;
	}	
	
	
}

//Método utilizado para buscar un número en la lista
void buscarNum(Nodo *&lista, int n){
	//Primero de todo se verifica si la lista no está vacía comprobando que el puntero lista esté apuntando a otra cosa que no sea NULL (otro nodo)
	if (lista!=NULL){
		//Se declara un entero el cual va a contar las n veces que aparece el número específicado
		int cuenta=0;
		//Se declara un puntero locales y se iguala con lista para posicionarnos en el primer nodo
		Nodo *aux= lista;
		//Siempre y cuando este aux no sea NULL va a recorrer la lista, es decir, va a empezar en lista hasta el último nodo
		while (aux!=NULL){
			//Mientras recoge la lista va a verificar si el número en esa dirección de memoria es el mismo del digitado por el usuario
			if (aux->numero==n){
				//Si es el caso, suma uno a la variable declarada anteriormente
				cuenta=cuenta+1;
			}
			//Se le dice al aux que se mueva a la posición siguiente (él mismo+sig)
			aux= aux -> sig;	
			}
		
		//Se revisa el valor de la variable cuenta para darle la info al user
		if (cuenta>=1){
			cout << n << " se encuentra en la lista " << cuenta << " veces " << endl;
		}	
		else{
			cout << n <<" no esta " << endl;
		}
	}
	else {
		cout << "LISTA VACIA" << endl;
	}	
}

//Método utilizado para calcular el promedio de una lista
void calcularPromedio(Nodo *&lista){
	//Primero de todo se verifica si la lista no está vacía comprobando que el puntero lista esté apuntando a otra cosa que no sea NULL (otro nodo)
	if (lista != NULL){
		//Se declara un puntero locales y se iguala con lista para posicionarnos en el primer nodo
		Nodo *actual=lista;
		//Se declaran varios ints locales para almacenar los valores en los punteros 
		int cant, prom;
		int sum=0;
		//Siempre y cuando este aux no sea NULL va a recorrer la lista, es decir, va a empezar en lista hasta el último nodo
		while (actual!=NULL){
			//Almacena el valor que existe en la dirección actual
			sum= sum+ actual->numero;
			cant=cant+1;
			//Se le dice al aux que se mueva a la posición siguiente (él mismo+sig)
			actual=actual->sig;
		}	
		prom= (sum)/cant;
		cout<< " " << endl;
		cout << "El promedio es: " << prom << endl;
		cout<< " " << endl;
	}
	
	else{
		cout<< "LISTA VACIA" << endl;
		
	}
	
}

//Método utilizado para crear un menú interactivo
void menu(){
	int opc,num,num2;
	
	do
	{   system("cls");
		cout <<"MENU PRINCIPAL" <<endl;
		cout <<"1. Ingresar DATOS " <<endl;
		cout <<"2. Mostrar DATOS " <<endl;
		cout <<"3. Eliminar el dato del Inicio" <<endl;
		cout <<"4. Eliminar el dato del Final" <<endl;
		cout <<"5. Buscar numero, ver si está en la lista y cuántas veces aparece" <<endl;
		cout <<"6. Promedio de datos" <<endl;
		cout <<"7. Ordenar de menor a mayor" <<endl;
		cout <<"8. Salir" <<endl;
		cout <<"La opcion seleccionada es: ";
		cin >> opc;
		switch(opc)
		{
			case 1: 
			{
			cout<< "Digite el num: " << endl;
			cout<< " " << endl;
			cin >> num;
			cout<< " " << endl;
			insertarLista(lista,num);	
			system("pause");
			break;
			}
			case 2: {
			mostrarLista(lista);
			system("pause");	
			break;
			} 
			case 3: {
			eliminarInicio(lista,num);	
			system("pause");
			break;
			} 
			case 4: {
			eliminarFinal(lista,num);	
			system("pause");
			break;
			} 
			case 5: {
			cout << "Cual numero quiere buscar?" << endl;
			buscarNum(lista,num2);	
			system("pause");
			break;
			} 
			case 6: {
			calcularPromedio(lista);	
			system("pause");
			break;
			} 
			case 7: {
			ordenarMenor(lista);	
			system("pause");
			break;
			} 
			
		}	
		system("cls");
} while(opc !=8);
}

int main (){
    
	menu();

}


