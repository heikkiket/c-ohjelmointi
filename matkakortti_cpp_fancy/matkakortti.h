#ifndef MATKAKORTTI_H
#define MATKAKORTTI_H

#include <string>
#include <memory>
#include <iostream>

#include "matkalippu.h"
#include "henkilokortti.h"
#include "lompakko.h"

class Matkakortti : public HenkiloKortti, public Lompakko
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

  void lataaSaldoa(float saldo);

  std::string getEtunimi();
  std::string getSukunimi();
  std::string palautaVirhe();

  friend std::ostream &operator<<(std::ostream &os, const Matkakortti &kortti);
};

#endif
