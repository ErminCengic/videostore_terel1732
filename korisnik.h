#ifndef _KORISNIK_H
#define _KORISNIK_H

#include "datum.h"
#include "racun.h"
#include "listaFilmova.h"

class Korisnik{
      friend std::ostream& operator<<(std::ostream&,const Korisnik&);
    private:
        std::string _ime, _prezime, _jmbg;
        Datum _datum;
        Racun _racun;
        ListaFilmova _posudjeni;
        ListaFilmova _historija;
    public:
        Korisnik();
        Korisnik(const std::string&, const std::string&, const std::string&, const Datum&, const Racun&);
        std::string getIme() const;
        std::string getPrezime() const;
        std::string getJmbg() const;
        void setIme(const std::string&);
        void setPrezime(const std::string&);
        void setJmbg(const std::string&);
        const Racun& getRacun() const;
        Korisnik& setRacun(Racun&);
        const  Datum& getDatum() const;
        Korisnik& setDatum(Datum&); 
        const ListaFilmova& getPosudjeni() const;
        Korisnik& setPosudjeni(ListaFilmova&);
        const ListaFilmova& getHistorija() const;
        Korisnik& setHistorija(ListaFilmova&);
        bool validan_jmbg(const std::string&);   
        void korisnik(int);
      //  ListaFilmova& ucitaj_historiju();
        ~Korisnik() = default;
};



bool operator==(const Korisnik&,const Korisnik&);
bool operator!=(const Korisnik&, const Korisnik&);

#endif
