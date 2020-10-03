#ifndef MATKAKORTTI_H
#define MATKAKORTTI_H

#include <string>
#include <memory>

#include "matkalippu.h"

class Matkakortti
{

private:
  std::shared_ptr<std::string> etunimi;
  std::shared_ptr<std::string> sukunimi;
  std::shared_ptr<float> saldo;
  std::shared_ptr<std::string> virhe;
  bool veloitaLippu(Matkalippu lippu);

public:
  Matkakortti(std::string aetunimi, std::string asukunimi);
  ~Matkakortti();
  bool matkusta(Matkalippu lippu);
  void vaihdaNimi(std::string aetunimi, std::string asukunimi);
  void lataaSaldoa(float saldo);
  void tulostaKortinTiedot();
  std::string getEtunimi();
  std::string getSukunimi();
  std::string palautaVirhe();
};

#endif
