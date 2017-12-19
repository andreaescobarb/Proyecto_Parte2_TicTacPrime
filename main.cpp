#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include "Player.h"
#include "Tictac.h"
#include "memory"
#include "utility"
#include <cstdlib>
#include <fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

//void deleteMatrix(int**, int);
int** createMatrix(int);
void printMatrix(int**, int);
bool PrimeNum(int);
int menu();
//funciones para validar los numeros ingresados dentro de la matriz (si estan en el rango de 0-9)
int posX(int);
int posY(int);
int numeros();

int computedNumber2x2(int**, int, int);

//funcion para validar si la posicion que la persona ingreso esta disponible
bool position(int**, int, int, int);
string Player1();
string Player2();

//funciones para verificar si hay un numero primo de formas verticales, horizontales y diagonales
bool VerifyHorizontal1(int**, int, int, int);
bool VerifyHorizontal2(int**, int, int, int);
bool VerifyHorizontal3(int**, int, int, int);
bool VerifyVertical1(int**, int, int, int);
bool VerifyVertical2(int**, int, int, int);
bool VerifyVertical3(int**, int, int, int);
bool VerifyDiagonal1(int**, int, int, int);
bool VerifyDiagonal2(int**, int, int, int);
bool VerifyDiagonal3(int**, int, int, int);
bool VerifyDiagonalC1(int**, int, int, int);
bool VerifyDiagonalC2(int**, int, int, int);
bool VerifyDiagonalC3(int**, int, int, int);

bool lose(int**, int);//funcion que verifica en caso que nadie gane y la matriz este llena

//funciones que chequean las posiciones posibles disponibles para ingresar un numero
int compX(int**, int, int, int);
int compY(int**, int, int, int);

void wFile(vector<Player*>);//prototipo de funcion que escribe el archivo
vector<Player*> readFile(); //y esta funcion la lee y me retorna un vector del mismo tipo


