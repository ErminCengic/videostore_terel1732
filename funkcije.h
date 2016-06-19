#include <fstream>
#include <sstream>
#include "listaKorisnika.h"
#include <ctype.h>
//#include "admin.h"
using namespace std;
ListaFilmova historija;
ListaFilmova posudjeni;
ListaFilmova filmovi;
ListaKorisnika korisnici;
int counter=0;
int ID = 1020;
int film_counter = 0;
int countH = 0;

string& pretvori(string& str){
  str[0] = toupper(str[0]);
  for(int i = 1; i < str.length();++i){
    str[i] = tolower(str[i]);
    }
  return str;
}

void citanje_korisnika(){
  ifstream file("korisnici.txt");
         string line;
         char temp1,temp2,tacka;
         string ime,prezime,jmbg,user,pass;
         int god,dan,mjesec;
         while(getline(file,line)){
            stringstream linestream(line);
            linestream>>temp1;
            if(temp1=='#'){
                linestream>>temp2>>ime>>prezime>>jmbg>>dan>>tacka>>mjesec>>tacka>>god>>user>>pass;
                Racun rac(user,pass);
                Datum dat(dan,mjesec,god);
                Korisnik clan(ime,prezime,jmbg,dat,rac);
                korisnici.dodaj_korisnika(clan);
            }
         }
}

void citanje_filmova(){
    ifstream myfile("filmovi.txt");
    char temp, zarez, temp1;
    ListaPoznatih glumci, producenti, scenaristi, a, b, c;
    string line;
    Poznati glumac, producent, scenarist;
    string naziv,ime, prezime, kompanija;
    Poznati reziser;
    int god, kopije, id;
    string opis;
    string rijec;
    string pom;
    string pom1;
    string temp3;
    int broj = 0;
    while(getline(myfile,line)){
        stringstream linestream(line);
        linestream >> temp;
        if(temp=='#'){
          naziv = pom;
          temp3 = pom;
	            linestream>>temp1;
            do{  linestream>>pom1;
              if(pom1 != ",")
                temp3 += pom1 + ' ';
              naziv = string(temp3.size()-1,'*');
              }while(pom1!=",");
              for(int i = 0; i < temp3.size()-1; ++i)
                naziv[i] = temp3[i];
            naziv = pretvori(naziv);
              linestream>>god>>zarez>>ime>>prezime>>zarez>>kompanija>>zarez>>kopije>>zarez>>id;
            reziser.setIme(ime);
            reziser.setPrezime(prezime);
            ++broj;
        }
        else if(temp=='*'){
          glumci = a;
          do{
            linestream>>ime;
            if(ime =="!")
              break;
          linestream>>prezime>>temp1;
           glumac.setIme(ime);
           glumac.setPrezime(prezime);
          glumci.insertLast(glumac);
          }while(temp1!='!');
        }
        else  if(temp=='+'){
            producenti = a;
            do{
              linestream>>ime;
              if(ime == "!")
                break;
              linestream>>prezime>>temp1;
             producent.setIme(ime);
             producent.setPrezime(prezime);
              producenti.insertLast(producent);
            }while(temp1!='!');
          }
        else  if(temp=='/'){
              scenaristi = a;
              do{
                linestream>> ime;
                if(ime == "!")
                  break;
                linestream>>prezime>>temp1;
                 scenarist.setIme(ime);
                 scenarist.setPrezime(prezime);
                 scenaristi.insertLast(scenarist);
              }while(temp1!='!');
            }
        else if(temp == '&'){
              Film novi1(naziv,god,reziser,kompanija,kopije,id,glumci,producenti,scenaristi,rijec);
              rijec = pom;
           filmovi.dodaj_film(novi1);

            }
        else{
              rijec += temp;
              do{
              linestream>>opis;
              rijec = rijec+opis+' ';
              }while(opis!="!");
            }
           
    }
 }

