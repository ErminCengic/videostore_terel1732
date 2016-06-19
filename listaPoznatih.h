#ifndef _LISTAPOZNATIH_H
#define _LISTAPOZNATIH_H

#include "poznati.h"
#include "jednostruka.hxx"

class ListaPoznatih : public linkedListType<Poznati>{
      public:
        ListaPoznatih() = default;
        Poznati pretrazi_poznate(const string&) const;
        Cvor<Poznati>* nadji_poznate(const string&) const;
        std::ostream& operator<<(std::ostream&);
Cvor<Poznati>* nadji();
        ~ListaPoznatih() = default;
};

#endif


