#ifndef OMISTAJA_H
#define OMISTAJA_H

#include <iostream>
#include <string>
#include <memory>

class Omistaja
{
public:
  Omistaja();
  Omistaja(std::string aetunimi, std::string asukunimi);
  void vaihdaNimi(std::string aetunimi, std::string asukunimi);
  std::string annaNimi() const;

protected:
  std::shared_ptr<std::string> etunimi;
  std::shared_ptr<std::string> sukunimi;
};

#endif
