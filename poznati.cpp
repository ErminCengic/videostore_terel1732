#include "poznati.h"

Poznati::Poznati(const std::string& ime, const std::string& prezime){
      _ime = ime;
      _prezime = prezime;
}

void Poznati::setIme(const std::string& ime) {_ime = ime;}
void Poznati::setPrezime(const std::string& prezime) {_prezime = prezime;}
std::string Poznati::getIme() const {return _ime;}
std::string Poznati::getPrezime() const {return _prezime;}

std::ostream& operator<<(std::ostream& izlaz, const Poznati& poznati){
      izlaz << poznati._ime << " " << poznati._prezime;
      return izlaz;
}
