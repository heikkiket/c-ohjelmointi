#include "matkalippu.h"

Matkalippu::Matkalippu(float hinta)
{
  this->hinta = hinta;
  this->nimi = "";
}

Matkalippu::Matkalippu(std::string nimi, float hinta)
{
  this->hinta = hinta;
  this->nimi = nimi;
}

float Matkalippu::getHinta()
{
  return hinta;
}

std::string Matkalippu::getNimi()
{
  return nimi;
}