void ucitaj_posudjene(){
  ifstream myfile2("posudjeni.txt");
  char zarez, temp;
  Korisnik korisnik;
  string line, b, c, user, ime, prezime, br, film,noviFilm;
  int kljuc;
  ListaFilmova novi, a;
  while(getline(myfile2,line)){
    stringstream linestream(line);
    linestream >> temp;
    if(temp == '#'){
      linestream >> br >> user >> zarez;
      do{
        linestream >> ime;
      }while(ime!=",");
    

    do{
      linestream >> prezime;
    }while(prezime!="!!");

  }
   else if(temp == '&'){
      korisnik = korisnici.pretrazivanje_korisnika(user);
      korisnici.izbrisi_korisnika(korisnik);
      korisnik.setPosudjeni(posudjeni);
      korisnici.dodaj_korisnika(korisnik);
      posudjeni.initializeList();
   }
    else{
      do{
        linestream >> film;
        if(film!=",")
          noviFilm+=film + ' ';
      }while(film!=",");
      linestream >> kljuc >> c;
      Cvor<Film> * cvorFilm = filmovi.nadji_film(kljuc);
      posudjeni.dodaj_film(cvorFilm->getInfo());
    }
  }
}

void ucitaj_historiju(){
  ifstream myfile1("historija.txt");
  char zarez, temp;
  Korisnik korisnik;
  string line, b , c, user, ime ,prezime ,br ,film, noviFilm, film1;
  int kljuc;
  ListaFilmova novi, a;
  while(getline(myfile1,line)){
    stringstream linestream(line);
    linestream >> temp;
    if(temp == '#'){
         linestream >> br >> user >> zarez;
      do{
        linestream >> ime;
       
      }while(ime!=",");
       
      do{
        linestream >> prezime;
        }while(prezime!="!!");
          
    }
    else if(temp == '&'){
             korisnik = korisnici.pretrazivanje_korisnika(user);
             korisnici.izbrisi_korisnika(korisnik);
            korisnik.setHistorija(historija);
             korisnici.dodaj_korisnika(korisnik);
             historija.initializeList();
    }
    else{
      do{
        linestream >> film;
        if(film!=",")
          noviFilm += film + ' ';
      }while(film!=",");
      linestream >> kljuc >> c;
         Cvor<Film> * cvorFilm = filmovi.nadji_film(kljuc);
         historija.dodaj_film(cvorFilm->getInfo());
    }
  }
}

void ListaKorisnika::upisivanje_posudjenih(){
  ofstream file;
  file.open("posudjeni.txt");
  Cvor<Korisnik>* temp = first;
  while(temp!=nullptr){
    file << "#" << ++countH << " " << temp->getInfo().getRacun().getUsername() << " , " << temp->getInfo().getIme();
    file << " ,  " << temp->getInfo().getPrezime() << " !!" << endl;
    ListaFilmova temp1 = temp->getInfo().getPosudjeni();
    Cvor<Film> *temp2 = temp1.nadji();
    while(temp2!=nullptr){
      file << temp2->getInfo().getNaziv() << " , " << temp2->getInfo().getId() << " !!" << endl;
      temp2 = temp2->getLink();
    }
    file << "&" << endl;
    temp = temp->getLink();
  }
  file.close();
}

void ListaKorisnika::upisivanje_historije(){
  ofstream file;
  file.open("historija.txt");
  Cvor<Korisnik>* temp = first;
  while(temp!=nullptr){
    file << "#" << ++countH << " " << temp->getInfo().getRacun().getUsername() << " , " << temp->getInfo().getIme();
    file << " ,  " << temp->getInfo().getPrezime() << " !!" << endl;
    ListaFilmova temp1 = temp->getInfo().getHistorija();
    Cvor<Film> *temp2 = temp1.nadji();
    while(temp2!=nullptr){
      file << temp2->getInfo().getNaziv() << " , " << temp2->getInfo().getId() << " !!" << endl;
      temp2 = temp2->getLink();
    }
    file << "&" << endl;
    temp = temp->getLink();
  }
  file.close();
}

void ListaKorisnika::upisivanje_korisnika(){
    ofstream file;
    file.open("korisnici.txt");
    Cvor<Korisnik>* temp = first;
     while(temp!=nullptr){
      file<<"#"<< ++counter <<" " << temp->getInfo().getIme() << " " << temp->getInfo().getPrezime() << " " << temp->getInfo().getJmbg() << " ";
     file<<temp->getInfo().getDatum().getDan() << "." << temp->getInfo().getDatum().getMjesec() << "." << temp->getInfo().getDatum().getGod();
      file<<" " <<temp->getInfo().getRacun().getUsername() << " " << temp->getInfo().getRacun().getLozinka() << endl;
    temp=temp->getLink();
   }
    file.close();
}

