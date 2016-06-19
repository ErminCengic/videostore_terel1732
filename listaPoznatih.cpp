#include "listaPoznatih.h"

Poznati ListaPoznatih::pretrazi_poznate(const string& ime) const{
      Cvor<Poznati>* temp = first;
	   Poznati prazan;
      while(temp!=nullptr){
	if(temp->getInfo().getIme() == ime)
		return temp->getInfo();
	temp = temp->getLink();
}
cout <<"Nema trazene osobe! " << endl;
return prazan;
}

Cvor<Poznati>* ListaPoznatih::nadji_poznate(const string& prezime) const{
     Cvor<Poznati>* current = first;
     while(current!=nullptr){
       if(current->getInfo().getPrezime() == prezime)
         return current;
         current = current->getLink();
     }
       return nullptr;
}

std::ostream& ListaPoznatih::operator<<(std::ostream& izlaz){
  Cvor<Poznati>* temp = first;
  while(temp!=nullptr){
  izlaz << temp->getInfo().getIme() << " " << temp->getInfo().getPrezime() << " , ";
  temp = temp->getLink();
  }
  return izlaz;
}

Cvor<Poznati>* ListaPoznatih::nadji(){
return first;
}
