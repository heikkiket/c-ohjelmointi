#include "matkalippu.h"

Lippu luo_sisainen()
{
  Lippu lippu = { LIPPUTYYPPI_SISAINEN, 2.80 };
  return lippu;
}

Lippu luo_seutulippu()
{
  Lippu lippu = { LIPPUTYYPPI_SEUTU, 3.80 };
  return lippu;
}