void ListaFilmova::upisivanje_filmova(){
  ofstream file;
  
  file.open("filmovi.txt");
  Cvor<Film>* temp = first;
  while(temp!= nullptr){
    file << "#" << ++film_counter << " " << temp->getInfo().getNaziv()  << " , " << temp->getInfo().getGod() << " , ";
    file <<  temp->getInfo().getReziser().getIme() << " " << temp->getInfo().getReziser().getPrezime() << " , " << temp->getInfo().getKompanija() << " , " << temp->getInfo().getKopije() << " , " << temp->getInfo().getId() << endl;
    file << "*" << " ";
    ListaPoznatih temp1 = temp->getInfo().getGlumci();
    Cvor<Poznati> * poznati= temp1.nadji();
    while(poznati!=nullptr){
      file << poznati->getInfo() << " , ";
	poznati = poznati->getLink();
    }
    file << "!" << endl;
    file << "+" << " ";
    ListaPoznatih temp2 = temp->getInfo().getProducenti();
    Cvor<Poznati> * producenti= temp2.nadji();
    while(producenti!=nullptr){
      file << producenti->getInfo() << " , ";
	producenti = producenti->getLink();
    }
    file << "!" << endl;
    file << "/" << " ";
    ListaPoznatih temp3 = temp->getInfo().getScenaristi();
    Cvor<Poznati> * scenaristi= temp3.nadji();
    while(scenaristi!=nullptr){
      file << scenaristi->getInfo() << " , ";
	scenaristi = scenaristi->getLink();
    }
    file << "!" << endl;  
    file  << temp->getInfo().getOpis() << endl << "&" << endl;
    temp = temp->getLink();
  }
  file.close();
}



Korisnik unos_korisnika(){
  Korisnik korisnik;
  Racun racun;
  string ime, prezime, jmbg, lozinka, username;
  int dan, god, mjesec;
  cout << "Unesite ime i prezime korisnika: ";
  cin>>ime>>prezime;
  ime = pretvori(ime);
  prezime = pretvori(prezime);
  cin.ignore();
  do{
  cout << "Unesite jmbg korisnika: ";
    cin>>jmbg;
    cin.clear();
   }while(!korisnik.validan_jmbg(jmbg));
  cout << "Unesite datum uclanjivanja(dan, mjesec, godina): ";
  cin >> dan >> mjesec >> god;
  Datum datum(dan, mjesec, god);
  cin.ignore();
 do{ 
   cout << "Unesite korisnicko ime: ";
   getline(cin,username);
  }while(!racun.validnost_username(username) || korisnici.nadji_korisnika(username)!=nullptr);
 racun.setUsername(username);
 do{
   cin.clear();
    cout << "Unesite lozinku: ";
    getline(cin,lozinka);
 }while(!racun.validnost_lozinke(lozinka));
 racun.setLozinka(lozinka);

  Korisnik novi(ime, prezime, jmbg, datum, racun);
  return novi;
}

Korisnik& azuriranje_korisnika(Korisnik& korisnik){
    char izbor;
    Racun racun;
    string ime,prezime,username,lozinka;
    do{
      cout << endl;
      cout <<"Sta zelite azurirati? " << endl;
      cout <<"a. Ime korisnika " << endl;
      cout <<"b. Prezime korisnika " << endl;
      cout <<"c. Jmbg korisnika " << endl;
      cout <<"d. Datum uclanjivanja " << endl;
      cout <<"e. Korisnicko ime " << endl;
      cout <<"f. Lozinka korisnika " << endl;
      cout <<"g. Izlaz" << endl;
      cin>>izbor;
      cin.clear();
        switch(izbor){
          case 'a':
            {
             cout <<"Novo ime: ";
             cin>>ime;
             ime = pretvori(ime);
             korisnik.setIme(ime);
             cout <<"Uspjesno ste promijenili ime korisnika!" << endl;
             break;
           }
          case 'b':
            {
             cout <<"Novo prezime: ";
             cin>>prezime;
             prezime = pretvori(prezime);
             korisnik.setPrezime(prezime);
             cout << "Uspjesno ste promijenili prezime korisnika!" << endl;
             break;
           }
          case 'c':
            {
              cin.ignore();
              string jmbg;
              cout <<"Novi jmbg: ";
              getline(cin,jmbg);
              if(korisnik.validan_jmbg(jmbg)){
                  korisnik.setJmbg(jmbg);
                  cout << "Uspjesno ste promijenili jmbg!" << endl;
              }
              else
                cout <<"Niste promijenili jmbg." << endl;
              break;
            }
          case 'd':
            {
              cin.clear();
              int dan,god,mjesec;
              cout <<"Unesite novi datum(dan,mjesec,godina): ";
              cin>>dan>>mjesec>>god;
              Datum datum(dan,mjesec,god);
              korisnik.setDatum(datum);
              cout << "Uspjesno ste promijenili datum uclanjivanja!" << endl;
              break;
            }
          case 'e':
            {
              cin.ignore();
              do{
             cout <<"Novo korisnicko ime: ";
             getline(cin,username);
              } while(!racun.validnost_username(username) || korisnici.nadji_korisnika(username)!=nullptr);
               racun.setLozinka(korisnik.getRacun().getLozinka());
               racun.setUsername(username);
               korisnik.setRacun(racun);
               cout <<"Uspjesno ste promijenili korisnicko ime!" << endl;
             break;
            }
          case 'f':
            {
              cin.ignore();
              do{
              cout <<"Nova lozinka: ";
              getline(cin,lozinka);
              }while(!racun.validnost_lozinke(lozinka));
                  racun.setLozinka(lozinka);
                  racun.setUsername(korisnik.getRacun().getUsername());
                  korisnik.setRacun(racun);
                  cout <<"Uspjesno ste promijenili lozinku!" << endl;
              break;
            }
        }
    }while(izbor!='g');
        return korisnik;
}

