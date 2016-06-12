#ifndef _LISTAKORISNIKA_H
#define _LISTAKORISNIKA_H

#include "jednostruka.hxx"
#include "korisnik.hxx"

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
};

void ListaKorisnika::sortiraj_korisnike(){
       for(int i =0; i < count; ++i){
      Cvor<Korisnik>* temp = first;
      Cvor<Korisnik>* current = first;
      while(temp!=nullptr){
      while(current->getLink()!=nullptr){
        if(current->getInfo().getDatum().getGod() < current->getLink()->getInfo().getDatum().getGod()){
            Korisnik temp = current->getInfo();
            current->getInfo() = current->getLink()->getInfo();
            current->getLink()->getInfo() = temp;}
        else if(current->getInfo().getDatum().getGod() == current->getLink()->getInfo().getDatum().getGod() && current->getInfo().getDatum().getMjesec() < current->getLink()->getInfo().getDatum().getMjesec()){
            Korisnik temp = current->getInfo();
            current->getInfo() = current->getLink()->getInfo();
            current->getLink()->getInfo() = temp;}
        else if(current->getInfo().getDatum().getGod() == current->getLink()->getInfo().getDatum().getGod() && current->getInfo().getDatum().getMjesec() == current->getLink()->getInfo().getDatum().getMjesec() && current->getInfo().getDatum().getDan() < current->getLink()->getInfo().getDatum().getDan()){
            Korisnik temp = current->getInfo();
            current->getInfo() = current->getLink()->getInfo();
            current->getLink()->getInfo() = temp;}

        current = current->getLink();
        }
        temp = temp->getLink();
      }
      }
}

Cvor<Korisnik>* ListaKorisnika::nadji_korisnika(const string& username) const{
     Cvor<Korisnik>* current = first;
     int brojac = 0;
     while(current!=nullptr){
        if(current->getInfo().getRacun().getUsername() == username){
          ++brojac;
          break;}
        else{
            current = current->getLink();
        }
     }
     if(brojac==0)
     {
       return nullptr;
     }
     return current;
}

Cvor<Korisnik>* ListaKorisnika::nadji_korisnika(const string& ime, const string& prezime) const{
       Cvor<Korisnik>* current = first;
       Cvor<Korisnik>* trailCurrent = first;
       int brojac = 0;
       while(current!=nullptr){
        if(current->getInfo().getIme() == ime && current->getInfo().getPrezime() == prezime){
          ++brojac;
          if(brojac==1){
            trailCurrent = current;
          }
        }
            current = current->getLink();
     }
       if(brojac>1){
      std::cout << "Postoji " << brojac << " korisnika sa trazenim imenom i prezimenom, unesite username: " << std::endl;
      string username;
      std::cin>>username;
      current = nadji_korisnika(username);
      return current;}
       else if(brojac==1)
         return trailCurrent;
       else {
         return nullptr;
       }
}

void ListaKorisnika::dodaj_korisnika(Korisnik& novi){
      if(nadji_korisnika(novi.getRacun().getUsername())==nullptr)
        insertLast(novi);
      else
        std::cout << "Korisnik kojeg zelite unijeti vec ima racun u videoteci!" << std::endl;
}

Korisnik ListaKorisnika::pretrazivanje_korisnika(const string& ime, const string& prezime){
     Cvor<Korisnik>* temp = nadji_korisnika(ime,prezime);
     if(temp == nullptr){
        Korisnik korisnik;
        std::cout <<"Nema trazenog korisnika!" << std::endl;
        return korisnik;
     }
     return temp->getInfo();
}

Korisnik ListaKorisnika::pretrazivanje_korisnika(const string& username){
     Cvor<Korisnik>* temp = nadji_korisnika(username);
     if(temp == nullptr){
       Korisnik korisnik;
       std::cout <<"Nema trazenog korisnika!" << std::endl;
        return korisnik;
     }
     return temp->getInfo();
}

void ListaKorisnika::izbrisi_korisnika(Korisnik& korisnik){
    deleteNode(korisnik);
}

void ListaKorisnika::ispisi_korisnike() const{
      Cvor<Korisnik>* temp = first;
      while(temp!=nullptr){
          std::cout << temp->getInfo() << std::endl;
          temp = temp->getLink();
      }
}


#endif
