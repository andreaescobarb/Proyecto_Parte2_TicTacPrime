#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "memory"
#include "utility"
#include "sstream"
using namespace std;

class Player{
  private:
    string nombre;
    int score;

  public:
    Player();
    Player(string, int);
    void setNombre(string);
    string getNombre();
    void setScore(int);
    int getScore();
    string toString();
    ~Player();

};
#endif