int main(int argc, char const *argv[]) {
  vector<Player*> players=readFile();
  bool salir = true;
  cout<<"           TIC TAC PRIME"<<endl;
  cout<<"_______________________________________"<<endl;

  while(salir){
    switch (menu()) {
      case 1:{
        bool game = true;
        unique_ptr<Tictac> mat(new Tictac(2));
        mat->setMat(createMatrix(2));

        bool play =true;
        while (play) {
          cout<<"     OPCIONES"<<endl<<"1- Ingresar nuevo jugador"<<endl<<"2- Usar jugador existente"<<endl<<"3- Salir"<<endl;
          int opt;
          cin>>opt;
          while (opt<0||opt>3) {
            cout<<"Opcion invalida, intente de nuevo"<<endl;
          }
          switch (opt) {
            case 1:{
              string p1, p2;
              int s1, s2;
              break;
            }
            case 2:{
              string p1, p2;
              int s1, s2;
              break;
              if (player.size()==1) {
                cout<<"Jugador 1: "<<player.at(0)<<endl<<endl;
                cout<<"Ingrese nombre de nuevo jugador"<<endl;
                cin>>p1;
                players.push_back(new Player(p1, 0));
              }
              break;
            }
            case 3:{
              play=false;
              break;
            }
          }
        }

        while (game) {
          bool turno1=true;
          bool turno2=false;
          int number;
          int posx;
          int posy;
          while (turno1) {
            cout<<"Turno de Jugador 1:"<<p1<<endl;
            cout<<"_______________________________________"<<endl<<endl;
            printMatrix(mat->getMat(), 2);
            posx=posX(2);
            posy=posY(2);
            while (!position(mat->getMat(), posx, posy, 2)) {
              cout<<"Posicion invalida, intente de nuevo"<<endl;
              cout<<endl;
              posx=posX(2);
              posy=posY(2);
            }
            number=numeros();
            mat->getMat()[posx][posy] = number;

            if (VerifyHorizontal1(mat->getMat(), posx, posy, 2)||VerifyVertical1(mat->getMat(), posx, posy, 2)||VerifyDiagonal1(mat->getMat(), posx, posy, 2)||VerifyDiagonalC1(mat->getMat(), posx, posy, 2)) {
              printMatrix(mat->getMat(), 2);
              cout<<endl;
              cout<<"Felicidades!! Acabas de ganar el juego: "<<p1<<endl;
              cout<<endl;
              game = false;
              break;
            }
            if (lose(mat->getMat(), 2)) {
              cout<<"Lo siento, ambos jugadores perdieron"<<endl;
              game=false;
            }
            turno1 = false;
            turno2 = true;
          }
          while (turno2) {
            cout<<"Turno de Jugador 2:"<<p2<<endl;
            printMatrix(mat->getMat(), 2);
            posx=posX(2);
            posy=posY(2);
            while (!position(mat->getMat(), posx, posy, 2)) {
              cout<<"Posicion invalida, intente de nuevo"<<endl;
              cout<<endl;
              posx=posX(2);
              posy=posY(2);
            }
            number=numeros();
            mat->getMat()[posx][posy] = number;
            if (VerifyHorizontal1(mat->getMat(), posx, posy, 2)||VerifyVertical1(mat->getMat(), posx, posy, 2)||VerifyDiagonal1(mat->getMat(), posx, posy, 2)||VerifyDiagonalC1(mat->getMat(), posx, posy, 2)) {
              printMatrix(mat->getMat(), 2);
              cout<<endl;
              cout<<"Felicidades!! Acabas de ganar el juego: "<<p2<<endl;
              cout<<endl;
              game = false;
              break;
            }
            if (lose(mat->getMat(), 2)) {
              cout<<"Lo siento, ambos jugadores perdieron"<<endl;
              game=false;
              break;
            }
            turno2 = false;
            turno1 = true;
          }

      }

      //deleteMatrix(mat,2);
      break;
      }
      case 2:{
        bool game1 = true;
        unique_ptr<Tictac> mat(new Tictac(3));
        mat->setMat(createMatrix(3));
        string p1=Player1();
        string p2=Player2();
        while (game1) {
          bool turno1=true;
          bool turno2=false;
          int number;
          int posx;
          int posy;
          while (turno1) {
            cout<<"Turno de Jugador 1:"<<p1<<endl;
            cout<<"_______________________________________"<<endl<<endl;
            printMatrix(mat->getMat(), 3);
            posx=posX(3);
            posy=posY(3);
            while (!position(mat->getMat(), posx, posy, 3)) {
              cout<<"Posicion invalida, intente de nuevo"<<endl;
              cout<<endl;
              posx=posX(3);
              posy=posY(3);
            }
            number=numeros();
            mat->getMat()[posx][posy] = number;

            if (VerifyHorizontal2(mat->getMat(), posx, posy, 3)||VerifyVertical2(mat->getMat(), posx, posy, 3)||VerifyDiagonal2(mat->getMat(), posx, posy, 3)||VerifyDiagonalC2(mat->getMat(), posx, posy, 2)) {
              printMatrix(mat->getMat(), 3);
              cout<<endl;
              cout<<"Felicidades!! Acabas de ganar el juego: "<<p1<<endl;
              cout<<endl;
              game1=false;
              break;
            }
            if (lose(mat->getMat(), 3)) {
              cout<<"Lo siento, ambos jugadores perdieron"<<endl;
              game1=false;
              break;
            }
            turno1 = false;
            turno2 = true;
          }
          while (turno2) {
            cout<<"Turno de Jugador 2:"<<p2<<endl;
            cout<<"_______________________________________"<<endl<<endl;
            printMatrix(mat->getMat(), 3);
            posx=posX(3);
            posy=posY(3);
            while (!position(mat->getMat(), posx, posy, 3)) {
              cout<<"Posicion invalida, intente de nuevo"<<endl;
              cout<<endl;
              posx=posX(3);
              posy=posY(3);
            }
            number=numeros();
            mat->getMat()[posx][posy] = number;
            if (VerifyHorizontal2(mat->getMat(), posx, posy, 3)||VerifyVertical2(mat->getMat(), posx, posy, 3)||VerifyDiagonal2(mat->getMat(), posx, posy, 3)||VerifyDiagonalC2(mat->getMat(), posx, posy, 2)) {
              printMatrix(mat->getMat(), 3);
              cout<<endl;
              cout<<"Felicidades!! Acabas de ganar el juego: "<<p2<<endl;
              cout<<endl;
              game1=false;
              break;
            }
            if (lose(mat->getMat(), 3)) {
              cout<<"Lo siento, ambos jugadores perdieron"<<endl;
              game1=false;
              break;
            }
            turno2 = false;
            turno1 = true;
          }
      }

      //deleteMatrix(mat,3);
      break;
      }

      case 3:{
        bool game1 = true;
        unique_ptr<Tictac> mat(new Tictac(4));
        mat->setMat(createMatrix(4));
        string p1=Player1();
        string p2=Player2();
        while (game1) {
          bool turno1=true;
          bool turno2=false;
          int number;
          int posx;
          int posy;
          while (turno1) {
            cout<<"Turno de Jugador 1:"<<p1<<endl;
            cout<<"_______________________________________"<<endl<<endl;
            printMatrix(mat->getMat(), 4);
            posx=posX(4);
            posy=posY(4);
            while (!position(mat->getMat(), posx, posy, 4)) {
              cout<<"Posicion invalida, intente de nuevo"<<endl;
              cout<<endl;
              posx=posX(4);
              posy=posY(4);
            }
            number=numeros();
            mat->getMat()[posx][posy] = number;

            if (VerifyHorizontal3(mat->getMat(), posx, posy, 4)||VerifyVertical3(mat->getMat(), posx, posy, 4)||VerifyDiagonal3(mat->getMat(), posx, posy, 4)||VerifyDiagonalC3(mat->getMat(), posx, posy, 2)) {
              printMatrix(mat->getMat(), 4);
              cout<<endl;
              cout<<"Felicidades!! Acabas de ganar el juego: "<<p1<<endl;
              cout<<endl;
              game1=false;
              break;
            }
            if (lose(mat->getMat(), 4)) {
              cout<<"Lo siento, ambos jugadores perdieron"<<endl;
              game1=false;
              break;
            }

            turno1 = false;
            turno2 = true;
          }
          while (turno2) {
            cout<<"Turno de Jugador 2:"<<p2<<endl;
            cout<<"_______________________________________"<<endl<<endl;
            printMatrix(mat->getMat(), 4);
            posx=posX(4);
            posy=posY(4);
            while (!position(mat->getMat(), posx, posy, 4)) {
              cout<<"Posicion invalida, intente de nuevo"<<endl;
              cout<<endl;
              posx=posX(4);
              posy=posY(4);
            }
            number=numeros();
            mat->getMat()[posx][posy] = number;
            if (VerifyHorizontal3(mat->getMat(), posx, posy, 4)||VerifyVertical3(mat->getMat(), posx, posy, 4)||VerifyDiagonal3(mat->getMat(), posx, posy, 4)||VerifyDiagonalC3(mat->getMat(), posx, posy, 2)) {
              printMatrix(mat->getMat(), 4);
              cout<<endl;
              cout<<"Felicidades!! Acabas de ganar el juego: "<<p2<<endl;
              cout<<endl;
              game1=false;
              break;
            }
            if (lose(mat->getMat(), 4)) {
              cout<<"Lo siento, ambos jugadores perdieron"<<endl;
              game1=false;
              break;
            }
            turno2 = false;
            turno1 = true;
          }
      }

      //deleteMatrix(mat,4);


        break;
      }
      case 4:{
        bool game = true;
        unique_ptr<Tictac> mat(new Tictac(2));
        mat->setMat(createMatrix(2));
        string p1=Player1();
        while (game) {
          bool turno1=true;
          bool turno2=false;
          int number;
          int posx;
          int posy;
          while (turno1) {
            cout<<"Turno de Jugador 1:"<<p1<<endl;
            cout<<"_______________________________________"<<endl<<endl;
            printMatrix(mat->getMat(), 2);
            posx=posX(2);
            posy=posY(2);
            while (!position(mat->getMat(), posx, posy, 2)) {
              cout<<"Posicion invalida, intente de nuevo"<<endl;
              cout<<endl;
              posx=posX(2);
              posy=posY(2);
            }
            number=numeros();
            mat->getMat()[posx][posy] = number;

            if (VerifyHorizontal1(mat->getMat(), posx, posy, 2)||VerifyVertical1(mat->getMat(), posx, posy, 2)||VerifyDiagonal1(mat->getMat(), posx, posy, 2)||VerifyDiagonalC1(mat->getMat(), posx, posy, 2)) {
              printMatrix(mat->getMat(), 2);
              cout<<endl;
              cout<<"Felicidades!! Acabas de ganar el juego: "<<p1<<endl;
              cout<<endl;
              game = false;
              break;
            }
            if (lose(mat->getMat(), 2)) {
              cout<<"Lo siento, ambos jugadores perdieron"<<endl;
              game=false;
              break;
            }
            turno1 = false;
            turno2 = true;
          }
          while (turno2) {
            cout<<"Turno de Jugador 2: "<<"MACHINE"<<endl;
            cout<<"_______________________________________"<<endl<<endl;
            printMatrix(mat->getMat(), 2);
            int posxi=compX(mat->getMat(), posx, posy, 2);
            int posyi=compY(mat->getMat(), posx, posy, 2);
            int numberr=computedNumber2x2(mat->getMat(), posxi, posyi);
            mat->getMat()[posxi][posyi]=numberr;
            if (VerifyHorizontal1(mat->getMat(), posxi, posyi, 2)||VerifyVertical1(mat->getMat(), posxi, posyi, 2)||VerifyDiagonal1(mat->getMat(), posxi, posyi, 2)||VerifyDiagonalC1(mat->getMat(), posxi, posyi, 2)) {
              printMatrix(mat->getMat(), 2);
              cout<<endl;
              cout<<"Felicidades!! Acabas de ganar el juego: "<<"MACHINE"<<endl;
              cout<<endl;
              game = false;
              break;
            }
            turno2 = false;
            turno1 = true;
          }

      }

      //deleteMatrix(mat,2);

      break;
      }
      case 5:{

        break;
      }
      case 6:{

        break;
      }
      case 7:{
        cout<<" BIENVENIDOD A LOS SCORES DE LOS JUGADORES"<<endl;
        cout<<"_______________________________________________________"<<endl;
        for (int i = 0; i < players.size(); i++) {
          cout<<i<<"- "<<players.at(i)->getNombre()<<": "<<players.at(i)->getScore()<<endl;
        }

        break;
      }

      case 8:{
        salir = false;
        break;
        break;
      }
    }

  }
  return 0;
}

