
#ifndef MATKAKORTTI_H
#define MATKAKORTTI_H

#define LIPPUTYYPPI_SEUTU 1
#define LIPPUTYYPPI_SISAINEN 2

typedef struct Lippu {
  short lipputyyppi;
  float hinta;
} Lippu;

Lippu luo_sisainen();

Lippu luo_seutulippu();

#endif
