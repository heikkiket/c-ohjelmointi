#ifndef LEIMAAJA_H
#define LEIMAAJA_H

#include <iostream>
#include <vector>
#include <memory>

#include "matkakortti.h"
#include "matkalippu.h"
#include "leimaustapahtuma.h"
#include "paneeli.h"

class Leimaaja
{
private:
  std::vector<Leimaustapahtuma> leimaustapahtumat;
  std::shared_ptr<Leimaustapahtuma> kirjaaLeimaustapahtuma(std::unique_ptr<Matkakortti> &kortti, Matkalippu lippu);
  Paneeli paneeli;
  int linja {-1};
public:
  Leimaaja();
  Leimaaja(int linja);
  ~Leimaaja();
  void leimaa(std::unique_ptr<Matkakortti> &kortti, Matkalippu lippu);

  void tulostaLeimaustapahtumat();
};

#endif