int** createMatrix(int size){
    int** matrix = new int* [size];

  for (int i = 0; i < size; i++) {
    matrix[i] = new int[size];
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix[i][j] = -1;
    }
  }

  return matrix;
}

void printMatrix(int** matrix, int size){
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (matrix[i][j]==-1) {
        cout<<"["<<" "<<"]";
      } else{
        cout<<"["<<matrix[i][j]<<"]";
      }
    }
    cout<<endl;
  }
}

vector<Player*> readFile(){
  vector<Player*> players;
  fstream file("Players.txt");
  if (file.is_open()) {
    while(!file.eof()){
      string name;
      string hscore;
      int score;
        getline(file,name,',');
        getline(file,hscore,';');
        score = atoi(hscore.c_str());
        players.push_back(new Player(name,score));
    }
    file.close();
    return players;
  }
}

void wFile(vector<Player*> players){
  ofstream archivo("Players.txt");
  if (archivo.is_open()) {
    for (int i = 0; i < players.size(); i++) {
      archivo<<players.at(i)->toString();
    }
    archivo.close();
  }
}

/*void deleteMatrix(int** matrix, int size){
  for (int i = 0; i < size; i++) {
    delete[] matrix[i];
    matrix[i] = NULL;
  }
  delete[] matrix;
}*/

