#ifndef _FILM_H
#define _FILM_H

//#include "poznati.h"
//#include "jednostruka.hxx"
#include "listaPoznatih.h"

class Film{
  friend std::ostream& operator<<(std::ostream&,const Film&);
    private:
      std::string _naziv, _kompanija, _opis;
      Poznati _reziser;
      ListaPoznatih _producenti, _scenaristi, _glumci;
      int _godIzdavanja, _kopije;
      int _id = 1000;
    public:
      Film() = default;
      Film(const std::string&,int,Poznati&,const std::string&,int,int, ListaPoznatih&,ListaPoznatih&,ListaPoznatih&,const std::string&);
      std::string getNaziv() const;
      std::string getOpis() const;
      std::string getKompanija() const;
      int getGod() const;
      int getKopije() const;
      const Poznati& getReziser() const;
      const ListaPoznatih& getProducenti() const;
      const ListaPoznatih& getScenaristi() const;
      const ListaPoznatih& getGlumci() const;

      int getId() const;
      void setNaziv(const std::string&);
      void setOpis(const std::string&);
      void setKompanija(const std::string&);
      void setGod(int);
      void setKopije(int);
      Film& setReziser(Poznati&);
      Film& setProducenti(ListaPoznatih&);
      Film& setScenaristi(ListaPoznatih&);
      Film& setGlumci(ListaPoznatih&);
      void setId(int);
      ~Film() = default;
};

bool operator==(const Film&, const Film&);
bool operator!=(const Film&, const Film&);


#endif
