#ifndef PANEELI_H
#define PANEELI_H

#include <string>
#include <memory>
#include <iostream>
#include <iomanip>

#include "leimaustapahtuma.h"

class Paneeli
{
public:
  Paneeli();
  void naytaLeimauksenTiedot(std::shared_ptr<Leimaustapahtuma> &leimaus);
  void naytaVirheviesti(std::string viesti);
  ~Paneeli();
  void piirraPaneeli(std::string sisalto);
private : int width = 40;
  int hPadding = 1;
  void piirraReunus();
  void piirraOtsikko();
  std::string piirraCentered(std::string mjono);
  void tulostaRivi(std::string teksti);
  int contentWidth();
  std::string piirraPadding();
  std::string tulostaPunainen(std::string mjono);
  std::string tulostaVihrea(std::string mjono);
};

#endif