Film& azuriraj_film(Film& film){
      char izbor;
      do{
          cout << endl;
          cout << "Sta zelite azurirati: " << endl;
          cout << "a. Naziv filma " << endl;
          cout << "b. Godinu izdavanja " << endl;
          cout << "c. Ime i prezime rezisera " << endl;
          cout << "d. Naziv kompanije " << endl;
          cout << "e. Broj kopija filma u videoteci " << endl;
          cout << "f. Imena i prezimena glumaca, scenarista ili producenata " << endl;
          cout << "g. Izlaz " << endl;
          cin>>izbor;
          cin.clear();

          switch(izbor){
                case 'a':
                  {
                    string naziv;
                    cin.ignore();
                    cout <<"Unesite novi naziv filma: ";
                    getline(cin,naziv);
                    naziv = pretvori(naziv);
                    film.setNaziv(naziv);
                    break;
                  }
                case 'b':
                  {
                    int godina;
                    cout <<"Unesite novu godinu izdavanja filma: ";
                    cin>>godina;
                    film.setGod(godina);
                    break;
                  }
                case 'c':
                  {
                    string ime,prezime;
                    cin.clear();
                    cout <<"Unesite novo ime i prezime rezisera: ";
                    cin>>ime>>prezime;
                    ime = pretvori(ime);
                    prezime = pretvori(prezime);
                    Poznati reziser(ime,prezime);
                    film.setReziser(reziser);
                    break;
                  }
                case 'd':
                  {
                    cin.ignore();
                    string kompanija;
                    cout <<"Unesite novi naziv kompanije: ";
                    getline(cin,kompanija);
                    kompanija = pretvori(kompanija);
                    film.setKompanija(kompanija);
                    break;
                  }
                case 'e':
                  {
                    int kopije;
                    cout <<"Unesite broj kopija filma u videoteci: ";
                    cin>>kopije;
                    film.setKopije(kopije);
                    break;
                  }
                case 'f':
                  {
                    string ime,prezime;
                    cout <<"Unesite jednu od sljedece tri opcije: " << endl;
                    cout <<"1. Glumci: " << endl;
                    cout <<"2. Producenti:" << endl;
                    cout <<"3.Scenaristi: " << endl;
                    int br;
                    cin>>br;
                    cout <<"Unesite ime i prezime osobe koju zelite azurirati: ";
                    cin>>ime>>prezime;
                    ime = pretvori(ime);
                    prezime = pretvori(prezime);
                    cin.clear();
                    if(br == 1){
                      string name,surname;
                      ListaPoznatih temp = film.getGlumci();
                      Cvor<Poznati>* glumac = temp.nadji_poznate(prezime);
                      if(glumac!=nullptr){
                      cout <<"Unesite novo ime i prezime glumca: ";
                      cin>>name>>surname;
                      name = pretvori(name);
                      surname = pretvori(surname);
                      glumac->getInfo().setIme(name);
                      glumac->getInfo().setPrezime(surname);
                      film.setGlumci(temp);
                      }
                      else cout <<"Nema trazenog glumca!" << endl;
                    }
                    else if(br == 2){
                      string name,surname;
                        ListaPoznatih temp = film.getProducenti();
                        Cvor<Poznati>* producent = temp.nadji_poznate(prezime);
                        if(producent!=nullptr){
                            cout <<"Unesite novo ime i prezime producenta: ";
                            cin>>name>>surname;
                            name = pretvori(name);
                            surname = pretvori(surname);
                            producent->getInfo().setIme(name);
                            producent->getInfo().setPrezime(surname);
                            film.setProducenti(temp);
                        }
                        else cout <<"Nema trazenog producenta!" << endl;
                    }
                    else{
                      string name,surname;
                      ListaPoznatih temp = film.getScenaristi();
                      Cvor<Poznati>* scenarist = temp.nadji_poznate(surname);
                      if(scenarist!=nullptr){
                          cout <<"Unesite novo ime i prezime scenariste: ";
                          cin>>name>>surname;
                          name = pretvori(name);
                          surname = pretvori(surname);
                          scenarist->getInfo().setIme(name);
                          scenarist->getInfo().setPrezime(surname);
                          film.setScenaristi(temp);
                      }
                      else cout <<"Nema trazenog scenariste!" << endl;
                    }
                      break;
                    }
                  }
      }while(izbor!='g');
      return film;
}

