#ifndef LEIMAUSTAPAHTUMA_H
#define LEIMAUSTAPAHTUMA_H

#include <time.h>
#include <string>
#include <cstdio>
#include <memory>

#include "matkalippu.h"
#include <iostream>

class Leimaustapahtuma
{
private:
  std::string etunimi;
  std::string sukunimi;
  struct tm aikaleima;
  std::shared_ptr<Matkalippu> lippu;
public:
  Leimaustapahtuma(std::string etunimi, std::string sukunimi, Matkalippu *lippu);
  std::string getNimi();
  std::string getAika();
  std::string getLippu();
  std::string tulosta();
  ~Leimaustapahtuma();
};

#endif
