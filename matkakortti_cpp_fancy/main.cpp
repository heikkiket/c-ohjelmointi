#include <iostream>
#include <string>

using namespace std;

#include "matkakortti.h"
#include "leimaaja.h"

std::unique_ptr<Matkakortti> valittuKortti;
Leimaaja leimaaja;

std::unique_ptr<Matkakortti> luoMatkakortti();
void matkusta(std::unique_ptr<Matkakortti> &kortti);

int main() {
  bool jatketaan = true;
  int valinta = 0;

  int linja;
  cout << "Anna linjan nimi, jolla leimaaja leimaa: ";
  cin >> linja;

  leimaaja = Leimaaja(linja);

  while(jatketaan) {
    cout << "\n\n1. Luo matkakortti\n";
    cout << "2. Lataa saldoa\n";
    cout << "3. Tulosta kortin tiedot\n";
    cout << "4. Vaihda kortin haltijan nimi\n";
    cout << "5. Matkusta kortilla\n";
    cout << "6. Tulosta leimaustapahtumat\n";
    cout << "7. Matkusta operaattoria kuormittamalla\n";
    cout << "0. Poistu\n\n";
    cout << "Anna valinta: ";
    cin >> valinta;
    cout << "\n";
    switch(valinta) {
    case 1:
      valittuKortti = luoMatkakortti();
      break;

    case 2: {
      cout << "Paljonko ladataan?";
      float saldo{};
      cin >> saldo;
      valittuKortti->lataaSaldoa(saldo);
      break;
    }

    case 3:
      valittuKortti->tulostaKortinTiedot();
      break;

    case 4: {
      cout << "Anna uusi nimi (etunimi ja sukunimi): ";
      std::string etunimi, sukunimi;
      cin >> etunimi >> sukunimi;
      valittuKortti->vaihdaNimi(etunimi, sukunimi);
      break;
    }

    case 5:
      matkusta(valittuKortti);
      break;


    case 6:
      leimaaja.tulostaLeimaustapahtumat();
      break;

    case 7:
      leimaaja << valittuKortti;
      break;

    case 0:
      cout << "Näkemiin!\n";
      jatketaan = false;
      break;

    }
  }
  return 0;
}

std::unique_ptr<Matkakortti> luoMatkakortti()
{
  cout << "1. Luo matkakortti\n"
       << "Anna nimi (etunimi ja sukunimi): ";
  std::string etunimi, sukunimi;
  cin >> etunimi >> sukunimi;
  std::unique_ptr<Matkakortti> kortti(new Matkakortti(etunimi, sukunimi));
  return kortti;
}

void matkusta(std::unique_ptr<Matkakortti> &kortti)
{
       cout << "Matkan tyyppi?\n"
           << " 1. Sisäinen matka\n"
           << " 2. Seutumatka\n";
      int matkatyyppi{};
      cin >> matkatyyppi;
      Matkalippu lippu(0);
      if(matkatyyppi == 1) {
        lippu = Matkalippu("Sisäinen lippu", 2.80);
      } else if(matkatyyppi == 2) {
        lippu = Matkalippu("Seutulippu", 4.50);
      }
      leimaaja.leimaa(kortti, lippu);
}