int izbor_admina(){
  int izbor;
  cout << endl;
  cout << "Izaberite opciju: " << endl;
  cout << "1. Pregled sadrzaja videoteke" << endl;
  cout << "2. Pretraga sadrzaja videoteke po nazivu filma" << endl;
  cout << "3. Ispis svih podataka za odabrani film" << endl;
  cout << "4. Dodavanje novog filma u videoteku" << endl;
  cout << "5. Brisanje odabranog filma iz videoteke" << endl;
  cout << "6. Azuriranje postojecih filmova" << endl;
  cout << "7. Pregled liste korisnika" << endl;
  cout << "8. Pretraga liste korisnika po imenu i prezimenu" << endl;
  cout << "9. Pretraga liste korisnika po korisnickom imenu" << endl;
  cout << "10. Dodavanje novog korisnika" << endl;
  cout << "11. Brisanje odabranog korisnika" << endl;
  cout << "12. Azuriranje postojecih korisnika" << endl;
  cout << "13. Pregled liste trenutno posudjenih filmova za odabranog korisnika" << endl;
  cout << "14. Pregled historije posudjivanja za odabranog korisnika" << endl;
  cout << "15. Izlaz iz programa" << endl;
  cin >> izbor;
  return izbor;
}

void administrator(int izbor){
  switch(izbor){
       case 1:
         {
           filmovi.sortiraj_filmove();
           filmovi.ispisi_filmove();
           administrator(izbor_admina());
           break;
         }
       case 2:
         {
           string naziv;
           int br = 0;
           do{
              cout << "Unesite naziv filma: ";
              cin.ignore();
              getline(cin,naziv);
              naziv = pretvori(naziv);
              if(filmovi.nadji_film(naziv) == nullptr){
                  cout << "Nema trazenog filma. ";
                  cout << "Ako zelite drugu pretragu upisite broj 1: ";
                  cin>>br;
              }
              else{
                 cout << naziv << " je dostupan u videoteci." << endl;
                 br = 0;
                 break;
              }
           }while(br == 1);
       		 administrator(izbor_admina());
           break;
         }
       case 3:
         {
            string naziv;
            int br = 0;
            do{
              cout <<"Upisite naziv filma: ";
              cin.ignore();
              getline(cin,naziv);
              naziv = pretvori(naziv);
              Film temp = filmovi.pretrazivanje_filmova(naziv);
              if(temp.getId() == 1000){
                  cout << "Unesite broj 1 ako zelite drugu pretragu: ";
                  cin>>br;
              }
              else{
                cout << temp;
                br = 0;
                break;
              }
            }while(br==1);
    		 administrator(izbor_admina());
            break;
         }
       case 4:
         {
           string naziv,kompanija,opis,ime,prezime;
           int god,kopije,br;
           ListaPoznatih glumci, producenti,scenaristi;
           cout << "Unesite naziv filma: ";
           cin.ignore();
           getline(cin,naziv);
           naziv = pretvori(naziv);
           cout << "Unesite godinu izdavanja: ";
           cin >> god;
           cout << "Unesite ime rezisera: ";
           cin.ignore();
           getline(cin,ime);
           ime = pretvori(ime);
           cout << "Unesite prezime rezisera: ";
           cin.clear();
           getline(cin,prezime);
           prezime = pretvori(prezime);
           Poznati reziser(ime,prezime);
           cout << "Unesite kompaniju: ";
           cin.clear();
           getline(cin,kompanija);
           cout << "Unesite broj kopija filma: ";
           cin>>kopije;
           cout <<"Koliko glumaca zelite dodati: ";
           cin >> br;
           for(int i = 0; i < br; ++i){
              cout << "Unesite ime glumca: ";
              cin>>ime;
              ime = pretvori(ime);
              cout << "Unesite prezime glumca: ";
              cin>>prezime;
              prezime = pretvori(prezime);
              Poznati glumac(ime,prezime);
              glumci.insertLast(glumac);}
           cout << "Koliko producenata zelite dodati: ";
           cin>>br;
           for(int i = 0; i < br; ++i){
              cout << "Unesite ime producenta: ";
              cin>>ime;
              ime = pretvori(ime);
              cout << "Unesite prezime producenta: ";
              cin>>prezime;
              prezime = pretvori(prezime);
              Poznati producent(ime,prezime);
              producenti.insertLast(producent);}
           cout << "Koliko scenarista zelite dodati: ";
           cin>>br;
           for(int i = 0; i < br; ++i){
              cout << "Unesite ime scenariste: ";
              cin>>ime;
              ime = pretvori(ime);
              cout << "Unesite prezime scenariste: ";
              cin>>prezime;
              prezime = pretvori(prezime);
              Poznati scenarist(ime,prezime);
              scenaristi.insertLast(scenarist);}
           cin.ignore();
           cout << "Unesite opis filma: ";
           getline(cin,opis);
           Film novi(naziv,god,reziser,kompanija,kopije,ID,glumci,producenti,scenaristi,opis);
           ID+=20;
           filmovi.dodaj_film(novi);
	         filmovi.sortiraj_filmove();
      		administrator(izbor_admina());
           break;
         }
       case 5:
         {
           string naziv;
           cout <<"Unesite naziv filma kojeg zelite obrisati: ";
           cin.ignore();
           getline(cin,naziv);
           naziv = pretvori(naziv);
           Film temp = filmovi.pretrazivanje_filmova(naziv);
           if(temp.getId()!=1000){
              filmovi.izbrisi_film(temp);
              cout << "Film je uspjesno izbrisan!" << endl;
           }
    	   administrator(izbor_admina());
           break;
         }
         
       case 6:
         {
           Film novi;
           string naziv;
           cout <<" Unesite naziv filma kojeg zelite azurirati: ";
           cin.ignore();
           getline(std::cin,naziv);
           novi = filmovi.pretrazivanje_filmova(naziv);
           filmovi.izbrisi_film(novi);
           if(novi.getId() != 1000){
           cout << endl;
           cout <<"Film za azuriranje: " <<endl << endl;
           cout << novi;
           novi = azuriraj_film(novi);
           filmovi.dodaj_film(novi);
           cout << "Azurirani film: " << endl << endl;
           cout << novi;}

   	  administrator(izbor_admina());
          break;
         }
         
       case 7:
         {
            korisnici.sortiraj_korisnike();
            korisnici.ispisi_korisnike();
            administrator(izbor_admina());
            break;
         }
       case 8:
         {
           string ime, prezime;
           Korisnik korisnik;
           int br = 0;
           do{
             
          cout << "Unesite ime korisnika: ";
           cin >> ime;
           ime = pretvori(ime);
           cout << "Unesite prezime korisnika: ";
           cin >> prezime;
           prezime = pretvori(prezime);
           korisnik =  korisnici.pretrazivanje_korisnika(ime,prezime);
           if(korisnik.getDatum().getDan() == 0)
           {
             cout << "Ako zelite drugu pretragu upisite broj 1:";
             cin >> br;
           }
           else{
             cout << korisnik;
             break;
           }
           }while(br == 1);
   	   administrator(izbor_admina());
           break;
         }
       case 9:
         {
           Korisnik korisnik;
           string username;
           int br = 0;
           do{
             cout << "Unesite korisnicko ime: ";
             cin >> username;
             korisnik = korisnici.pretrazivanje_korisnika(username);
             if(korisnik.getDatum().getDan() == 0){
               cout << "Ako zelite drugu pretragu upisite broj 1: ";
               cin >> br;
             }
             else{
               cout << korisnik;
               break;
             }
           }while(br == 1);
           administrator(izbor_admina());
           break;
         }
       case 10:
         {
           Korisnik korisnik;
          korisnik = unos_korisnika();
          korisnici.dodaj_korisnika(korisnik);
          administrator(izbor_admina());
          break;
         }
        case 11:
         {
           Korisnik korisnik;
           string ime,prezime;
          cout <<"Unesite korisnika kojeg zelite izbrisati: " << endl;
          cin.ignore();
          cout <<"Ime: ";
          cin>>ime;
          ime = pretvori(ime);
          cout <<"Prezime: ";
          cin>>prezime;
          prezime = pretvori(prezime);
          korisnik = korisnici.pretrazivanje_korisnika(ime,prezime);
          if(korisnik.getDatum().getDan()!=0){
            korisnici.izbrisi_korisnika(korisnik);
            cout <<"Korisnik je uspjesno izbrisan!" << endl;}
          administrator(izbor_admina());
          break;
         }
        case 12:
         {
           Korisnik korisnik,novi;
           Racun racun;
           string username;
           cout <<"Unesite korisnicko ime korisnika kojeg zelite azurirati: ";
           cin>>username;
           korisnik = korisnici.pretrazivanje_korisnika(username);
           if(korisnik.getDatum().getDan()!=0)
           {
             cout << endl;
             cout <<"Korisnik za azuriranje:"<< endl << endl;
             cout << korisnik;
             korisnik = azuriranje_korisnika(korisnik);
             cout << "Azurirani korisnik:" << endl << endl;
             cout << korisnik;}
     	    administrator(izbor_admina());
           break;
         }
        case 13:
         {
           cin.ignore();
           string ime, prezime;
           Korisnik korisnik;
           cout << "Unesite ime korisnika: ";
           getline(cin,ime);
           ime = pretvori(ime);
	         cin.clear();
           cout << "Unesite prezime korisnika: ";
           getline(cin,prezime);
           prezime = pretvori(prezime);
           korisnik = korisnici.pretrazivanje_korisnika(ime,prezime);
           if(korisnik.getPosudjeni().isEmptyList())
             cout << "Korisnik trenutno nema posudjenih filmova!" << endl;
          else{
             ListaFilmova test = korisnik.getPosudjeni();
             Cvor<Film>* proba = test.nadji();

              while(proba!=nullptr){
                cout << proba->getInfo().getNaziv() << ", " << proba->getInfo().getGod() << endl;
               proba = proba->getLink();
              }
            }

    	     administrator(izbor_admina());
           break;
         }
        case 14:
         {
	         cin.ignore();
           string ime, prezime;
           Korisnik korisnik;
           cout << "Unesite ime korisnika: ";
           getline(cin,ime);
           ime = pretvori(ime);
           cin.clear();
           cout << "Unesite prezime korisnika: ";
           getline(cin,prezime);
           prezime = pretvori(prezime);
           korisnik = korisnici.pretrazivanje_korisnika(ime,prezime);
           cout << korisnik;
            
          ListaFilmova test = korisnik.getHistorija();
          Cvor<Film>* proba = test.nadji();
          if(korisnik.getHistorija().isEmptyList())
            cout << "Korisnik nije nikad posudio film!" << endl;
          else{
              while(proba!=nullptr){
               cout << proba->getInfo().getNaziv() << ", " << proba->getInfo().getGod() << endl;
               proba = proba->getLink();
             }
          }
          
           administrator(izbor_admina());
           break;
         }
        case 15:
         {
           return;
         }
        default:
         cout <<"Pogresan izbor!" << endl;
  }
}


