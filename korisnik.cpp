#include "korisnik.h"

std::string Korisnik::getIme() const { return _ime; }
std::string Korisnik::getPrezime() const { return _prezime; }
std::string Korisnik::getJmbg() const {return _jmbg;}
void Korisnik::setIme(const std::string& ime) {_ime = ime;}
void Korisnik::setPrezime(const std::string& prezime) {_prezime = prezime;}
void Korisnik::setJmbg(const std::string& jmbg) {_jmbg = jmbg;}
const Racun& Korisnik::getRacun() const {return _racun;}
Korisnik& Korisnik::setRacun(Racun& racun){_racun = racun; return *this;}
const  Datum& Korisnik::getDatum() const {return _datum;}
Korisnik& Korisnik::setDatum(Datum& datum){_datum = datum; return *this;}  
const ListaFilmova& Korisnik::getPosudjeni() const { return _posudjeni; }
Korisnik& Korisnik::setPosudjeni(ListaFilmova& posudjeni) {_posudjeni = posudjeni; return *this;}
const ListaFilmova& Korisnik::getHistorija() const { return _historija; }
Korisnik& Korisnik::setHistorija(ListaFilmova& historija) {_historija = historija; return *this;}
bool Korisnik::validan_jmbg(const std::string& jmbg){
    if(jmbg.length() != 13){
      std::cout << "Jmbg mora imati 13 cifara!" << std::endl;
      return false;}
    for(int i = 0;i< jmbg.length(); ++i){
        if(jmbg[i] < '0' || jmbg[i]>'9'){
          std::cout << "Jmbg mora sadrzavati samo brojeve!" << std::endl;
          return false;
    }
    }
    return true;
}

bool operator==(const Korisnik& prvi,const Korisnik& drugi){
    return (prvi.getRacun().getUsername() == drugi.getRacun().getUsername());
}

bool operator!=(const Korisnik& prvi, const Korisnik& drugi){
    return (prvi.getRacun().getUsername() != drugi.getRacun().getUsername());
}

Korisnik::Korisnik(){
    Datum();
    Racun();
}

Korisnik::Korisnik(const std::string& ime, const std::string& prezime, const std::string& jmbg, const Datum& datum, const Racun& racun){
        _ime = ime;
        _prezime = prezime;
        _jmbg = jmbg;
        _datum = datum;
        _racun = racun;
}

/*
ListaFilmova& Korisnik::ucitaj_historiju(){
  string temp = this->getRacun().getUsername();
  return ucitaj_historiju1(temp);
}*/

std::ostream& operator<<(std::ostream& izlaz, const Korisnik& korisnik){
    izlaz<< korisnik._ime << " " << korisnik._prezime << " " << korisnik._jmbg << " " << korisnik._datum << " " << korisnik._racun << std::endl;
    return izlaz;
}
