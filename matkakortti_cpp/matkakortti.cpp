#include <iostream>

#include "matkakortti.h"

Matkakortti::Matkakortti(std::string etunimi, std::string sukunimi)
{
  this->vaihdaNimi(etunimi, sukunimi);
  this->saldo = 0;
}

void Matkakortti::vaihdaNimi(std::string aetunimi, std::string asukunimi)
{
  etunimi = aetunimi;
  sukunimi = asukunimi;
}

void Matkakortti::tulostaKortinTiedot()
{
  std::cout << "---- Matkakortin tiedot ----\n";
  std::cout << "Omistaja: " << etunimi << " " << sukunimi << "\nSaldo: " << saldo << "\n";
}

void Matkakortti::lataaSaldoa(float saldo)
{
  this->saldo += saldo;
}

void Matkakortti::matkusta(Matkalippu lippu)
{
  if(this->veloitaLippu(lippu)) {
    std::cout << "Matka tehty\n";
  } else {
    std::cout << "Matkustaminen epäonnistui: saldoa ei ole riittävästi.\n";
  }
}

bool Matkakortti::veloitaLippu(Matkalippu lippu)
{

  if (this->saldo - lippu.getHinta() < 0) {
    return false;
  }

  this->saldo -= lippu.getHinta();
  return true;
}
