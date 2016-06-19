#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <string>
using namespace std;

template <class Type>
class Cvor
{
	private:
		Type info;
		Cvor* link;
	public:
		Type& getInfo() {return info;}
		Cvor* getLink() {return link;}
		void setInfo(Type T) {info=T;}
		void setLink(Cvor* L) {link=L;}
};


template <class Type>
class linkedListType
{
	public:
		const linkedListType<Type>& operator=(const linkedListType<Type>&);
		void initializeList();
		bool isEmptyList() const;
		void print() const;
		int length() const;
		void destroyList();
		Type front() const;
		Type back() const;
		
		bool search(const Type& searchItem) const;
		void insertFirst(const Type& newItem);
		void insertLast(const Type& newItem);
    void insertNovi(const Type& newItem);
		void deleteNode(const Type& deleteItem);
		
		linkedListType();
		linkedListType(const linkedListType<Type>& otherList);
		linkedListType(linkedListType<Type>&& otherList);
		const linkedListType<Type>& operator=(linkedListType<Type>&&);
		
		~linkedListType();

	protected:
		int count; //varijabla za pohranu veličine liste
		Cvor<Type> *first; //pokazivač na prvi čvor u listi
		Cvor<Type> *last; //pokazivač na posljednji čvor u listi

	private:	
		void copyList(const linkedListType<Type>& otherList);

};

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return (first == nullptr);//lista je prazna ako je first nullptr
}

template <class Type>
linkedListType<Type>::linkedListType() //default konstruktor : rezultat first i last imaju vrijednost nullptr, a veličina je 0
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
	Cvor<Type> *temp; //pokazivač pomoću kojeg ćemo obrisati čvor

	while (first != nullptr)//dok ima čvorova u listi
	{
		temp = first;//postavi temp na trenutni čvor
		first = (*first).getLink(); //preusmjeri first na naredni čvor
		delete temp;//dealociraj memoriju zauzetu čvorom
	}

	last = nullptr; //postavi last na nullptr jer smo ispraznili listu, first je već postavljen u petlji
	count = 0;//postavi veličinu na 0 jer smo ispraznili listu
}

template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //obriši sve čvorove iz liste
}

template <class Type>
void linkedListType<Type>::print() const
{
	Cvor<Type> *current; //pokazivač za prolazak kroz listu
	current = first; //kreni od prvog čvora

	while (current != nullptr) //dok ima elemenata
	{
		cout << (*current).getInfo() << ", ";//ispiši info dio
		current = (*current).getLink();//pomjeri pokazivač na naredni čvor
	}
}//end print

template <class Type>
int linkedListType<Type>::length() const
{
	return count;//vrati veličinu liste
}

template <class Type>
Type linkedListType<Type>::front() const
{
	if(first==nullptr) throw string("There are no elements in list!");
	else return (*first).getInfo(); //ako lista nije prazna, vrati info dio prvog čvora
}//end front

template <class Type>
Type linkedListType<Type>::back() const
{

	if(last==nullptr) throw string("There are no elements in list!");
	return (*last).getInfo(); //ako lista nije prazna, vrati info dio zadnjeg čvora
}//end back

template <class Type>
bool linkedListType<Type>::search(const Type& searchItem) const
{
	bool found = false;
	Cvor<Type> *current; //pokazivač za prolazak kroz listu
	current = this->first;	//počni pretragu od prvog čvora u listi

	while (current != nullptr && !found) //dok ima elemenata za pretragu i dok ne nađemo element kojeg tražimo
		if ((*current).getInfo() == searchItem)// ako je na trenutnom čvoru info dio jednak traženom, našli smo željeni čvor
			found = true;
		else
			current = (*current).getLink(); //ako nije, onda pomjeri pokazivač na sljedeći čvor
	
	return found;
}//end search

template <class Type>
void linkedListType<Type>::insertFirst(const Type& newItem)
{
	Cvor<Type> *newNode;  //pokazivač za kreiranje novog čvora
	newNode = new Cvor<Type>; //kreiraj novi čvor
	(*newNode).setInfo(newItem);//postavi info dio novog čvora
	(*newNode).setLink(this->first);//postavi link dio novog čvora na trenutni prvi čvor u listi
	this->first = newNode;	//postavi first da pokazuje na trenutni prvi čvor
	this->count++;	//povećaj veličinu
	if (this->last == nullptr) //ako je lista bila prazna, onda je ovo prvi element u listi i također posljednji, pa last treba da pokazuje na taj novi čvor
		this->last = newNode;
}//end insertFirst


template<typename Type>
void linkedListType<Type>::insertNovi(const Type& newItem){
  Cvor<Type>* newNode;
  newNode = new Cvor<Type>;
  newNode->setInfo(newItem);
  newNode->setLink(nullptr);
  int br = 0;
  Cvor<Type>* temp = first;
  if(first == nullptr){
    first = newNode;
    last = newNode;
    count++;
    return;
  }
   if(temp->getLink() == nullptr)
  {
      if(temp->getInfo().getGod() <= newNode->getInfo().getGod()){
          first = newNode;
          newNode->setLink(temp);
          last = temp;
          ++count;
        }
    else{
      last->setLink(newNode);
      last = newNode;
      ++count;
    }

  }
  else{
      while(temp!=nullptr){
      ++br;
      Cvor<Type>* temp1 = temp;
      if(temp->getInfo().getGod() <= newNode->getInfo().getGod()){
          Cvor<Type> * temp2 = temp;
          if(br == 1){
            first = newNode;
            newNode->setLink(temp);
            
          }
          else{
          temp->setLink(temp2->getLink());
          newNode->setLink(temp2);
          }
          ++count;
          return;
       }
        else
          temp = temp->getLink();
    }
    last->setLink(newNode);
    last = newNode;
    ++count;
  }

}

