/*
 * funciones_ordenacion.hpp
 *
 *  Created on: 19/04/2018
 *      Author: antonio
 */

#include<iostream>
#include<vector>
#include<stdio.h>
#include"dni.hpp"

template<class T>
/**insercion*/
  void insertar(vector<T>& ordena,bool verbose);
template<class T>
  void burbuja(vector<T>& ordena, bool verbose);
template<class H>
  void heapSort(vector<H>& ordena, bool verbose);
template<class T>
  void baja( int i , vector<T>& ordena, int n);
template<class T>
    void Swap(T& a, T& b);
template<class T>
  void Qsort( vector<T>& ordena, int ini, int fin);
template<class T>
  void Quicksort(vector<T>& ordena, bool verbose);
template<class T>
     void shell(vector<T>& ordena, bool verbose);
template<class T>
     void shellsort(int d , vector<T>& ordena);

