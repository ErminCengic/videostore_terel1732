#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include "node1.hxx"

using namespace std;

template <typename Type>
class list
{
    public:
        class iterator;
        class const_iterator;

        size_t size() const;  // Vraca velicinu liste, tj. broj elemenata || slozenost O(1)
        bool empty() const; // Vraca bool vrijednost (da li je lista prazna), tj. da li first pokazuje na nullptr || slozenost 0(1)


        void clear(); // Briše sve elemente iz liste i postavlja velicinu na 0 || slozenost O(n)

        void push_back(const Type& val); // dodaje elemenat na kraj liste, elemenat se prosljeđuje po const referenci || slozenost O(1)
        void push_back(Type&& val); // dodaje elemenat na kraj liste, elemenat se prosljeđuje kao rvalue (&& ), move || slozenost O(1)

        void push_front(const Type& elem); // dodaje elemenat na pocetak liste, elemenat se prosljeđuje po const referenci || slozenost O(1)
        void push_front(Type&& val); // dodaje elemenat na pocetak liste, elemenat se prosljeđuje kao rvalue (&& ), move || slozenost O(1)
        void pop_back(); // Brise zadnji elemenat u listi, smanjuje broj elemenata  za 1 || slozenost O(n)
        void pop_front(); // Brise prvi elemenat u listi, smanjuje broj elemenata za 1 || slozenost O(1)

        iterator insert (const_iterator position, const Type& val); // ubacuje elemenat (prosljedjen po const referenci) na poziciju poslije prosljedjene (position) || slozenost O(1)
        iterator insert (const_iterator position, Type&& val); // ubacuje elemenat (prosljedjen kao rvalue (move)) na poziciju poslije prosljedjene (position) || slozenost 0(1)


        Type front();   // Vraca elemenat koji se nalazi na prvom mjestu u listi || slozenost O(1)
        const Type& front() const; // Vraca referencu na prvi elemenat u listi || slozenost O(1)
        Type back(); // Vraca zadnji elemenat u listi || slozenost O(1)
        const Type& back() const; // Vraca zadnji elemenat u listi po const referenci || slozenost O(1)


        iterator begin() { return (iterator(first));} // Vraca iterator na pocetak liste || slozenost O(1)
        const_iterator begin() const { return (iterator(first));} // Vraca const iterator na pocetak liste || slozenost O(1)
        iterator end() { return (iterator(last->getNext()));}  // Vraca iterator na zadnji elemenat liste || slozenost O(1)
        const_iterator end() const { return (iterator(last->getNext()));} // Vraca const iterator na zadnji elemant liste || slozenost O(1)


        list(); // Default konstruktor || slozenost O(1)
        list (const list& x); // Copy constructor || slozenost O(n)
        list (list&& x); // Move constructor || slozenost O(n)
        ~list(); // destruktor, brise elemente || slozenost O(n)
        list& operator= (const list& x); // The copy assignment || slozenost O(n)
        list& operator= (list&& x); // The move assignment || slozenost O(n)
        void print() const; // ispisuje elemente || slozenost O(n)
    private:
        void kopiraj(const list<Type>& druga); // kopira elemente iz jedne liste u drugu || slozenost O(n)
		size_t count; // Number of elements in list
		nodeType<Type> *first; // Pointer to the first element of list
		nodeType<Type> *last; // Pointer to the last element of list
};

template<typename Type>
void list<Type>::print() const{
      nodeType<Type>* temp;
      temp = this->first;
      while(temp!=nullptr)
      {
        std::cout << (*temp).getInfo() << std::endl;
        temp = (*temp).getNext();
      }
}
template<typename Type>
size_t list<Type>::size() const{
    return count;
}

template<typename Type>
bool list<Type>::empty() const{
    return (first == nullptr);
}

template<typename Type>
void list<Type>::clear(){
    nodeType<Type> *temp;
    while(first != nullptr)
    {
        temp = first;
        first = (*first).getNext();
        delete temp;
    }
    last = nullptr;
    count = 0;
}

template<typename Type>
void list<Type>::push_back(const Type& val){
    nodeType<Type> *temp;
    temp = new nodeType<Type>;
    (*temp).setInfo(val);
    (*temp).setNext(nullptr);
    if ( this->first == nullptr)
    {
        this->first = temp;
        this->last = temp;
        this->count++;
    }
    else
    {
        this->last->setNext(temp);
        this->last = temp;
        this->count++;
    }
}