//verificar si el numero es primo
bool PrimeNum(int num){
  bool prime = false;
  int cont = 0;

  for (int i = 1; i <= num; i++) {
    if (num%i==0) {
      cont++;
    }
  }

  if (cont==2) {
    prime = true;
  }
  return prime;
}

void Facil(int** mat, int size){
  int num = 1, c;
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (mat[i][j]==-1) {
        while (num%2!=0) {
          num = rand()%9;
        }
        mat[i][j]=num;
        break;
      }
    }
  }
}

void Medio(int** mat, int size){
  int num = 1, c;
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (mat[i][j]==-1) {
          num = rand()%9;
        mat[i][j]=num;
        break;
      }
    }
  }
}

int menu(){
  cout<<"1- JUGADOR 1 VS JUGADOR 2  (Matriz de 2X2)"<<endl;
  cout<<"2- JUGADOR 1 VS JUGADOR 2  (Matriz de 3X3)"<<endl;
  cout<<"3- JUGADOR 1 VS JUGADOR 2  (Matriz de 4X4)"<<endl;
  cout<<"4- JUGADOR 1 VS MACHINE    (Matriz de 2X2)"<<endl;
  cout<<"5- JUGADOR 1 VS MACHINE    (Matriz de 3X3)"<<endl;
  cout<<"6- JUGADOR 1 VS MACHINE    (Matriz de 4X4)"<<endl;
  cout<<"7- VER SCORES"<<endl;
  cout<<"8- Salir "<<endl;
  cout<<endl;
  cout<<"Ingrese una opción"<<endl;
  int op=0;
  cin>>op;
  while (op<0||op>8) {
    cout<<"Opcion invalida. Ingrese de nuevo"<<endl;
    cin>>op;
  }
  return op;
}

