#include <time.h>
#include <string>
#include <cstdio>

class Leimaustapahtuma
{
private:
  std::string etunimi;
  std::string sukunimi;
  struct tm aikaleima;
public:
  Leimaustapahtuma(std::string etunimi, std::string sukunimi);
  std::string getNimi();
  std::string getAika();
  std::string tulosta();
  ~Leimaustapahtuma();
};

