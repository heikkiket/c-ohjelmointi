#ifndef MATKAKORTTI_H
#define MATKAKORTTI_H

#include <string>

#include "matkalippu.h"

class Matkakortti
{

private:
  std::string *etunimi;
  std::string *sukunimi;
  float *saldo;
  bool veloitaLippu(Matkalippu lippu);

public:
  Matkakortti(std::string aetunimi, std::string asukunimi);
  ~Matkakortti();
  void matkusta(Matkalippu lippu);
  void vaihdaNimi(std::string aetunimi, std::string asukunimi);
  void lataaSaldoa(float saldo);
  void tulostaKortinTiedot();
};

#endif