//Funcion para validar que la posicion de x este dentro de la matriz
int posX(int size){
  int x;
  cout<<"Ingrese posicion en X de la matriz"<<endl;
  cin>>x;
  while(x>size-1||x<0){
    cout<<"Posicion inexistente, intente de nuevo"<<endl;
    cin>>x;
  }
  return x;
}

//Funcion para validar que la posicion de Y este dentro de la matriz
int posY(int size){
  int y;
  cout<<"Ingrese posicion en Y de la matriz"<<endl;
  cin>>y;
  while(y>size-1||y<0){
    cout<<"Posicion inexistente, intente de nuevo"<<endl;
    cin>>y;
  }
  return y;
}


//funcion para verificar si la posicion ingresada es valida
bool position(int** mat, int x, int y, int size){
  bool val= false;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i==x && j == y) {
        if (mat[i][j]==-1) {
          val = true;
        }
      }
    }
  }
  return val;
}

//Funcion para validar que el numero este entre el rango de 0 a 9.
int numeros(){
  cout<<"Ingrese un numero de 0-9"<<endl;
  int number;
  cin>>number;
  while(number<0||number>9){
    std::cout << "Lo sentimos! Ingrese un numero dentro del rango de 0-9" << '\n';
    cin>>number;
  }
  return number;
}

int compX(int** mat, int x, int y, int size){
  int posx;
  for (int i = 0; i < size; i++) {
    if (mat[x][i]==-1) {
      posx=i;
      break;
    }
  }
  return posx;
}

int compY(int** mat, int x, int y, int size){
  int posy;
  for (int i = 0; i < size; i++) {
    if (mat[i][y]==-1) {
      posy=i;
      break;
    }
  }
  return posy;
}

int computedNumber2x2(int** mat, int x, int y){ //matriz de 2x2 solamente
  int num;
  int generated;
  int cont=0;
  if (x==0&&y==0) {
    if (mat[x+1][y+1]==-1) {
      for (int k = 0; k < 9; k++) {
        num=mat[x][y]*10;
        if (PrimeNum(num+k)) {
          cont++;
          mat[x+1][y+1]=k;
          generated = k;
          break;
        }
      }
    }
  }else if (x==1&&y==0) {
    if (mat[x-1][y+1]==-1) {
      for (int k = 0; k < 9; k++) {
        num=mat[x][y]*10;
        if (PrimeNum(num+k)) {
          mat[x-1][y+1]=k;
          generated=k;
          break;
        }
      }
    }
  } else if (x==0&&y==1) {
    if (mat[x+1][y-1]==-1) {
      for (int k = 0; k < 9; k++) {
        num=mat[x][y]*10;
        if (PrimeNum(num+k)) {
          mat[x+1][y-1]=k;
          generated=k;
          break;
        }
      }
    }
  } else if (x==1&&y==1) {
    if (mat[x-1][y-1]==-1) {
      for (int k = 0; k < 9; k++) {
        num=mat[x][y]*10;
        if (PrimeNum(num+k)) {
          mat[x-1][y-1]=k;
          generated=k;
          break;
        }
      }
    }
  }
  return generated;
}

string Player1(){
  string player;
  cout<<"Ingrese nombre de jugador 1: "<<endl;
  cin>>player;
  return player;
}

string Player2(){
  string player;
  cout<<"Ingrese nombre de jugador 2: "<<endl;
  cin>>player;
  return player;
}

