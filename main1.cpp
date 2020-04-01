#include "phrase1.hpp"
#include <iostream>


Alphabet::Alphabet()
{
  alphabet={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','k','r','s','t','v','w','x','y','z'};
}

Alphabet::Alphabet(std::vector<char> &v)
{
     alphabet=v;
}

std::ostream & operator <<(std::ostream & os, Alphabet A)
   {
     for(int i=0;i < A.alphabet.size();i++){
         os << A.alphabet[i] << " ";
     }
     os << std::endl;
   return os;
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


}
