# include <iostream>
# include <conio.h>
using namespace std;

int main (){
	//PUNTERO A VAR
	/*int a,*aa;
	a=20;
	aa= &a;
	cout << a << *aa;*/
	
	//PUNTERO A ARRAY
	/*
	int i=0;
	int num [] = {1,2,3,4};
	int *dir;
	dir= num;
	
	while (i<4){
		cout << "P " << i << *dir++ << endl;
		i++;
	}*/
	
	
	int numeros [10], *dir;
	int j=0;
	
	for (int i=0; i< 10; i++){
		cout <<" NUM" << i;
		cin >> numeros [i];
	}
	dir = numeros;
	
	while (j<10){
		
		if (*dir % 2== 0){
			cout << " PAR " << *dir;
		}
		else{
			cout << " IMPAR " << *dir;
		}
		
		*dir++;
		j++;
	}
	
}