bool VerifyHorizontal1(int** mat, int x, int y, int size){
  bool ver = false;
  int n1, n2;
    for (int i = 0; i < size; i++) {
      if (mat[x][i]!=-1) {
        if (i==0) {
          n1=mat[x][i]*10;
        } else if (i==1) {
          n1+=mat[x][i];
        }
      }
    }

    for (int i = size-1; i >= 0; i--) {
      if (mat[x][i]!=-1) {
        if (i==1) {
          n2=mat[x][i]*10;
        } else if (i==0) {
          n2+=mat[x][i];
        }
      }
    }
    if (PrimeNum(n1)||PrimeNum(n2)) {
      ver = true;
    }
    return ver;
}

bool VerifyHorizontal2(int** mat, int x, int y, int size){
  bool ver = false;
  int n1, n2;
  int cont1=0, cont2=0;
    for (int i = 0; i < size; i++) {
      if (mat[x][i]!=-1) {
        if (i==0) {
          cont1++;
          n1=mat[x][i]*100;
        } else if (i==1) {
          cont1++;
          n1+=(mat[x][i]*10);
        } else if (i==2) {
          cont1++;
          n1+=mat[x][i];
        }
      }
    }

    for (int i = size-1; i >= 0; i--) {
      if (mat[x][i]!=-1) {
        if (i==2) {
          cont2++;
          n2=mat[x][i]*100;
        } else if (i==1) {
          cont2++;
          n2+=(mat[x][i]*10);
        } else if (i==0) {
          cont2++;
          n2+=mat[x][i];
        }
      }
    }
    if ((PrimeNum(n1)&&cont1==size)||(PrimeNum(n2)&&cont2==size)) {
      ver = true;
    }
    return ver;
}

bool VerifyHorizontal3(int** mat, int x, int y, int size){
  bool ver = false;
  int n1, n2;
  int cont1 = 0, cont2=0;
    for (int i = 0; i < size; i++) {
      if (mat[x][i]!=-1) {
        if (i==0) {
          cont1++;
          n1=mat[x][i]*1000;
        } else if (i==1) {
          cont1++;
          n1+=(mat[x][i]*100);
        } else if (i==2) {
          cont1++;
          n1+=(mat[x][i]*10);
        } else if (i==3) {
          cont1++;
          n1+=mat[x][i];
        }
      }
    }

    for (int i = size-1; i >= 0; i--) {
      if (mat[x][i]!=-1) {
        if (i==3) {
          cont2++;
          n2=mat[x][i]*1000;
        } else if (i==2) {
          cont2++;
          n2+=(mat[x][i]*100);
        } else if (i==1) {
          cont2++;
          n2+=(mat[x][i]*10);
        } else if (i==0) {
          cont2++;
          n2+=mat[x][i];
        }
      }
    }
    if ((PrimeNum(n1)&&cont1==size)||(PrimeNum(n2)&&cont2==size)) {
      ver = true;
    }
    return ver;
}

bool VerifyVertical1(int** mat, int x, int y, int size){
  bool ver = false;
  int n1, n2;
    for (int i = 0; i < size; i++) {
      if (mat[i][y]!=-1) {
        if (i==0) {
          n1=mat[i][y]*10;
        } else if (i==1) {
          n1+=mat[i][y];
        }
      }
    }

    for (int i = size-1; i >= 0; i--) {
      if (mat[i][y]!=-1) {
        if (i==1) {
          n2=mat[i][y]*10;
        } else if (i==0) {
          n2+=mat[i][y];
        }
      }
    }
    if (PrimeNum(n1)||PrimeNum(n2)) {
      ver = true;
    }
    return ver;
}

