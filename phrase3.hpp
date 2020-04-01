#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<list>
//using namespace std;

#ifndef PHRASE3_HPP
#define PHRASE3_HPP

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


  protected:
     std::vector<char>  alphabet;



 };

 class Dico : public Alphabet
 {
    public:
      Dico();
      Dico(Alphabet a, std::vector<std::string>  &s);
      void aff_dico() const;
      void aff_alphabet() const;

    private:
      std::vector<std::string>  str;
      Alphabet alphab;

 };


 #endif
