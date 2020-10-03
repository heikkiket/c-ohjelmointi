#include <iostream>
#include <vector>

#include "matkakortti.h"
#include "matkalippu.h"
#include "leimaustapahtuma.h"

class Leimaaja
{
private:
  std::vector<Leimaustapahtuma> leimaustapahtumat;
  void kirjaaLeimaustapahtuma(Matkakortti kortti, Matkalippu lippu);
  int linja {-1};
public:
  Leimaaja();
  Leimaaja(int linja);
  ~Leimaaja();
  void leimaa(std::shared_ptr<Matkakortti> kortti, Matkalippu lippu);

  void tulostaLeimaustapahtumat();
};