bool VerifyVertical2(int** mat, int x, int y, int size){
  bool ver = false;
  int n1, n2;
  int cont1=0, cont2=0;
    for (int i = 0; i < size; i++) {
      if (mat[i][y]!=-1) {
        if (i==0) {
          cont1++;
          n1=mat[i][y]*100;
        } else if (i==1) {
          cont1++;
          n1+=(mat[i][y]*10);
        } else if (i==2) {
          cont1++;
          n1+=mat[i][y];
        }
      }
    }

    for (int i = size-1; i >= 0; i--) {
      if (mat[i][y]!=-1) {
        if (i==2) {
          cont2++;
          n2=mat[i][y]*100;
        } else if (i==1) {
          cont2++;
          n2+=(mat[i][y]*10);
        } else if (i==0){
          cont2++;
          n2+=mat[i][y];
        }
      }
    }

    if ((PrimeNum(n1)&&cont1==size)||(PrimeNum(n2)&&cont2==size)) {
      ver = true;
    }
    return ver;
}
bool VerifyVertical3(int** mat, int x, int y, int size){
  bool ver = false;
  int n1, n2;
  int cont1=0, cont2=0;
    for (int i = 0; i < size; i++) {
      if (mat[i][y]!=-1) {
        if (i==0) {
          cont1++;
          n1=mat[i][y]*1000;
        }
        if (i==1) {
          cont1++;
          n1+=(mat[i][y]*100);
        }
        if (i==2) {
          cont1++;
          n1+=(mat[i][y]*10);
        }
        if (i==3) {
          cont1++;
          n1+=mat[i][y];
        }
      }
    }

    for (int i = size-1; i >= 0; i--) {
      if (mat[i][y]!=-1) {
        if (i==3) {
          cont2++;
          n2=mat[i][y]*1000;
        }
        if (i==2) {
          cont2++;
          n2+=(mat[i][y]*100);
        }
        if (i==1) {
          cont2++;
          n2+=(mat[i][y]*10);
        }
        if (i==0) {
          cont2++;
          n2+=mat[i][y];
        }
      }
    }
    if ((PrimeNum(n1)&&(cont1==size))||(PrimeNum(n2)&&(cont2==size))) {
      ver = true;
    }
    return ver;
}

bool VerifyDiagonal1(int** mat, int x, int y, int size){
  bool ver = false;
  int n1, n2;
  int cont1=0, cont2=0;
  if (x==y) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (mat[i][j]!=-1) {
          if (i==0&&i==j) {
            cont1++;
            n1=mat[i][j]*10;
          }
          if (i==1&&i==j) {
            cont1++;
            n1+=mat[i][j];
          }
        }
      }
    }

    for (int i = size-1; i >=0; i--) {
      for (int j = size-1; j >=0; j--) {
        if (mat[i][j]!=-1) {
          if (i==1&&i==j) {
            cont2++;
            n2=mat[i][j]*10;
          }
          if (i==0&&i==j) {
            cont2++;
            n2+=mat[i][j];
          }
        }
      }
    }
    if ((PrimeNum(n1)&&cont1==size)||(PrimeNum(n2)&&cont2==size)) {
      ver = true;
    }
  }
  return ver;
}

bool VerifyDiagonal2(int** mat, int x, int y, int size){
  bool ver = false;
  int n1, n2;
  int cont1=0, cont2=0;
  if (x==y) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (mat[i][j]!=-1) {
          if (i==0&&i==j) {
            cont1++;
            n1=mat[i][j]*100;
          } else if (i==1&&i==j) {
            cont1++;
            n1+=(mat[i][j]*10);
          } else if (i==2&&i==j) {
            cont1++;
            n1+=mat[i][j];
          }
        }
      }
    }

    for (int i = size-1; i >=0; i--) {
      for (int j = size-1; j >=0; j--) {
        if (mat[i][j]!=-1) {
          if (i==2&&i==j) {
            cont2++;
            n2=mat[i][j]*100;
          } else if (i==1&&i==j) {
            cont2++;
            n2+=(mat[i][j]*10);
          } else if (i==0&&i==j) {
            cont2++;
            n2+=mat[i][j];
          }
        }
      }
    }
    if ((PrimeNum(n1)&&cont1==size)||(PrimeNum(n2)&&cont2==size)) {
      ver = true;
    }
  }
  return ver;
}

bool VerifyDiagonal3(int** mat, int x, int y, int size){
  bool ver = false;
  int n1, n2;
  int cont1=0, cont2=0;
  if (x==y) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (mat[i][j]!=-1) {
          if (i==0&&i==j) {
            cont1++;
            n1=mat[i][j]*1000;
          } else if (i==1&&i==j) {
            cont1++;
            n1+=(mat[i][j]*100);
          } else if (i==2&&i==j) {
            cont1++;
            n1+=(mat[i][j]*10);
          } else if (i==3&&i==j) {
            cont1++;
            n1+=mat[i][j];
          }
        }
      }
    }

    for (int i = size-1; i >=0; i--) {
      for (int j = size-1; j >=0; j--) {
        if (mat[i][j]!=-1) {
          if (i==2&&i==j) {
            cont2++;
            n2=mat[i][j]*1000;
          } else if (i==1&&i==j) {
            cont2++;
            n2+=(mat[i][j]*100);
          } else if (i==0&&i==j) {
            cont2++;
            n2+=(mat[i][j]*10);
          } else if (i==3&&i==j) {
            cont2++;
            n2+=mat[i][y];
          }
        }
      }
    }
    if ((PrimeNum(n1)&&cont1==size)||(PrimeNum(n2)&&cont2==size)) {
      ver = true;
    }
  }
  return ver;
}


