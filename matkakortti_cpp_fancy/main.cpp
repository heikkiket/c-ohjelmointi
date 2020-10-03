#include <iostream>
#include <string>

using namespace std;

#include "matkakortti.h"
#include "leimaaja.h"

int main()
{
  bool jatketaan = true;
  int valinta = 0;
  std::shared_ptr<Matkakortti> valittuKortti;

  int linja;
  cout << "Anna linjan nimi, jolla leimaaja leimaa: ";
  cin >> linja;

  Leimaaja leimaaja (linja);

  while(jatketaan) {
    cout << "\n\n1. Luo matkakortti\n";
    cout << "2. Lataa saldoa\n";
    cout << "3. Tulosta kortin tiedot\n";
    cout << "4. Vaihda kortin haltijan nimi\n";
    cout << "5. Matkusta kortilla\n";
    cout << "6. Tulosta leimaustapahtumat\n";
    cout << "0. Poistu\n\n";
    cout << "Anna valinta: ";
    cin >> valinta;
    cout << "\n";
    switch(valinta) {
    case 1: {
      cout << "1. Luo matkakortti\n"
           << "Anna nimi (etunimi ja sukunimi): ";
      std::string etunimi, sukunimi;
      cin >> etunimi >> sukunimi;
      valittuKortti = std::unique_ptr<Matkakortti>(new Matkakortti(etunimi, sukunimi));
      break;
    }

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

    case 5: {
      cout << "Matkan tyyppi?\n"
           << " 1. Sisäinen matka\n"
           << " 2. Seutumatka\n";
      int matkatyyppi{};
      cin >> matkatyyppi;
      Matkalippu lippu(0);
      if(matkatyyppi == 1) {
        lippu = Matkalippu(2.80);
      } else if(matkatyyppi == 2) {
        lippu = Matkalippu(4.50);
      }
      leimaaja.leimaa(valittuKortti, lippu);
      break;
    }

    case 6:
      leimaaja.tulostaLeimaustapahtumat();
      break;

    case 0:         cout << "Näkemiin!\n";
      jatketaan = false;
      break;

    }
  }
  return 0;
}