int izbor_korisnika(){
  int izbor;
  cout << "Izaberite opciju:" << endl;
  cout << "1. Pregled sadrzaja videoteke" << endl;
  cout << "2. Pretraga sadrzaja videoteke po nazivu filma" << endl;
  cout << "3. Ispis svih podataka za odabrani film" << endl;
  cout << "4. Posudjivanje filma sa datim nazivom" << endl;
  cout << "5. Vracanje filma" << endl;
  cout << "6. Pregled svoje historije posudjivanja filmova" << endl;
  cout << "7. Pregled trenutne liste posudjenih filmova" << endl;
  cout << "8. Izlaz iz programa" << endl;
  cin >> izbor;
  return izbor;
}

void Korisnik::korisnik(int izbor){
  switch(izbor){
      case 1:
        {
          filmovi.ispisi_filmove();
          korisnik(izbor_korisnika());
          break;
        }
      case 2:
        {
          string naziv;
         int br = 0;
           do{
              cout << "Unesite naziv filma: ";
              cin.ignore();
              getline(cin,naziv);
              naziv = pretvori(naziv);
              Cvor<Film>* temp = filmovi.nadji_film(naziv);
              if(temp == nullptr || temp->getInfo().getKopije() == 0){
                  cout << "Nema trazenog filma. ";
                  cout << "Ako zelite drugu pretragu upisite broj 1: ";
                  cin>>br;
              }
              else{
                 cout << naziv << " je dostupan u videoteci i ima " << temp->getInfo().getKopije() << " kopija." << endl;
                 br = 0;
                 break;
              }
           }while(br == 1);
           korisnik(izbor_korisnika());
           break; 
        }
      case 3:
        {
           string naziv;
           int br = 0;
            do{
              cout <<"Upisite naziv filma: ";
              cin.ignore();
              getline(cin,naziv);
              naziv = pretvori(naziv);
              Film temp = filmovi.pretrazivanje_filmova(naziv);
              if(temp.getId() == 1000){
                  cout << "Unesite broj 1 ako zelite drugu pretragu: ";
                  cin>>br;
              }
              else{
                cout << temp;
                br = 0;
                break;
              }
            }while(br==1);
            korisnik(izbor_korisnika());
            break;

        }
      case 4:
        {
          
          int br = 0;
          ListaFilmova posudio = getPosudjeni();
          if(posudio.length() > 2){
            cout << "Ne mozete imati vise od 3 posudjena filma!" << endl;
          }
          else{
            cout << "Unesite naziv filma kojeg zelite posuditi: ";
            cin.ignore();
            string naziv;
            getline(cin,naziv);
            naziv = pretvori(naziv);
          
            Film posudjeni = filmovi.posudi_film(naziv);
            ListaFilmova test = getPosudjeni();
             Cvor<Film>* proba = test.nadji();

              while(proba!=nullptr){
               if(proba->getInfo().getId() == posudjeni.getId()){
                 cout << "Ne mozete posuditi film kojeg ste vec posudili!" << endl;
                ++br;
                
                  break;
              }
                proba = proba->getLink();
            }

            if(posudjeni.getId() != 1000 && br == 0){
                ListaFilmova hist = getHistorija();
                hist.dodaj_film(posudjeni);
                setHistorija(hist);             
                posudio.dodaj_film(posudjeni);
                setPosudjeni(posudio);
                korisnici.izbrisi_korisnika(*this);
                korisnici.dodaj_korisnika(*this);
                korisnici.upisivanje_historije();
                korisnici.upisivanje_posudjenih();
                hist.initializeList();
           }
          }
          korisnik(izbor_korisnika());
          break;
        }
      case 5:
        {
          string naziv;
          cout << "Unesite naziv filma kojeg vracate: ";
          cin.ignore();
          getline(cin,naziv);
          naziv = pretvori(naziv);
          if(_posudjeni.nadji_film(naziv) != nullptr){
           Film temp = _posudjeni.pretrazivanje_filmova(naziv);
           _posudjeni.izbrisi_film(temp);
           filmovi.vrati_film(temp);
          }
          else
            cout << "Uneseni film nije posudjen!" << endl;
          korisnici.upisivanje_posudjenih();
         korisnik(izbor_korisnika());
          break;
        }
      case 6:
        {
          ListaFilmova test = getHistorija();
          Cvor<Film>* proba = test.nadji();
          if(getHistorija().isEmptyList())
            cout << "Niste nikada posudili film!" << endl;
          else{
              while(proba!=nullptr){
               cout << proba->getInfo().getNaziv() << ", " << proba->getInfo().getGod() << endl;
               proba = proba->getLink();
             }
          }

           korisnik(izbor_korisnika());
           break;
        }
      case 7:
        {
           if(getPosudjeni().isEmptyList())
             cout << "Trenutno nema nijednog posudjenog filma!" << endl;
          else{
             ListaFilmova test = getPosudjeni();
             Cvor<Film>* proba = test.nadji();

              while(proba!=nullptr){
                cout << proba->getInfo().getNaziv() << ", " << proba->getInfo().getGod() << endl;
               proba = proba->getLink();
              }
            }

          korisnik(izbor_korisnika());
          break;
        }
      case 8:
        {
          return;
        }
      default:
        cout << "Pogresan izbor!" << endl;
}
}
