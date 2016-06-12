#ifndef _KORISNIK_H
#define _KORISNIK_H

#include "datum.hxx"
#include "listaNiz.hxx"
//#include "film.hxx"
#include "racun.hxx"

class Korisnik{
      friend std::ostream& operator<<(std::ostream&,const Korisnik&);
    private:
        std::string _ime, _prezime, _jmbg;
        Datum _datum;
        Racun _racun;
  //      ListaNizom<Film> _posudjeni;
  //      ListaNizom<Film> _historija;
    public:
        Korisnik();
        Korisnik(const std::string&, const std::string&, const std::string&, const Datum&, const Racun&);
        std::string getIme() const { return _ime; }
        std::string getPrezime() const { return _prezime; }
        std::string getJmbg() const {return _jmbg;}
        void setIme(const std::string& ime) {_ime = ime;}
        void setPrezime(const std::string& prezime) {_prezime = prezime;}
        void setJmbg(const std::string& jmbg) {_jmbg = jmbg;}
       const Racun& getRacun() const {return _racun;}
        Korisnik& setRacun(Racun racun){_racun = racun; return *this;}
       const  Datum& getDatum() const {return _datum;}
        Korisnik& setDatum(Datum datum){_datum = datum; return *this;}  
        bool validan_jmbg(const std::string&);
        ~Korisnik() = default;
};

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

std::ostream& operator<<(std::ostream& izlaz, const Korisnik& korisnik){
    izlaz<< korisnik._ime << " " << korisnik._prezime << " " << korisnik._jmbg << " " << korisnik._datum << " " << korisnik._racun << std::endl;
    return izlaz;
}

#endif 
