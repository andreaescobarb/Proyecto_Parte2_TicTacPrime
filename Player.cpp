#include "Player.h"

Player::Player(){

}

Player::Player(string nombre, int score){
  this->nombre=nombre;
  this->score=score;
}

void Player::setNombre(string nombre){
  this->nombre=nombre;
}

string Player::getNombre(){
  return nombre;
}

void Player::setScore(int score){
  this->score=score;
}

int Player::getScore(){
  return score;
}

string Player::toString(){
  stringstream ss;
  ss.str("");
  ss<<nombre;
  ss<<",";
  ss<<score;
  ss<<";";
  return ss.str();
}

Player::~Player(){

}
