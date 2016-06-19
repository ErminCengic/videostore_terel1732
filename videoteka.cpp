#include "funkcije.h"
#include "admin.h"
#include <unistd.h>

using namespace std;

int main(){
      Admin admin;
      Korisnik korisnik;
      Racun osoba;
      string username,lozinka;
      int izbor_a, izbor_k;
      int br = 0;
      citanje_korisnika();
      citanje_filmova();
      ucitaj_historiju();
      ucitaj_posudjene();
      do{
         cout << "Unesite vas username: " << endl;
          getline(cin,username);
          cin.clear();
          if(username == admin.getUsername()){
            br = 1;
            break;
          }
          osoba.setUsername(username);
      }while(!osoba.validnost_username(username));
      
      do{
        if(br == 1){
          lozinka = getpass("Unesite lozinku administratora: ");
          if(admin.getLozinka() == lozinka)
            break;
        }
        else{
            lozinka = getpass("Unesite vasu lozinku: ");
            osoba.setLozinka(lozinka);
      }
      
      }while(!osoba.validnost_lozinke(lozinka));
      cout << endl;
      
      if(username == admin.getUsername() && lozinka == admin.getUsername()){
	 cout << admin.getUsername() << ", dobrodosli u videoteku Terel!" << endl;
         izbor_a =  izbor_admina();
         administrator(izbor_a);
         korisnici.upisivanje_korisnika();
         filmovi.upisivanje_filmova();
      }

      else if(korisnici.nadji_korisnika(username)!=nullptr){
        int brojac = 0;
        do{
        if(osoba.getLozinka()!=korisnici.nadji_korisnika(username)->getInfo().getRacun().getLozinka()){
          cout << "Pogresno ste unijeli lozinku! Pokusajte ponovo: " << endl;
          ++brojac;
         lozinka = getpass("");
          osoba.setLozinka(lozinka);
        }
        }while(brojac < 2 &&  osoba.getLozinka()!=korisnici.nadji_korisnika(username)->getInfo().getRacun().getLozinka());
        if(osoba.getLozinka()!=korisnici.nadji_korisnika(username)->getInfo().getRacun().getLozinka()){
          cout << "Tri puta ste unijeli pogresnu lozinku!" << endl;
          
        }else{
	cout << username << ", dobrodosli u videoteku Terel!" << endl;
        korisnik = korisnici.pretrazivanje_korisnika(username);
        korisnik.korisnik(izbor_korisnika());
      }}
      else
        cout << "Niste registrovani u videoteci!" << endl;

  

  return 0;
}
