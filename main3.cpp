#include "phrase3.hpp"
#include <iostream>
#include <cstddef>        // std::size_t
#include <string>         // std::string



Alphabet::Alphabet()
{
  alphabet={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','k','r','s','t','v','w','x','y','z'};
}

Alphabet::Alphabet(std::vector<char> &v)
{
     alphabet=v;
}

Alphabet::Alphabet(const Alphabet &other)
{
  alphabet = other.alphabet;
}
Alphabet& Alphabet::operator=(const Alphabet &A)
{

    alphabet = A.alphabet;

    return *this;
}
void Alphabet::put_alphabet(int i, char a)
{
    alphabet[i] =  a;
}
Alphabet Alphabet::get_alphabet()
{
  return alphabet;
}
int Alphabet::taille() const
{
  return alphabet.size();
}
bool Alphabet::teste_mot(std::string &s)
{
  int compteur = 0;
  bool r = false;
  for(std::string::size_type i = 0; i < s.length(); i++){
     for(int j = 0; j<alphabet.size(); j++){
       if(s[i]  == alphabet[j] ) compteur++ ;//return true;
     }
     if(compteur-(i+1)!=0) compteur = compteur-1; //eviter les doublons

  }
  std::cout << compteur << '\n';
  if(compteur == s.length()) {r = true;}

  return r;

}

std::ostream & operator <<(std::ostream & os, Alphabet A)
{
     for(int i=0;i < A.alphabet.size();i++){
         os << A.alphabet[i] << " ";
     }
     os << std::endl;
   return os;
}


Dico::Dico()
{
  Dico::alphabet={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','k','r','s','t','v','w','x','y','z'};
}

Dico::Dico(Alphabet a, std::vector<std::string> &s)
{
  str = s;
  alphab = a;
}
void Dico::aff_dico() const
{
    for (int i = 0; i< str.size(); i++) {
       std::cout << str[i] << '\n';
    }

}
void Dico::aff_alphabet() const
{
  for (int i = 0; i< alphabet.size(); i++) {
     std::cout << alphabet[i] << '\n';
  }
}


int main ()
{
  int i,j;
  // Partie 1 de l'examen

  Alphabet alphab1;
  std::vector<char> v1{'l','a','m','f','c','b','s','e','a','p'};
  std::vector<char> v2{'k','l','k','h','d','u','y','q','a','z','p','m'};

  Alphabet alphab2(v1);
  Alphabet alphab3(v2);

  std::cout << "alphab1 = " << alphab1;

  std::cout << "v1 = {l,a,m,f,c,b,s,e,a,p}\n";
  std::cout << "alphab2(v1) = " << alphab2;

  std::cout << "v2 = {k,l,k,h,d,u,y,q,a,z,p,m}\n";
  std::cout << "alphab3(v2) = " << alphab3;


  // partie 2 de l'examen

  Alphabet alphab4(alphab2);
  Alphabet alphab5;
  alphab5 = alphab3;

  std::cout << "alphab4(alphab2) = " << alphab4;
  std::cout << "alphab5 = alphab3 = " << alphab5;

  std::string a1 = "melasse";
  std::string a2 = "matelas";

  std::cout << a1 << " dans aphab2 ? \n";
  if (alphab2.teste_mot(a1))
    std::cout << "oui"<< "\n";
  else
    std::cout << "non"<< "\n";

  std::cout << a2 << " dans aphab2 ? \n";
  if (alphab2.teste_mot(a2))
    std::cout << "oui"<< "\n";
  else
    std::cout << "non"<< "\n";


  //partie 3

  Dico d1;


  std::vector<std::string> vs={"base","lame","mua","dual","qhmp","pbcf","lafc"};

  Dico d2(alphab2,vs);
  Dico d3(alphab3,vs);


  std::cout << "d1 :\n";
  d1.aff_dico();
  d1.aff_alphabet();
  std::cout << "d2 :\n";
  d2.aff_alphabet();
  d2.aff_dico();
  std::cout << "d3 :\n";
  d3.aff_alphabet();
  d3.aff_dico();



}
