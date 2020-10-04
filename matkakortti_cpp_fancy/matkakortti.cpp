#include <iostream>

#include "matkakortti.h"

Matkakortti::Matkakortti(std::string etunimi, std::string sukunimi)
{
  this->vaihdaNimi(etunimi, sukunimi);
  saldo = std::unique_ptr<float>(new float(0));
}

Matkakortti::~Matkakortti() {
  std::cout << "Matkakortin destruktori suoritettu!\n";
}

void Matkakortti::vaihdaNimi(std::string aetunimi, std::string asukunimi)
{
  etunimi = std::unique_ptr<std::string>(new std::string(aetunimi));
  sukunimi = std::unique_ptr<std::string>(new std::string(asukunimi));
}


void Matkakortti::lataaSaldoa(float asaldo)
{
  *saldo = *saldo + asaldo;
}

bool Matkakortti::matkusta(Matkalippu lippu)
{
  if(this->veloitaLippu(lippu)) {
    return true;
  } else {
    virhe = std::make_shared<std::string> ("Matkustaminen epäonnistui: saldoa ei ole riittävästi.");
    return false;
  }

}

std::string Matkakortti::getEtunimi()
{
  return *etunimi;
}

std::string Matkakortti::getSukunimi()
{
  return *sukunimi;
}

std::string Matkakortti::palautaVirhe()
{
  return *virhe;
}

bool Matkakortti::veloitaLippu(Matkalippu lippu) {

  if (*saldo - lippu.getHinta() < 0) {
    return false;
  }

  *saldo -= lippu.getHinta();
  return true;
}

std::ostream &operator<<(std::ostream &os, const Matkakortti &kortti)
{
  os << "---- Matkakortin tiedot ----\n";
  os << "Omistaja: " << *kortti.etunimi << " " << *kortti.sukunimi
            << "\nSaldo: " << *kortti.saldo << "\n";
  return os;
}
