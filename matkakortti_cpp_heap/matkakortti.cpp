#include <iostream>

#include "matkakortti.h"
#include <string>

Matkakortti::Matkakortti(std::string aetunimi, std::string asukunimi)
{
  this->etunimi = new std::string(aetunimi);
  this->sukunimi = new std::string(asukunimi);
  this->saldo = new float(0);
}

Matkakortti::~Matkakortti()
{
  delete etunimi;
  delete sukunimi;
  delete saldo;
}

void Matkakortti::vaihdaNimi(std::string aetunimi, std::string asukunimi)
{
  delete etunimi;
  delete sukunimi;
  etunimi = new std::string(aetunimi);
  sukunimi = new std::string(asukunimi);
}

void Matkakortti::tulostaKortinTiedot()
{
  std::cout << "---- Matkakortin tiedot ----\n";
  std::cout << "Omistaja: " << *etunimi << " " << *sukunimi << "\nSaldo: " << *saldo << "\n";
}

void Matkakortti::lataaSaldoa(float asaldo)
{
  std::cout << "Ladataan: " << asaldo;
  *saldo = *saldo + asaldo;
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

  if (*saldo - lippu.getHinta() < 0) {
    return false;
  }

  *saldo = *saldo - lippu.getHinta();
  return true;
}
