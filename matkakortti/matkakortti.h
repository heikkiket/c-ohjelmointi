#include "matkalippu.h"

#ifndef MATKALIPPU_H
#define MATKALIPPU_H

#include <stdio.h>
#include <stdbool.h>

#define STATUS_AIKUINEN 1
#define STATUS_OPISKELIJA 2
#define STATUS_LAPSI 3

typedef struct Matkakortti {
  char nimi[256];
  float saldo;
  short status;
} Matkakortti;

Matkakortti luo_kortti(char *nimi, short status);
void vaihdaNimi(Matkakortti *kortti, char *uusiNimi);
void tulostaKortinTiedot(Matkakortti *kortti);
void lataaSaldoa(Matkakortti *kortti, float arvo);
bool matkusta(Matkakortti *kortti, Lippu *lippu);

#endif
