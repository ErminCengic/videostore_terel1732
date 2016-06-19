#include "film.h"

Film::Film(const std::string& naziv,int god,Poznati& reziser,const std::string& kompanija,int kopije,int id, ListaPoznatih& glumci,ListaPoznatih& producenti,ListaPoznatih& scenaristi,const std::string& opis){
      _naziv = naziv;
      _godIzdavanja = god;
      _reziser = reziser;
      _kompanija = kompanija;
      _kopije = kopije;
      _id = id;
      _glumci = glumci;
      _producenti = producenti;
      _scenaristi = scenaristi;
      _opis = opis;
}

std::string Film::getNaziv() const {return _naziv;}
std::string Film::getOpis() const {return _opis;}
std::string Film::getKompanija() const {return _kompanija;}
int Film::getGod() const {return _godIzdavanja;}
int Film::getKopije() const {return _kopije;}
const Poznati& Film::getReziser() const {return _reziser;}
const ListaPoznatih& Film::getProducenti() const {return _producenti;}
const ListaPoznatih& Film::getScenaristi() const {return _scenaristi;}
const ListaPoznatih& Film::getGlumci() const {return _glumci;}

int Film::getId() const {return _id;}
void Film::setNaziv(const std::string& naziv) {_naziv = naziv;}
void Film::setOpis(const std::string& opis) {_opis = opis;}
void Film::setKompanija(const std::string& kompanija) {_kompanija = kompanija;}
void Film::setGod(int godina) {_godIzdavanja = godina;}
void Film::setKopije(int kopije) {_kopije = kopije;}
Film& Film::setReziser(Poznati& reziser) {_reziser = reziser; return *this;}
Film& Film::setProducenti(ListaPoznatih& producenti) {_producenti = producenti; return *this;}
Film& Film::setScenaristi(ListaPoznatih& scenaristi) {_scenaristi = scenaristi; return *this;}
Film& Film::setGlumci(ListaPoznatih& glumci) {_glumci = glumci; return *this;}
void Film::setId(int id) {_id = id;}

std::ostream& operator<<(std::ostream& izlaz, const Film& film){
      izlaz << film._naziv << ", " << film._godIzdavanja << ", " << film._reziser << ", ";
      izlaz << film._kompanija << ", " << film._kopije << ", Kljuc: " << film._id << std::endl;
      izlaz << "Glumci: " << std::endl;
      film._glumci.print();
      izlaz << std::endl;
      izlaz << "Producenti: " << std::endl;
      film._producenti.print();
      izlaz << std::endl;
      izlaz << "Scenaristi: " << std::endl;
      film._scenaristi.print();
      izlaz << std::endl << film._opis << std::endl;

  return izlaz;
}

bool operator==(const Film& prvi, const Film& drugi){
    return (prvi.getId() == drugi.getId());
}

bool operator!=(const Film& prvi, const Film& drugi){
    return (prvi.getId() != drugi.getId());
}

