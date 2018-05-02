/*
 * node.h
 *
 *  Created on: 12/02/2018
 *      Author: antonio
 */

#pragma once
#ifndef NODE_H_
#define NODE_H_
#include <cassert>
#include <cstdio>
#include <iostream>


template<class TDATO>
class node {
	TDATO data_;
	node<TDATO>* right_;
	node<TDATO>* left_;
	node<TDATO>* father_;
public:
	node();
	node(TDATO data);
	node(TDATO data,node<TDATO>* right,node<TDATO>* left);
	node(const node<TDATO>& a);
	virtual ~node();
	void set_data(TDATO data);
	void set_right(node<TDATO>* right);
	void set_left(node<TDATO>* left);
	void set_father(node<TDATO>* father);
	TDATO get_data();
	node<TDATO>* get_right();
	node<TDATO>* get_left();
	node<TDATO>* get_father();
};

template<class TDATO>
node<TDATO>::node():
data_(),
right_(NULL),
left_(NULL),
father_(NULL){}

template<class TDATO>
node<TDATO>::node(TDATO data):
data_(data),
right_(NULL),
left_(NULL),
father_(NULL){}

template<class TDATO>
node<TDATO>::node(TDATO data,node<TDATO>* right,node<TDATO>* left):
data_(data),
right_(right),
left_(left),
father_(NULL){}

template<class TDATO>
node<TDATO>::node(const node<TDATO>& a):
data_(a.data_),
right_(NULL),
left_(NULL),
father_(NULL){}

template<class TDATO>
node<TDATO>::~node() {
	right_=NULL;
	left_=NULL;
	father_=NULL;
}

template<class TDATO>
void node<TDATO>::set_data(TDATO data){
	data_=data;
}

template<class TDATO>
void node<TDATO>::set_right(node<TDATO>* right){
	right_=right;
}

template<class TDATO>
void node<TDATO>::set_left(node<TDATO>* left){
	left_=left;
}

template<class TDATO>
void node<TDATO>::set_father(node<TDATO>* father){
	father_=father;
}

template<class TDATO>
TDATO node<TDATO>::get_data(){
	return data_;
}

template<class TDATO>
node<TDATO>* node<TDATO>::get_right(){
	return right_;
}

template<class TDATO>
node<TDATO>* node<TDATO>::get_left(){
	return left_;
}

template<class TDATO>
node<TDATO>* node<TDATO>::get_father(){
	return father_;
}


#endif /* NODE_H_ */
