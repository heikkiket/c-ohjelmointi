#include "paneeli.h"

Paneeli::Paneeli() {}
Paneeli::~Paneeli() {}

void Paneeli::naytaLeimauksenTiedot(std::unique_ptr<Leimaustapahtuma> &leimaus)
{

}

void naytaVirheviesti(std::string viesti);

void Paneeli::piirraPaneeli()
{
  this->piirraReunus();
  this->piirraOtsikko();
  this->tulostaRivi("");
  this->tulostaRivi(this->tulostaVihrea("test"));
  this->tulostaRivi("Tahan sisaltoa useammankin rivin verran");
  this->tulostaRivi("");
  this->tulostaRivi("@T: Heikki");
  this->piirraReunus();
}

void Paneeli::tulostaRivi(std::string teksti)
{
  std::cout << "|" << this->piirraPadding()
            << std::left << std::setw(this->contentWidth())
            << teksti.substr(0, this->contentWidth())
            << this->piirraPadding() << "|"
            << "\n";

  if(teksti.length() > this->contentWidth())
    this->tulostaRivi(teksti.substr(this->contentWidth()));
}

std::string Paneeli::piirraPadding()
{
  return std::string(this->hPadding, ' ');
}

int Paneeli::contentWidth()
{
  return this->width - (this->hPadding * 2) - 2;
}

void Paneeli::piirraOtsikko() {
  this->tulostaRivi(this->piirraCentered("[LEIMAUSLAITE]"));
}

void Paneeli::piirraReunus()
{
  std::cout << "+" << std::string(this->width-2, '-') << "+" << '\n';
}

std::string Paneeli::piirraCentered(std::string mjono)
{
  int centerPadding = (this->contentWidth() - mjono.length()) / 2;
  return std::string(centerPadding, ' ')
    + mjono
    + std::string(centerPadding, ' ');
}

std::string Paneeli::tulostaPunainen(std::string mjono)
{
  return "\033[1;31m" + mjono + "\033[0m";
}

std::string Paneeli::tulostaVihrea(std::string mjono)
{
  return "\033[1;32m" + mjono + "\033[0m";
}
