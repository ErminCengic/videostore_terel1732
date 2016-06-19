#ifndef _DATUM_H
#define _DATUM_H

#include <iostream>

class Datum{  
    friend std::ostream& operator<<(std::ostream&, const Datum&);
    private:
      int _godina, _mjesec;
      int _dan=0;
    public: 
      Datum() = default;
      Datum(int,int,int);
      int getGod() const;
      int getMjesec() const;
      int getDan() const;
      void setDan(int);
      ~Datum() = default;
};

#endif
