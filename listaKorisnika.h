#ifndef _LISTAKORISNIKA_H
#define _LISTAKORISNIKA_H

#include "korisnik.h"

class ListaKorisnika : public linkedListType<Korisnik>{
   public:
      void dodaj_korisnika(Korisnik&);
      void izbrisi_korisnika(Korisnik&);
      Cvor<Korisnik>* nadji_korisnika(const string&) const;
      Cvor<Korisnik>* nadji_korisnika(const string&, const string&) const;
      void sortiraj_korisnike();
      Korisnik pretrazivanje_korisnika(const string&,const string&);  
      Korisnik pretrazivanje_korisnika(const string&);
      void ispisi_korisnike() const;
      void upisivanje_korisnika();
      void upisivanje_historije();
      void upisivanje_posudjenih();
};

#endif
