#include "phrase4.hpp"
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
  for(std::string::size_type i = 0; i < s.size(); i++){
     for(int j = 0; j<alphabet.size(); j++){
       if(s[i]  == alphabet[j] ) compteur++ ;//return true;
     }
     if(compteur-(i+1)!=0) compteur = compteur-1; //eviter les doublons

  }
  std::cout << compteur << '\n';
  if(compteur == s.size()) {r = true;}

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


bool Dico::presence_mot(std::string  &s)
{
  for (int i = 0; i< str.size(); i++) {
         if(str[i].compare(s) == 0) return true;
  }
  return false;
}
bool Dico::insere_mot(std::string  &s)
{
  if (presence_mot(s))
      return false;
  else{
     int taille = str.size();
     str.resize(taille++, s);
     return true;
   }
}
bool Dico::efface_mot(std::string  &s)
{
  if(!presence_mot(s)) return false;
  else{
    for (int i = 0; i<str.size(); i++){
     if(str[i].compare(s) == 0){
       for(int j=i; j<str.size()-1; j++){
                    str[j] = str[j+1];
                }
                int taille = str.size();
                str.resize(taille--);
     }
    }
    return true;
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


  // partie 4 de l'examen

  std::string ss0 = "base";
  std::string ss1 = "balsa";
  std::string ss2 = "khua";

  if (d2.presence_mot(ss0))
    std::cout << ss0 << " est présent dans d2 \n";
  else
    std::cout << ss0 << " n'est pas présent dans d2 \n";

  if (d3.presence_mot(ss0))
    std::cout << ss0 << " est présent dans d3 \n";
  else
    std::cout << ss0 << " n'est pas présent dans d3 \n";

  if (d2.presence_mot(ss1))
    std::cout << ss1 << " est présent dans d2 \n";
  else
    std::cout << ss1 << " n'est pas présent dans d2 \n";

  if (d2.presence_mot(ss2))
    std::cout << ss2 << " est présent dans d2 \n";
  else
    std::cout << ss2 << " n'est pas présent dans d2 \n";

  if (d3.presence_mot(ss1))
    std::cout << ss1 << " est présent dans d3 \n";
  else
    std::cout << ss1 << " n'est pas présent dans d3 \n";

  if (d3.presence_mot(ss2))
    std::cout << ss2 << " est présent dans d3 \n";
  else
    std::cout << ss2 << " n'est pas présent dans d3 \n";

  // insertion

  if (d2.insere_mot(ss0))
    std::cout << "on insere "<< ss0 << " dans d2\n";
  else
    std::cout << "pas d'insertion de "<< ss0 << " dans d2\n";

  if (d2.insere_mot(ss1))
    std::cout << "on insere "<< ss1 << " dans d2\n";
  else
    std::cout << "pas d'insertion de "<< ss1 << " dans d2\n";

  if (d2.insere_mot(ss2))
    std::cout << "on insere "<< ss2 << " dans d2\n";
  else
    std::cout << "pas d'insertion de "<< ss2 << " dans d2\n";


  if (d3.insere_mot(ss0))
    std::cout << "on insere "<< ss0 << " dans d3\n";
  else
    std::cout << "pas d'insertion de "<< ss0 << " dans d3\n";

  if (d3.insere_mot(ss1))
    std::cout << "on insere "<< ss1 << " dans d3\n";
  else
    std::cout << "pas d'insertion de "<< ss1 << " dans d3\n";

  if (d3.insere_mot(ss2))
    std::cout << "on insere "<< ss2 << " dans d3\n";
  else
    std::cout << "pas d'insertion de "<< ss2 << " dans d3\n";

  // effacement

  if (d2.efface_mot(ss0))
    std::cout << "on efface "<< ss0 << " dans d2\n";
  else
    std::cout << "pas d'effacement de "<< ss0 << " dans d2\n";

  if (d2.efface_mot(ss1))
    std::cout << "on efface "<< ss1 << " dans d2\n";
  else
    std::cout << "pas d'effacement de "<< ss1 << " dans d2\n";

  if (d2.efface_mot(ss2))
    std::cout << "on efface "<< ss2 << " dans d2\n";
  else
    std::cout << "pas d'effacement de "<< ss2 << " dans d2\n";


  if (d3.efface_mot(ss0))
    std::cout << "on efface "<< ss0 << " dans d3\n";
  else
    std::cout << "pas d'effacement de "<< ss0 << " dans d3\n";

  if (d3.efface_mot(ss1))
    std::cout << "on efface "<< ss1 << " dans d3\n";
  else
    std::cout << "pas d'effacement de "<< ss1 << " dans d3\n";

  if (d3.efface_mot(ss2))
    std::cout << "on efface "<< ss2 << " dans d3\n";
  else
    std::cout << "pas d'effacement de "<< ss2 << " dans d3\n";

  //
  std::cout << "Au final\n";
  std::cout << "d2 :\n";
  d2.aff_alphabet();
  d2.aff_dico();
  std::cout << "d3 :\n";
  d3.aff_alphabet();
  d3.aff_dico();


}
