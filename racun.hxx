#ifndef _RACUN_H
#define _RACUN_H

#include <iostream>

class Racun{
  private: 
        std::string _korisnickoIme, _lozinka;
  public:
        Racun() = default;
        Racun(const std::string&, const std::string&);
        std::string getUsername() const { return _korisnickoIme; }
        std::string getLozinka() const { return _lozinka; }
        void setUsername(const std::string& ime) { _korisnickoIme = ime; }
        void setLozinka(const std::string& lozinka) { _lozinka = lozinka; }
        ~Racun() = default;
};

Racun::Racun(const std::string& ime, const std::string& lozinka){
      _korisnickoIme = ime;
      _lozinka = lozinka;
}


#endif
