/*
* arbol.h
*
*  Created on: 27/04/2018
*      Author: antonio
*/


#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;

#include "node.h"



template <class T>
class ABB {
private:
	node<T>* head_;

public:
	ABB();
	void insert(T data);
	node<T>* search(T data);
	void remove(T data);
	ostream& write(ostream& os=std::cout);
private:
	void remove_node(node<T>*,node<T>*);
	ostream& showTree(node<T>*, int n, ostream&);
};

template <class T>
ABB<T>::ABB():
head_(NULL){};

template <class T>
void ABB<T>::insert(T data){
	if(search(data)==NULL){
		bool inserted=false;
		node<T>* aux=head_;
		if(head_==NULL){
			head_=new node<T>(data);
		}
		else{
			while(!inserted){
				if(data<aux->get_data()){
					if(aux->get_left()!=NULL){
						aux=aux->get_left();
					}
					else{
						aux->set_left(new node<T>(data));
						aux->get_left()->set_father(aux);
						inserted=true;
					}
				}

				else if(data>aux->get_data()){
					if(aux->get_right()!=NULL){
						aux=aux->get_right();
					}
					else{
						aux->set_right(new node<T>(data));
						aux->get_right()->set_father(aux);
						inserted=true;
					}
				}
			}
		}
	}
}

template <class T>
node<T>* ABB<T>::search(T data){
	node<T>* aux=head_;
	bool encontrado=false;
	while(aux!=NULL && !encontrado){
		if(aux->get_data()==data){
			encontrado=true;
		}
		else{
			if(aux->get_data()<data){
				aux=aux->get_right();
			}
			else{
				aux=aux->get_left();
			}
		}
	}
	return aux;
}

template <class T>
void ABB<T>::remove(T data){
	node<T>* removing=search(data);
	if(removing->get_left()!=NULL && removing->get_right()!=NULL){
		node<T>* aux=removing->get_left();
		while(aux->get_right()!=NULL){
			aux=aux->get_right();
		}
		removing->set_data(aux->get_data());
		removing=aux;
	}
	if(removing->get_left()!=NULL){
		remove_node(removing,removing->get_left());
	}
	else{
		remove_node(removing,removing->get_right());
	}
	if(removing==head_)
		head_=NULL;
	removing->set_father(NULL);
	removing->set_left(NULL);
	removing->set_right(NULL);
	delete removing;

}

template<class T>
ostream& ABB<T>::write(ostream& os){
	showTree(head_,0,os);
	return os;
}

template <class T>
ostream& ABB<T>::showTree(node<T>* actual_node, int n, ostream& os)
{
     if(actual_node==NULL){
    	 for(int i=0; i<n; i++)
    	          cout<<"   ";
    	 cout<<"[.]"<<endl;
    	 return os;
     }
     showTree(actual_node->get_right(), n+1, os);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<<"["<<actual_node->get_data()<<"]"<<endl;

     showTree(actual_node->get_left(), n+1, os);

     return os;
}


template <class T>
void ABB<T>::remove_node(node<T>* removing, node<T>* n_son){
	if(removing->get_father()!=NULL){
		if(removing->get_father()->get_left()==removing){
			removing->get_father()->set_left(n_son);
		}
		else{
			removing->get_father()->set_right(n_son);
		}
	}
	if(n_son!=NULL){
		n_son->set_father(removing->get_father());
	}
}


