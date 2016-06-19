#include "racun.h"

std::string Racun::getUsername() const { return _korisnickoIme; }
std::string Racun::getLozinka() const { return _lozinka; }
void Racun::setUsername(const std::string& ime) { _korisnickoIme = ime; }
void Racun::setLozinka(const std::string& lozinka) { _lozinka = lozinka; }

Racun::Racun(const std::string& ime, const std::string& lozinka){
      _korisnickoIme = ime;
      _lozinka = lozinka;
}

bool Racun::validnost_lozinke(const std::string& lozinka){
      if(lozinka.length() < 4){
        std::cout <<"Duzina lozinke mora biti veca od 3!" << std::endl;
        return false;}
      else return true;
}

bool space(const std::string& s){
  for(int i = 0; i < s.length(); ++i){
      if(std::isspace(s[i]))
        return false;
  }
  return true;
}

bool Racun::validnost_username(const std::string& username){
  if(username[0] >= '0' && username[0] <= '9'){
      std::cout << "Username ne smije poceti sa brojem!" << std::endl;
      return false;
  }
  else if(!space(username)){
    std::cout << "Username ne smije imati razmak!" << std::endl;
    return false;
  }
  return true;
}

std::ostream& operator<<(std::ostream& izlaz, const Racun& racun){
    izlaz << racun._korisnickoIme << " " << racun._lozinka;
    return izlaz;
}

