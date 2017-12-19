#ifndef TICTAC_H
#define TICTAC_H

#include <iostream>
#include <memory>
#include "memory"
#include "utility"
using namespace std;

class Tictac{
private:
  int size;
  int** mat;
public:
  Tictac();
  Tictac(int);
  void setNumero(int);
  int getNumero();
  int** crearMat();
  void setMat(int**);
  int** getMat();
  ~Tictac();
};
#endif
