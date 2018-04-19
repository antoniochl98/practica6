
#include"funciones_ordenacion.hpp"

extern float const_reduc;

using namespace std;

template<class T>
/**insercion*/
  void insertar(vector<T>& ordena,bool verbose){
   int i,  j;
   T x;

   for (i = 1; i < ordena.size(); i++){
       x = ordena[i];
       j = i-1;
       if(verbose){
		   cin.ignore();
		   cout<<"El elemento a ordenar es la posición "<<i+1<<" el elemento "<<x<<endl;;
	   }

       while (j >= 0 &&  x < ordena[j])
       {
           ordena[j+1] = ordena[j];
           j = j-1;
       }
       ordena[j+1] = x;
       if(verbose){
    	   cout<<"El elemento "<<x<<" ha sido colocado en la posición "<<i+1<<endl;

       }
   }
  }


/**Por Intercambio*/
template<class T>
  void burbuja(vector<T>& ordena, bool verbose){
    bool no_cambio=false;
    for (int i = 1; i < ordena.size() && (no_cambio==false); i++){
      no_cambio=true;
      int j=0;
      for (j = ordena.size()-1; j >= i ; j--){
        if (ordena[j] < ordena[j-1] ){

          no_cambio=false;
          T x = ordena[j-1] ;
          ordena[j-1] = ordena[j] ;
          ordena[j] = x ;

        }

      }
      if(verbose==true){
		cout<<"Insertando el elemento burbuja "<<ordena[j]<<endl;
		for(int k=0;k<ordena.size();k++){
		  cout<<" ";
		  cout<<ordena[k];
		}
		cout<<endl;
      }
    }
  }

/** HEAPSORT*/

template<class H>

  void heapSort(vector<H>& ordena, bool verbose){
	int n=ordena.size();
    H x;
    for (int i = (n-1)/2; i >= 0; i--){
      baja(i, ordena, n);
    }
    for (int i = (n-1); i >= 1; i--){
      x = ordena[0] ;
      ordena[0] = ordena[i] ;
      ordena[i] = x ;
      baja(0,ordena,i-1) ;
    }
  }
template<class T>
  void baja( int i , vector<T>& ordena, int n){
    T x = ordena[i] ;
    int h;
    while ( ((2*i)+1) < n){
      int h1 = ((2*i)+1);
      int h2 = h1 + 1 ;
      if (h1 == n-1){
         h = h1;
      }
      else if (ordena[h2] < ordena[h1]){
        h = h1;
      }
      else h = h2 ;
      if (ordena[h] <= x){
        break ;
      }
      else{
        ordena[i] = ordena[h];
        ordena[h] = x ;
        i = h;
      }
    }
  }

  template<class T>
    void Swap(T& a, T& b){
      T aux;
      aux= a;
      a=b;
      b=aux;
    }

  template<class T>

  void Qsort( vector<T>& ordena, int ini, int fin){
    int i = ini , f = fin ;
    T p = ordena[(i+f)/2] ;
    while (i <= f){
      while (ordena[i] < p) i++ ;
      while (ordena[f] > p) f-- ;
      if (i <= f){
        T x = ordena[i] ;
        ordena[i] = ordena[f] ;
        ordena[f] = x ;
        i++ ; f-- ;
      } ;
    } ;
    if (ini < f) Qsort(ordena, ini, f) ;
    if (i < fin) Qsort(ordena, i, fin) ;
  }

  template<class T>

  void Quicksort(vector<T>& ordena, bool verbose){
	  Qsort(ordena,0,ordena.size()-1);
  }


  template<class T>

     void shell(vector<T>& ordena,bool verbose){
         int del = ordena.size();
         while (del > 1){
             del = del * const_reduc;
             shellsort(del,ordena) ;
         }
     }
   template<class T>
     void shellsort(int d , vector<T>& ordena){
         T x;
         int j;
         for (int i = d + 1; i <= ordena.size(); i++){
             x = ordena[i] ;
             j = i ;
             while ((j > d) && (x < ordena[j-d])){
                 ordena[j] = ordena[j-d] ;
                 j = j - d ;
             }
             ordena[j] = x ;
         }
     }
