#include<iostream>
#include<conio.h>
using namespace std;

void imprimirDesordenado(int size, int array[]){
	int i=0;
	int *puntero;
    while (i< size){
    	puntero=&i;
    	cout<< array[i] << endl;
    	i++;
	}	
}

void ordenarAscendente (int *puntero, int array[]){
	
}

int main(){
	int num;
	cout<<"DIGITE TAMANIO DEL ARRAY: "<< endl;
	cin >> num;
	int array[num];
	int i=0;
	while (i < num){
		int num2;
		cout<<"INGRESE NUM TO THE ARRAY"<< endl;
		cin>>num2;
		array[num2];
		i++;
	}
	int size= sizeof(array)/sizeof(array[i]);
	imprimirDesordenado(size,array);
}



