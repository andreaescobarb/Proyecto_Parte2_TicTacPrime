#include "Tictac.h"

Tictac::Tictac(){

}

Tictac::Tictac(int size){
  this->size=size;
  int** mat;
  mat=crearMat();
}

void Tictac::setNumero(int size){
  this->size=size;
}

int Tictac::getNumero(){
  return size;
}

int** Tictac::crearMat(){
	int** mat = new int *[size];
	for (int i = 0; i < size; ++i){
		mat[i]=new int[size];
	}
	return mat;
}

int** Tictac::getMat(){
  return mat;
}

void Tictac::setMat(int** mat){
  this->mat=mat;
}

Tictac::~Tictac(){
  cout<<"La matriz ha sido eliminada exitosamente!"<<endl;
}
