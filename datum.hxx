#ifndef _DATUM_H
#define _DATUM_H

#include <iostream>

class Datum{  
    friend std::ostream& operator<<(std::ostream&, const Datum&);
    private:
      int _godina, _mjesec , _dan;
    public: 
      Datum() = default;
      Datum(int,int,int);
      int getGod() const { return _godina; }
      int getMjesec() const { return _mjesec; }
      int getDan() const { return _dan; }
      ~Datum() = default;
};


Datum::Datum(int dan, int mjesec, int god){
      _dan = dan;
      _mjesec = mjesec;
      _godina = god;
}

std::ostream& operator<<(std::ostream& izlaz, const Datum& datum){
  izlaz << datum._dan << "." << datum._mjesec << "." << datum._godina << "." << std::endl;
  return izlaz;
}

#endif
