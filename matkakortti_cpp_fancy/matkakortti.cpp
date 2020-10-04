#include <iostream>

#include "matkakortti.h"
#include "omistaja.h"

Matkakortti::Matkakortti(std::string aetunimi, std::string asukunimi)
  : Omistaja{ aetunimi, asukunimi }
{
  saldo = std::unique_ptr<float>(new float(0));
}

Matkakortti::~Matkakortti() {
  std::cout << "Matkakortin destruktori suoritettu!\n";
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
  os << "Omistaja: " << kortti.annaNimi()
            << "\nSaldo: " << *kortti.saldo << "\n";
  return os;
}