template <class Type>
void linkedListType<Type>::insertLast(const Type& newItem)
{
	Cvor<Type> *newNode;  //pokazivač za kreiranje novog čvora
	newNode = new Cvor<Type>; //kreiraj novi čvor
	(*newNode).setInfo(newItem);	//postavi info dio novog čvora
	(*newNode).setLink(nullptr);//postavi link novog čvora na nullptr vrijednost jer će biti posljednji u listi
	if (this->first == nullptr) //ako je lista prazna, novi čvor će biti ujedno i prvi, i postavi first i last da pokazuju na taj novi čvor
	{
		this->first = newNode;
		this->last = newNode;
		this->count++; //povećaj veličinu
	}
	else
	//lista nije prazna, ubaci element na kraj
	{
		this->last->setLink(newNode); //ubaci novi element na kraj (trenutno posljednjem elementu postavi link na novi čvor)
		this->last = newNode; //postavi last da pokazuje na novi čvor jer je on sada posljednji
		this->count++; //povećaj veličinu
	}
}//end insertLast


template <class Type>
void linkedListType<Type>::deleteNode(const Type& deleteItem)
{
	Cvor<Type> *current; //pokazivač za prolazak kroz listu
	Cvor<Type> *trailCurrent; //pokazivač na čvor prije trenutnog
	bool found;
	if (this->first == nullptr) //Case 1; lista je prazna.
		cout << "Videoteka nema korisnika."<< endl;
	else
	{
	if (this->first->getInfo() == deleteItem) //Case 2
	{ 	//brišemo prvi čvor u listi
		current = this->first; //postavi pokazivač trenutni na prvi čvor
		this->first = this->first->getLink();   //preusmjeri first na drugi čvor
		this->count--; //smanji veličinu
		if (this->first == nullptr) //ako je to bio jedini čvor, last je pokazivao na njega, sad treba postaviti ga na nullptr
			this->last = nullptr;
		
		delete current;//obriši čvor
	}
	else //pretraži listu da se nađe čvor kojeg treba obrisati
	{
		found = false;
		trailCurrent = this->first; //postavi trailCurrent da pokazuje na prvi čvor
		current = this->first->getLink(); //postavi current da pokazuje na drugi čvor

		while (current != nullptr && !found)//dok ne dođemo do kraja i ne nađemo šta tražimo
		{
			if (current->getInfo() != deleteItem) //pomjeraj se kroz listu dalje dok ne nađemo element kojeg želimo obrisati
			{
				trailCurrent = current;
				current = current->getLink();
			}
			else
				found = true;
		}//end while
		if (found) //Case 3; ako smo našli element kojeg želimo obrisati, current pokazuje na čvor kojeg želimo obrisati
		{
			trailCurrent->setLink(current->getLink()); //trailcurrent pokazuje na čvor prije čvora kojeg želimo obrisati
			//tom čvoru postavi link da čvor koji se nalazi iza čvora kojeg želimo obrisati
			this->count--;//smanji veličinu
			if (this->last == current) //čvor kojeg želimo obrisati je bio posljednji u listi
				this->last = trailCurrent; // postavi last da pokazuje na trenutno predzadnji čvor u listi

			delete current; //obriši čvor
		}
		else //čvor kojeg želimo obrisati nije u listi
			cout << "Korisnik nije clan videoteke!" << endl;
	}//end else
	}//end else
}//end deleteNode

template <class Type>
void linkedListType<Type>::copyList (const linkedListType<Type>& otherList)
{
	Cvor<Type> *newNode; //pokazivač za kreiranje čvora
	Cvor<Type> *current; //pokazivač za prolazak kroz listu
	if (first != nullptr) //ako lista nije prazna, isprazni je
		destroyList();
	if (otherList.first == nullptr) //ako je druga lista prazna, i rezultujuća treba da bude
	{
		first = nullptr;
		last = nullptr;
		count = 0;
	}
	else
	{
		current = otherList.first; //current pokazuje na listu iz koje kopiramo elemente, trenutno na njen prvi čvor
		count = otherList.count; //postavi veličinu rezultujuće liste 
		first = new Cvor<Type>; //kreiraj novi čvor i postavi first da pokazuje na taj čvor
		(*first).setInfo((*current).getInfo()); //kopiraj info dio
		(*first).setLink(nullptr); //postavi link dio na nullptr
		last = first; //postavi last da pokazuje na prvi čvor (novi čvor)
		current = (*current).getLink(); //pomjeri current na drugi čvor u proslijeđenoj listi
		//kopiraj ostatak liste
		while (current != nullptr) //dok ima elemenata u proslijeđenoj listi
		{
			newNode = new Cvor<Type>; //kreiraj novi čvor 
			(*newNode).setInfo((*current).getInfo()); //kopiraj info
			(*newNode).setLink(nullptr); //postavi link dio na nullptr
			(*last).setLink(newNode); //ubaci novi čvor poslije posljednjeg čvora u listi
			last = newNode; //postavi last da pokazuje na stvarni zadnji čvor (novi čvor)
			current = (*current).getLink();//pomjeri current na naredni čvor u proslijeđenoj listi
		}//end while
	}//end else
}//end copyList

template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
	destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
	first = nullptr;
	copyList(otherList);
}//end copy constructor

//overload operatora =
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
	if (this != &otherList) //izbjegni samokopiranje
	{
		copyList(otherList);
	}//end if
	return *this;
}



#endif

