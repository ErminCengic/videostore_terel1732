#ifndef _POZNATI_H
#define _POZNATI_H

#include <iostream>

class Poznati{
  friend std::ostream& operator<<(std::ostream&,const Poznati&);
  private:
      std::string _ime;
      std::string _prezime;
     public:
      Poznati() = default;
      Poznati(const std::string& , const std::string&);
      void setIme(const std::string&);
      void setPrezime(const std::string&);
      std::string getIme() const;
      std::string getPrezime() const;
      ~Poznati() = default;
};


#endif
