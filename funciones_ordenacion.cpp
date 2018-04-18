
#include<iostream>
#include<vector>
#include<stdio.h>
#include"dni.hpp"


using namespace std;
/** VARIABLES GLOBALES */




template<class D>
/**insercion*/
  void insertar(vector<D>& sec,bool verbose){
   int i,  j;
   D x;

   for (i = 1; i < sec.size(); i++){
       x = sec[i];
       j = i-1;
       if(verbose){
		   cin.ignore();
		   cout<<"El elemento a ordenar es la posición "<<i+1<<" el elemento "<<x<<endl;;
	   }

       while (j >= 0 &&  x < sec[j])
       {
           sec[j+1] = sec[j];
           j = j-1;
       }
       sec[j+1] = x;
       if(verbose){
    	   cout<<"El elemento "<<x<<" ha sido colocado en la posición "<<i+1<<endl;
		   /*for (int k=0;j<sec.size();k++){
			   cout<<sec[k]<<" ";
		   }
		   cout<<endl;*/
       }
   }
  }


/**Por Intercambio*/
template<class T>
  void burbuja(vector<T>& sec, bool verbose){
    bool flag=false;
    for (int i = 1; i < sec.size() && (flag==false); i++){
      flag=true;
      int j=0;
      for (j = sec.size()-1; j >= i ; j--){//las pasadas
        if (sec[j] < sec[j-1] ){

          flag=false;
          T x = sec[j-1] ;
          sec[j-1] = sec[j] ;
          sec[j] = x ;

        }

      }
      if(verbose==true){
		cout<<"Insertando el elemento burbuja "<<sec[j]<<endl;
		for(int k=0;k<sec.size();k++){
		  cout<<" ";
		  cout<<sec[k];
		}
		cout<<endl;
      }
    }
  }

/** HEAPSORT*/

template<class H>

  void heapSort(vector<H>& sec, bool verbose){
	int n=sec.size();
    H x;
    for (int i = (n-1)/2; i >= 0; i--){
      baja(i, sec, n);
    }
    for (int i = (n-1); i >= 1; i--){
      x = sec[0] ;
      sec[0] = sec[i] ;
      sec[i] = x ;
      baja(0,sec,i-1) ;
    }
  }
template<class H>
  void baja( int i , vector<H>& sec, int n){
    H x = sec[i] ;
    int h;
    while ( ((2*i)+1) < n){
      int h1 = ((2*i)+1);
      int h2 = h1 + 1 ;
      if (h1 == n){
         h = h2;
      }
      else if (sec[h2] < sec[h1]){
        h = h1;
      }
      else h = h2 ;
      if (sec[h] <= x){
        break ;
      }
      else{
        sec[i] = sec[h];
        sec[h] = x ;
        i = h;
      }
    }
  }

  template<class H>

    void Swap(H& a, H& b){
      H aux;
      aux= a;
      a=b;
      b=aux;
    }

  template<class E>

  void Qsort( vector<E>& sec, int ini, int fin){
    int i = ini , f = fin ;
    E p = sec[(i+f)/2] ;
    while (i <= f){
      while (sec[i] < p) i++ ;
      while (sec[f] > p) f-- ;
      if (i <= f){
        E x = sec[i] ;
        sec[i] = sec[f] ;
        sec[f] = x ;
        i++ ; f-- ;
      } ;
    } ;
    if (ini < f) Qsort(sec, ini, f) ;
    if (i < fin) Qsort(sec, i, fin) ;
  }

  template<class E>

  void Quicksort(vector<E>& sec, bool verbose){
	  Qsort(sec,0,sec.size()-1);
	  
  }
