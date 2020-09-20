#include <string.h>

#include "matkakortti.h"

Matkakortti luo_kortti(char *nimi, short status)
{
  Matkakortti kortti = { "", 0.00, status };
  vaihdaNimi(&kortti, nimi);
  return kortti;
}

void vaihdaNimi(Matkakortti *kortti, char *uusiNimi)
{
  int len = strlen(uusiNimi);
  strncpy(kortti->nimi, uusiNimi, len);
}

void lataaSaldoa(Matkakortti *kortti, float arvo)
{
  kortti->saldo += arvo;
}

bool matkusta(Matkakortti *kortti, Lippu *lippu)
{
  if(kortti->saldo - lippu->hinta < 0) {
    return false;
  }

  kortti->saldo -= lippu->hinta;
  return true;
}

void tulostaKortinTiedot(Matkakortti *kortti)
{
  printf("---- Matkakortti ----\n");
  printf("Omistaja: %s \nSaldo: %f\n", kortti->nimi, kortti->saldo);
}
