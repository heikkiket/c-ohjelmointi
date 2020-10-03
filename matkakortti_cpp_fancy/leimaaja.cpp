#include "leimaaja.h"

Leimaaja::Leimaaja() {}

Leimaaja::Leimaaja(int linja) {
  this->linja = linja;
}

Leimaaja::~Leimaaja() {}

void Leimaaja::leimaa(std::unique_ptr<Matkakortti> &kortti, Matkalippu lippu)
{
  if(kortti->matkusta(lippu)) {
    std::cout << "Matka Leimaajalla tehty\n";
    this->kirjaaLeimaustapahtuma(kortti, lippu);
  } else {
    std::cout << "Ei onnistunut\n";
  }

}

void Leimaaja::tulostaLeimaustapahtumat()
{
  int lukumaara = 5;

  if (this->linja != -1) {
    std::cout << "Linjan " << this->linja << " ";
  }
  std::cout << lukumaara << " viimeisintä leimaustapahtumaa:";
  std::cout << "\n";

  int index = 0;
  for (auto tapahtuma = leimaustapahtumat.rbegin();
       tapahtuma != leimaustapahtumat.rend();
       ++tapahtuma) {

    std::cout << " " << tapahtuma->tulosta() << "\n";

    index++;

    if (index == lukumaara) {
      break;
    }
  }
}

void Leimaaja::kirjaaLeimaustapahtuma(std::unique_ptr<Matkakortti> &kortti, Matkalippu lippu)
{
  Leimaustapahtuma tapahtuma = { kortti->getEtunimi(), kortti->getSukunimi()};
  leimaustapahtumat.push_back(tapahtuma);
}
