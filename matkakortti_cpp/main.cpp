#include <iostream>
#include <string>

using namespace std;

#include "matkakortti.h"

int main()
{
  Matkakortti kortti1 ("Heikki", "Ketoharju");
  Matkalippu sisainen_lippu(2.80);
  Matkalippu seutulippu(4.20);

  kortti1.tulostaKortinTiedot();
  kortti1.vaihdaNimi("Herkko", "Kerkkonen");
  kortti1.tulostaKortinTiedot();

  cout << "Tehdään sisäinen matka (2.80e).\n";
  kortti1.matkusta(sisainen_lippu);

  cout << "Ladataan saldoa, jotta matkustaminen onnistuu\n";
  kortti1.lataaSaldoa(10);
  kortti1.tulostaKortinTiedot();
  cout << "Tehdään sisäinen matka (2.80e).\n";
  kortti1.matkusta(sisainen_lippu);
  cout << "Tehdään seutumatka (4.20e).\n";
  kortti1.matkusta(seutulippu);
  kortti1.tulostaKortinTiedot();
  return 0;
}
