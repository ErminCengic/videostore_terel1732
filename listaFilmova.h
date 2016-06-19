#ifndef _LISTAFILMOVA_H
#define _LISTAFILMOVA_H

#include "film.h"
//#include "jednostruka.hxx"

class ListaFilmova : public linkedListType<Film>{
      public:
        void sortiraj_filmove();
        void dodaj_film(Film&);
       
        void izbrisi_film(Film&);
        Film pretrazivanje_filmova(const std::string&);
        Cvor<Film>* nadji_film(const string&) const;
        Cvor<Film>* nadji_film(int) const;
        void ispisi_filmove() const;
        void azuriranje_filmova();
        Film posudi_film(const std::string&);
        void vrati_film(Film&);
	Cvor<Film>* nadji();
        void upisivanje_filmova();
};

#endif
