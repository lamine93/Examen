#include "phrase2.hpp"
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







int main ()
{
  int i,j;
  // Partie 1 de l'examen

  Alphabet alphab1;
  std::vector<char> v1{'l','a','m','f','c','b','s','e','a','p'};
  std::vector<char> v2{'k','l','k','h','d','u','y','q','a','z','p','m'};

  Alphabet alphab2(v1);
  Alphabet alphab3(v2);


  Alphabet alphab;
  alphab = alphab1.get_alphabet();
  std::cout << "alphab = " << alphab;

  std::cout << "taille alphab1 = " << alphab1.taille() << "\n";

  std::cout << "alphab1 = " << alphab1;

  std::cout << "v1 = {l,a,m,f,c,b,s,e,a,p}\n";
  std::cout << "alphab2(v1) = " << alphab2;

  std::cout << "v2 = {k,l,k,h,d,u,y,q,a,z,p,m}\n";
  std::cout << "alphab3(v2) = " << alphab3;


  // partie 2 de l'examen

  Alphabet alphab4(alphab2);
  Alphabet alphab5;
  alphab5 = alphab3;

  alphab2.taille();

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



}
