#ifndef _LISTAKORISNIKA_H
#define _LISTAKORISNIKA_H

#include "jednostruka.hxx"
#include "korisnik.hxx"

class ListaKorisnika : public list<Korisnik>{
   public:
      void dodaj_korisnika(Korisnik&);
      void izbrisi_korisnika(Korisnik&);
      bool nadji_korisnika(Korisnik&) const;
      ListaKorisnika& sortiraj_korisnike();
      Korisnik pretrazivanje_korisnika(const string&,const string&);  
      Korisnik pretrazivanje_korisnika(const string&);
      
    
};

bool ListaKorisnika::nadji_korisnika(Korisnik& korisnik) const{
      auto pocetak = this->begin();
      auto kraj = this->end();
      while(pocetak!=kraj){
        if((*pocetak).getInfo().getIme() == korisnik.getIme()){
          if((*pocetak).getInfo().getPrezime() ==korisnik.getPrezime()){
            if((*pocetak).getInfo().getRacun().getUsername() == korisnik.getRacun().getUsername())
              return true;
          }
        }
        ++pocetak;
      }
    return false;
}

void ListaKorisnika::dodaj_korisnika(Korisnik& novi){
      if(!nadji_korisnika(novi))
        push_back(novi);
      else
        std::cout << "Korisnik kojeg zelite vec ima racun u videoteci!" << std::endl;
}

Korisnik ListaKorisnika::pretrazivanje_korisnika(const string& ime, const string& prezime){
      auto pocetak = this->begin();
      auto kraj = this->end();
      int brojac = 0;
      Korisnik temp;
      while(pocetak!=kraj){
          if((*pocetak).getInfo().getIme() == ime && (*pocetak).getInfo().getPrezime() == prezime)
          {
            ++brojac;
            temp = (*pocetak).getInfo();
         }
      ++pocetak;
      }
    if(brojac==1)
      return temp;
    else{
      std::cout << "Postoji vise korisnika sa trazenim imenom i prezimenom. Unesite username: ";
      string username;
      std::cin >> username;
      temp = pretrazivanje_korisnika(username);
      return temp;
    }
}

Korisnik ListaKorisnika::pretrazivanje_korisnika(const string& username){
    auto pocetak = this->begin();
    auto kraj = this->end();
    Korisnik temp;
    while(pocetak!=kraj){
        if((*pocetak).getInfo().getRacun().getUsername() == username)
          temp = (*pocetak).getInfo();
    }
    return temp;
}

void ListaKorisnika::izbrisi_korisnika(Korisnik& korisnik){
    if(nadji_korisnika())
    {

    }
}


#endif
