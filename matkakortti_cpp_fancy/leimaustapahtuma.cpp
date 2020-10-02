#include "leimaustapahtuma.h"

Leimaustapahtuma::Leimaustapahtuma(std::string etunimi, std::string sukunimi)
{
  this->etunimi = etunimi;
  this->sukunimi = sukunimi;

  time_t sekunnit;
  time (&sekunnit);

  localtime_r(&sekunnit, &aikaleima);
}

Leimaustapahtuma::~Leimaustapahtuma() {}

std::string Leimaustapahtuma::getNimi()
{
  return etunimi + " " + sukunimi;
}

std::string Leimaustapahtuma::getAika()
{
  char stamp[9];
  snprintf(stamp, 9, "%02d:%02d:%02d",
           aikaleima.tm_hour, aikaleima.tm_min, aikaleima.tm_sec);

  return std::string(stamp);
}

std::string Leimaustapahtuma::tulosta()
{
  return this->getNimi() + " " + this->getAika();
}
