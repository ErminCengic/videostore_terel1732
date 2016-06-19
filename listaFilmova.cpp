#include "listaFilmova.h"

void ListaFilmova::ispisi_filmove() const{
    Cvor<Film>* temp = first;
    while(temp!=nullptr){
        std::cout << temp->getInfo() << std::endl;
        temp = temp->getLink();
    }
}

Cvor<Film>* ListaFilmova::nadji_film(int kljuc) const {
      Cvor<Film>* current = first;
      int brojac = 0;
      while(current!=nullptr){
          if(current->getInfo().getId() ==kljuc){
            ++brojac;
          break;}
        else
            current = current->getLink();
      }
      if(brojac ==0)
        return nullptr;
      else return current;
}

Cvor<Film>* ListaFilmova::nadji_film(const string& naziv) const{
      Cvor<Film>* current = first;
      Cvor<Film>* trailCurrent = first;
      int brojac = 0;
      ListaFilmova temp;
      while(current!=nullptr){
        if(current->getInfo().getNaziv() == naziv){
            ++brojac;
            if(brojac ==1)
              trailCurrent = current;
            temp.insertLast(current->getInfo());
        }
        current = current->getLink();
      }
      if(brojac==1)
        return trailCurrent;
      else if(brojac>1){
        std::cout << "Postoji " << brojac << " filmova sa navedenim nazivom: " << std::endl;
        temp.ispisi_filmove();
        int kljuc;
        std::cout << " Unesite kljuc: ";
        cin>>kljuc;
        cin.clear();;
        current = nadji_film(kljuc);
        return current;
      }
     else return nullptr;
}

Film ListaFilmova::pretrazivanje_filmova(const string& naziv){
      Cvor<Film>* temp = nadji_film(naziv);
      if(temp == nullptr){
          Film film;
          std::cout << "Nema trazenog filma!" << std::endl;
          return film;
      }
      return temp->getInfo();
}

void ListaFilmova::izbrisi_film(Film& film){
      deleteNode(film);
}

void ListaFilmova::dodaj_film(Film& film){
    insertLast(film);
}


void ListaFilmova::sortiraj_filmove() {
      for(int i = 0; i < count; ++i){
          Cvor<Film>* temp = first;
          if(temp == nullptr)
            break;
          while(temp->getLink()!= nullptr){
            if(temp->getInfo().getGod() < temp->getLink()->getInfo().getGod()){
                Film novi = temp->getInfo();
                temp->getInfo() = temp->getLink()->getInfo();
                temp->getLink()->getInfo() = novi;
            }
            temp = temp->getLink();
          }
      }
}

Film ListaFilmova::posudi_film(const std::string& naziv){
    Film temp = pretrazivanje_filmova(naziv);
    if(temp.getKopije() <= 0){
      cout << "Trenutno su svi filmovi sa trazenim nazivom izdati!" << endl;
    }
    if(temp.getId() != 1000){
        temp.setKopije(temp.getKopije()-1);
	izbrisi_film(temp);
	dodaj_film(temp);
    }
	upisivanje_filmova();
    return temp;

}

void ListaFilmova::vrati_film(Film& film){
        film.setKopije(film.getKopije()+1);
	izbrisi_film(film);
	dodaj_film(film);
	upisivanje_filmova();
    
}

Cvor<Film>* ListaFilmova::nadji(){
	return first;
}


