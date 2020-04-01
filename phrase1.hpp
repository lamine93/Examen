
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


     friend std::ostream& operator <<(std::ostream & os, Alphabet A);


  private:
     std::vector<char>  alphabet;


 };


 #endif
