#ifndef MATKALIPPU_H
#define MATKALIPPU_H

#include <string>

class Matkalippu
{
 private:
  float hinta;
  std::string nimi;
 public:
  Matkalippu(float hinta);
  Matkalippu(std::string nimi, float hinta);
  float getHinta();
  std::string getNimi();
};

#endif