//Verificar las diagonales contrarias
bool VerifyDiagonalC1(int** mat, int x, int y, int size){
  bool ver = false;
  int n1, n2;
  int cont1=0, cont2=0;
  if (x==y) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (mat[i][j]!=-1) {
          if (i==0&&(i-j==0)) {
            cont1++;
            n1=mat[i][j]*10;
          }
          if (i==1&&(i-j==0)) {
            cont1++;
            n1+=mat[i][j];
          }
        }
      }
    }

    for (int i = size-1; i >=0; i--) {
      for (int j = size-1; j >=0; j--) {
        if (mat[i][j]!=-1) {
          if (i==1&&(i-j==0)) {
            cont2++;
            n2=mat[i][j]*10;
          }
          if (i==0&&(i-j==0)) {
            cont2++;
            n2+=mat[i][j];
          }
        }
      }
    }
    if ((PrimeNum(n1)&&cont1==size)||(PrimeNum(n2)&&cont2==size)) {
      ver = true;
    }
  }
  return ver;
}

bool VerifyDiagonalC2(int** mat, int x, int y, int size){
  bool ver = false;
  int n1, n2;
  int cont1=0, cont2=0;
  if (x==y) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (mat[i][j]!=-1) {
          if (i==0&&(i-j==0)) {
            cont1++;
            n1=mat[i][j]*100;
          } else if (i==1&&(i-j==0)) {
            cont1++;
            n1+=(mat[i][j]*10);
          } else if (i==2&&(i-j==0)) {
            cont1++;
            n1+=mat[i][j];
          }
        }
      }
    }

    for (int i = size-1; i >=0; i--) {
      for (int j = size-1; j >=0; j--) {
        if (mat[i][j]!=-1) {
          if (i==2&&(i-j==0)) {
            cont2++;
            n2=mat[i][j]*100;
          } else if (i==1&&(i-j==0)) {
            cont2++;
            n2+=(mat[i][j]*10);
          } else if (i==0&&(i-j==0)) {
            cont2++;
            n2+=mat[i][j];
          }
        }
      }
    }
    if ((PrimeNum(n1)&&cont1==size)||(PrimeNum(n2)&&cont2==size)) {
      ver = true;
    }
  }
  return ver;
}

bool VerifyDiagonalC3(int** mat, int x, int y, int size){
  bool ver = false;
  int n1, n2;
  int cont1=0, cont2=0;
  if (x==y) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (mat[i][j]!=-1) {
          if (i==0&&(i-j==0)) {
            cont1++;
            n1=mat[i][j]*1000;
          } else if (i==1&&(i-j==0)) {
            cont1++;
            n1+=(mat[i][j]*100);
          } else if (i==2&&(i-j==0)) {
            cont1++;
            n1+=(mat[i][j]*10);
          } else if (i==3&&(i-j==0)) {
            cont1++;
            n1+=mat[i][j];
          }
        }
      }
    }

    for (int i = size-1; i >=0; i--) {
      for (int j = size-1; j >=0; j--) {
        if (mat[i][j]!=-1) {
          if (i==2&&(i-j==0)) {
            cont2++;
            n2=mat[i][j]*1000;
          } else if (i==1&&(i-j==0)) {
            cont2++;
            n2+=(mat[i][j]*100);
          } else if (i==0&&(i-j==0)) {
            cont2++;
            n2+=(mat[i][j]*10);
          } else if (i==3&&(i-j==0)) {
            cont2++;
            n2+=mat[i][y];
          }
        }
      }
    }
    if ((PrimeNum(n1)&&cont1==size)||(PrimeNum(n2)&&cont2==size)) {
      ver = true;
    }
  }
  return ver;
}
