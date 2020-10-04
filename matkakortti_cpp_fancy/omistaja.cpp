#include "omistaja.h"

Omistaja::Omistaja() {}

Omistaja::Omistaja(std::string aetunimi, std::string asukunimi) {
  this->vaihdaNimi(aetunimi, asukunimi);
}

void Omistaja::vaihdaNimi(std::string aetunimi, std::string asukunimi) {
  etunimi = std::unique_ptr<std::string>(new std::string(aetunimi));
  sukunimi = std::unique_ptr<std::string>(new std::string(asukunimi));
}

std::string Omistaja::annaNimi() const
{
  return *etunimi + " " + *sukunimi;
}
