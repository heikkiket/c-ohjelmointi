#include <iostream>
#include <vector>
#include <memory>

#include "matkakortti.h"
#include "matkalippu.h"
#include "leimaustapahtuma.h"

class Leimaaja
{
private:
  std::vector<Leimaustapahtuma> leimaustapahtumat;
  void kirjaaLeimaustapahtuma(std::unique_ptr<Matkakortti> &kortti, Matkalippu lippu);
  int linja {-1};
public:
  Leimaaja();
  Leimaaja(int linja);
  ~Leimaaja();
  void leimaa(std::unique_ptr<Matkakortti> &kortti, Matkalippu lippu);

  void tulostaLeimaustapahtumat();
};