template<typename Type>
void list<Type>::push_back(Type&& val){
    nodeType<Type> *temp;
    temp = new nodeType<Type>;
    (*temp).setInfo(val);
    (*temp).setNext(nullptr);
    if ( this->first == nullptr)
    {
        this->first = temp;
        this->last = temp;
        this->count++;
    }
    else
    {
        this->last->setNext(temp);
        this->last = temp;
        this->count++;
    }
}

template<typename Type>
void list<Type>::push_front(const Type& val){
    nodeType<Type> *temp;
    temp = new nodeType<Type>;
    (*temp).setInfo(val);
    (*temp).setNext(this->first);
    this->first = temp;
    this->count++;
    if(this->last == nullptr)
    this->last = temp;
}

template<typename Type>
void list<Type>::push_front(Type&& val){
    nodeType<Type> *temp;
    temp = new nodeType<Type>;
    (*temp).setInfo(val);
    (*temp).setNext(this->first);
    this->first = temp;
    this->count++;
    if(this->last == nullptr)
    this->last = temp;
}

template<typename Type>
void list<Type>::pop_back(){
    nodeType<Type> *temp;
    nodeType<Type> *temp1;
    if (this->first == nullptr)
        cout << "Lista je vec prazna." << endl;
    else
    {
        if (this->first->getNext() == nullptr)
        {
            temp = this->first;
            this->first = nullptr;
            this->last = nullptr;
            this->count--;
            delete temp;
        }
        else
        {
            temp1 = this->first;
            temp = this->first->getNext();
            while(temp != nullptr)
            {
                if((*temp1).getNext()!= last)
                temp1= temp;
                temp = (*temp).getNext();
            }

            (*temp1).setNext(nullptr);
            this->last = temp1;
            this->count--;
             delete temp;

        }
    }
}

template<typename Type>
void list<Type>::pop_front(){
    nodeType<Type> *temp;
    if(this->first == nullptr)
        cout << "Lista je vec prazna." << endl;
    else
        {
            temp = this->first;
            this->first = this->first->getNext();
            this->count--;
            if(this->first == nullptr)
                this->last = nullptr;
            delete temp;
        }
}

template<typename Type>
Type list<Type>::front(){
    if(this->first == nullptr)
    throw string("Nema elemenata u listi!");
    else
    return (*first).getInfo();
}

template<typename Type>
Type list<Type>::back(){
    if(this->last == nullptr)
    throw string("Nema elemenata u listi!");
    else
    return (*last).getInfo();
}

template<typename Type>
const Type& list<Type>::front() const{
    if(this->first == nullptr)
    throw string("Nema elemenata u listi!");
    else
    return (*first).getInfo();
}

template<typename Type>
const Type& list<Type>::back() const{
    if(this->last == nullptr)
    throw string("Nema elemenata u listi!");
    else
    return (*last).getInfo();
}

template<typename Type>
list<Type>::list(){
    first = nullptr;
    last = nullptr;
    count = 0;
}

template<typename Type>
void list<Type>::kopiraj(const list<Type>& druga){
    nodeType<Type> *temp;
    if(this->first!= nullptr)
    clear();
    if(druga.first == nullptr)
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        nodeType<Type> *temp1;
        temp1 = druga.first;
        count = druga.count;
        first = new nodeType<Type>;
        (*first).setInfo((*temp1).getInfo());
        (*first).setNext(nullptr);
        last = first;
        temp1 = (*temp1).getNext();
        while(temp1!=nullptr)
        {
            temp = new nodeType<Type>;
            (*temp).setInfo((*temp1).getInfo());
            (*temp).setNext(nullptr);
            (*last).setNext(temp);
            last = temp;
            temp1 = (*temp1).getNext();
        }
    }
}

template<typename Type>
list<Type>::list(const list<Type>& x){
    std::cout << "copy" << endl;
    first = nullptr;
    kopiraj(x);
}

