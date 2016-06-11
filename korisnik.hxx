#ifndef _KORISNIK_H
#define _KORISNIK_H

#include "datum.hxx"
#include "listaNiz.hxx"
//#include "film.hxx"
#include "racun.hxx"

class Korisnik{
    private:
        std::string _ime, _prezime, _jmbg;
        Datum _datum;
        Racun _racun;
  //      ListaNizom<Film> _posudjeni;
  //      ListaNizom<Film> _historija;
    public:
        Korisnik();
        Korisnik(const std::string&, const std::string&, const std::string&);
        std::string getIme() const { return _ime; }
        std::string getPrezime() const { return _prezime; }
        
       const Racun& getRacun() const {return _racun;}
        Korisnik& setRacun(Racun racun){_racun = racun; return *this;}
      const  Datum& getDatum() const {return _datum;}
        Korisnik& setDatum(Datum datum){_datum = datum; return *this;}        
        ~Korisnik() = default;

};

Korisnik::Korisnik(){
    Datum();
    Racun();
}

Korisnik::Korisnik(const std::string& ime, const std::string& prezime, const std::string& jmbg){
        _ime = ime;
        _prezime = prezime;
        _jmbg = jmbg;
}


#endif 
