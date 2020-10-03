#include "leimaaja.h"

Leimaaja::Leimaaja() {}

Leimaaja::Leimaaja(int linja) {
  this->linja = linja;
  this->paneeli = Paneeli();
}

Leimaaja::~Leimaaja() {}

void Leimaaja::leimaa(std::unique_ptr<Matkakortti> &kortti, Matkalippu lippu)
{
  if(kortti->matkusta(lippu)) {
    std::shared_ptr<Leimaustapahtuma> leimaustapahtuma = this->kirjaaLeimaustapahtuma(kortti, lippu);
    this->paneeli.naytaLeimauksenTiedot(leimaustapahtuma);
  } else {
    this->paneeli.naytaVirheviesti(kortti->palautaVirhe());
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

std::shared_ptr<Leimaustapahtuma> Leimaaja::kirjaaLeimaustapahtuma(std::unique_ptr<Matkakortti> &kortti, Matkalippu lippu)
{
  Leimaustapahtuma tapahtuma = { kortti->getEtunimi(), kortti->getSukunimi(), &lippu };

  leimaustapahtumat.push_back(tapahtuma);

  return std::make_shared<Leimaustapahtuma>(tapahtuma);
}

void Leimaaja::operator<<(std::unique_ptr<Matkakortti> &kortti)
{
  Matkalippu lippu ("Helsinki", 2.80);
  return this->leimaa(kortti,lippu);
}
