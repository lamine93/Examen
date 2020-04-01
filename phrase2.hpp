#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<list>
//using namespace std;

#ifndef PHRASE1_HPP
#define PHRASE1_HPP

class Alphabet
{
  public:

     Alphabet();
     Alphabet(std::vector<char> &v);
     Alphabet(const Alphabet &other);
     Alphabet& operator=(const Alphabet &A);
     void put_alphabet(int i, char a);
     Alphabet get_alphabet();
     int taille() const;
     bool teste_mot(std::string &s);


     friend std::ostream& operator <<(std::ostream & os, Alphabet A);


  private:
     std::vector<char>  alphabet;


 };


 #endif
