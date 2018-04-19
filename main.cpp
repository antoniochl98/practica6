#include <stdio.h>
#include <iostream>
#include <vector>
#include "dni.hpp"
#include "funciones_ordenacion.cpp"
#define N_METHOD 5

using namespace std;


const string METHOD[N_METHOD]={"insertar", "burbuja", "heapSort", "Quicksort","shellsort" };

typedef void (*opera_ptr)(vector <Dni>& ,bool);

int main (void){
	extern int contador;
	extern float const_reduc;
	srand(time(NULL));
	bool verbose=true;
	int opcion,N,nPruebas=1;
	opera_ptr opera_array[N_METHOD];

	opera_array[0]=insertar<Dni>;
	opera_array[1]=burbuja<Dni>;
	opera_array[2]=heapSort<Dni>;
	opera_array[3]=Quicksort<Dni>;
	opera_array[4]=shell<Dni>;








	cout<<"1.Modo demostración"<<endl<<"2.Modo estadística"<<endl;
	cin>>opcion;
	if(opcion==2){
		verbose=false;
	}
	if(verbose){
		cout<<"demostración"<<endl;
	}
	else{
		cout<<"estadística"<<endl;
	}
	cout<<"Introduzca la cantidad de elementos a ordenar: ";
	cin>>N;


	vector<bool> metodo(5,false);//inserción,burbuja,heap,quick,shell
	if(verbose){
		cout<<"Elige el método a desarrollar:"<<endl<<"1.Inserción 2.Método de la burbuja 3.Heapsort 4.Quicksort 5.Shellsort"<<endl;
		cin>> opcion;
		metodo[opcion-1]=true;
	}
	else{
		cout<<"Introduce el nº de pruebas a desarrollar:"<<endl;
		cin>>nPruebas;
		for(int i=0;i<metodo.size();i++){
			metodo[i]=true;
		}

	}
	if(!verbose || opcion==4){
		cout<<"Elige la constante de reducción para el shellsort(entre 0 y 1): ";
		cin>>const_reduc;
	}

	vector<Dni> banco_pruebas;


	for(int i=0;i<(N*nPruebas);i++){
		Dni dni;
		banco_pruebas.push_back(dni);
	}















	if(!verbose){
		cout<<"				Nº de comparaciones"<<endl<<"		Mínimo	Medio	Máximo"<<endl;
	}
	int min,max;
	float med=0;


	for(int k=0; k<N_METHOD; k++){
		if (metodo[k]){
			med=0;
			for(int i=0;i<nPruebas;i++){
				vector<Dni> ordenar;
				contador=0;
				for (int j=0;j<N;j++){
					ordenar.push_back(banco_pruebas[rand()%(N*nPruebas)]);

				}

				if(verbose){
					cout<<"El vector a ordenar es:"<<endl;
					for (int j=0;j<N;j++){
						cout<<ordenar[j]<<" ";
					}
					cout<<endl;
				}
				opera_array[k] (ordenar,verbose);
				if(verbose){
					cout<<"El vector ordenado:"<<endl;
					for (int j=0;j<N;j++){
						cout<<ordenar[j]<<" ";
					}
					cout<<endl;
				}

				if(i==0){
					min=contador;
					max=contador;
				}
				else{
					if(min>contador){
						min=contador;
					}
					else if(max<contador){
						max=contador;
					}
				}
				med+=(contador/nPruebas);
			}
			if(!verbose){
				cout<<endl;
				cout<<METHOD[k]<<"	"<<min<<"	"<<med<<"	"<<max<<" ";
				cout<<endl;
			}
		}
	}

	cout<<"adiós"<<endl;


}
