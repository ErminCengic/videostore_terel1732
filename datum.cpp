#include "datum.h"

Datum::Datum(int dan, int mjesec, int god){
      _dan = dan;
      _mjesec = mjesec;
      _godina = god;
}

std::ostream& operator<<(std::ostream& izlaz, const Datum& datum){
  izlaz << datum._dan << "." << datum._mjesec << "." << datum._godina;
  return izlaz;
}

int Datum::getGod() const { return _godina; }
int Datum::getMjesec() const { return _mjesec; }
int Datum::getDan() const { return _dan; }
void Datum::setDan(int dan) {_dan = dan;}
