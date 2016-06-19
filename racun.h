#ifndef _RACUN_H
#define _RACUN_H

#include <iostream>

class Racun{
    friend std::ostream& operator<<(std::ostream&, const Racun&);
  private: 
        std::string _korisnickoIme, _lozinka;
  public:
        Racun() = default;
        Racun(const std::string&, const std::string&);
        std::string getUsername() const;
        std::string getLozinka() const;
        void setUsername(const std::string&);
        void setLozinka(const std::string&);
        bool validnost_lozinke(const std::string&);
        bool validnost_username(const std::string&);
        ~Racun() = default;
};

#endif
