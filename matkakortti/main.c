
#include "matkalippu.h"
#include "matkakortti.h"

int main()
{
  Matkakortti kortti1 = luo_kortti("Maija Meikäläinen", STATUS_AIKUINEN);

  tulostaKortinTiedot(&kortti1);
  printf("Lisätään saldoa:\n\n");

  lataaSaldoa(&kortti1, 10.00);

  tulostaKortinTiedot(&kortti1);

  printf("Matkustetaan yksi sisäinen matka:\n\n");

  Lippu sisainen_lippu = luo_sisainen();

  matkusta(&kortti1, &sisainen_lippu);

  tulostaKortinTiedot(&kortti1);

  printf("Matkustetaan yksi matka seutulipulla:\n\n");
  Lippu seutulippu = luo_seutulippu();

  matkusta(&kortti1, &seutulippu);

  tulostaKortinTiedot(&kortti1);

  printf("\n\nYritetään vielä matkustaa seutulipulla:\n\n");
  if(!matkusta(&kortti1, &seutulippu)) {
    printf("Matkustaminen ei onnistunut: saldoa on liian vähän!\n");
  }

  tulostaKortinTiedot(&kortti1);
  return 0;
}