template<typename Type>
list<Type>::list(list<Type>&& x){
     std::cout << "move" << endl;
    if(x.first == nullptr){
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else{
        nodeType<Type> *temp;
        first = x.first;
        last = first;
        count = x.count;
        while(x.first!= nullptr){
         temp = x.first->getNext();
         last = temp;
         x.first = x.first->getNext();
    }

    x.last = nullptr;
    x.count=0;
}}

template<typename Type>
list<Type>::~list(){
    clear();
}

template<typename Type>
list<Type>& list<Type>::operator=(const list<Type>& x){
     std::cout << "copy assignment" << endl;
    if(this != &x)
        kopiraj(x);
    return *this;
}

template<typename Type>
list<Type>& list<Type>::operator=(list<Type>&& x){
     std::cout << "move assignment" << endl;
    if(x.first == nullptr){
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else{
        nodeType<Type> *temp;
        first = x.first;
        last = first;
        count = x.count;
        while(x.first!= nullptr){
         temp = x.first->getNext();
         last = temp;
         x.first = x.first->getNext();
    }
                        //x.first pokazuje na nullptr poslije while petlje
    x.last = nullptr;
    x.count=0;
}}


template<typename Type>
typename list<Type>::iterator list<Type>::insert (const_iterator position, const Type& val){
  nodeType<Type> * temp =new nodeType<Type>;
    (*temp).setInfo(val);
     if(position.getPok1()==nullptr && first==nullptr) // Provjeravamo da li je lista prazna i da li je prosljeden nullptr
      {  first = temp;
        last = temp;
        ++count;
        iterator it(temp);
        return it;
    }
    else
     if(position.getPok1() == nullptr) // Provjeravamo da li prosljedjen nullptr, u slučaju da jest, onda dodajemo elemenat na pocetak liste
    {
        (*temp).setNext(first);
        first = temp;
        ++count;
        iterator it(temp);
        return it;
    }
    (*temp).setNext((*position).getNext());
    (*position).setNext(temp);
    if((*temp).getNext() == nullptr)  // Provjeravamo da li je temp zadnji elemenat, ako jest last treba da pokazuje na temp
    last = temp;
    this->count++;
    iterator it(temp);
    return it;
}
template<typename Type>
typename list<Type>::iterator list<Type>::insert (const_iterator position,  Type&& val){
    nodeType<Type> * temp =new nodeType<Type>;
    (*temp).setInfo(val);
     if(position.getPok1()==nullptr && first==nullptr) // Provjeravamo da li je lista prazna i da li je prosljeden nullptr
      {  first = temp;
        last = temp;
        ++count;
        iterator it(temp);
        return it;
    }
    else
     if(position.getPok1() == nullptr) // Provjeravamo da li prosljedjen nullptr, u slučaju da jest, onda dodajemo elemenat na pocetak liste
    {
        (*temp).setNext(first);
        first = temp;
        ++count;
        iterator it(temp);
        return it;
    }
    (*temp).setNext((*position).getNext());
    (*position).setNext(temp);
    if((*temp).getNext() == nullptr)
    last = temp;
    this->count++;
    iterator it(temp);
    return it;
}
template<typename Type>
class list<Type>::iterator: public std::iterator<std::forward_iterator_tag, Type>
{
  private:
    nodeType<Type> *pok;
  public:
 // typedef nodeType<Type> pokazivac;
    iterator(nodeType<Type> *p) : pok(p){}
     iterator(const_iterator & p) {pok = nullptr; pok=p.getPok1();}
    nodeType<Type>* getPok() {return pok;}
    nodeType<Type>& operator*(){return *pok;}
    nodeType<Type>& operator*()const {return *pok;}
    iterator& operator++(){pok=pok->getNext(); return *this;}
    iterator operator++(int){
      iterator temp = *this;
      pok=pok->getNext();
      return temp;
    }
    bool operator!=(const iterator& b)const{return !((*this)==b);}
    bool operator==(const iterator& b)const{return pok == b.pok;}
};

template<typename Type>
class list<Type>::const_iterator: public std::iterator<std::forward_iterator_tag, Type>
{
  private:
    nodeType<Type> *pok;
  public:
 // typedef nodeType<Type> pokazivac;
    const_iterator(nodeType<Type> *p) : pok(p){}
    nodeType<Type>* getPok1() {return pok;}
    nodeType<Type>& operator*(){return *pok;}
    nodeType<Type>& operator*() const{return *pok;}
    void setPok1(nodeType<Type> *p) {pok =p;}
    const_iterator(): pok(nullptr){};
    const_iterator(iterator p){pok=p.getPok();}
    const_iterator& operator++(){pok=pok->getNext(); return *this;}
    const_iterator operator++(int){
      const_iterator temp = *this;
      pok=pok->getNext();
      return temp;
    }
    bool operator!=(const_iterator& b)const{return !((*this)==b);}
    bool operator==(const_iterator& b)const{return pok == b.pok;}


};


#endif
