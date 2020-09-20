#include <stdio.h>
#include <stdbool.h>

char nimi[256];
int ika;

void tulostaValikko();
int pyydaValinta();
void kysyNimi();
void kysyIka();
void tulostaIka();
void tulostaNimi();
void tulostaKehote();

int main()
{
  bool jatketaan = true;
  tulostaValikko();
  while(jatketaan == true){
    switch(pyydaValinta()) {
    case 1:
      kysyNimi();
      break;
    case 2:
      kysyIka();
      break;
    case 3:
      tulostaNimi();
      break;
    case 4:
      tulostaIka();
      break;
    case 5:
      printf("näkemiin, %s %d vuotta!\n", nimi, ika);
      jatketaan = false;
    }
    tulostaKehote();
  }
  return 0;
}

void tulostaValikko()
{

  printf("Valikko:\n\n");
  printf("1. Kysy nimi\n");
  printf("2. Kysy ikä\n");
  printf("3. Tulosta nimi\n");
  printf("4. Tulosta ikä\n");
  printf("5. Poistu\n");
}

void tulostaKehote()
{
  printf("\n>");
}

int pyydaValinta()
{
  int valinta;
  scanf("%d%*c", &valinta);
  return valinta;
}

void kysyNimi()
{
  printf("Mikä on nimesi? ");
  fgets(nimi, 256, stdin);
}

void kysyIka()
{
  printf("Mikä on ikäsi? ");
  scanf("%d%*c", &ika);
}

void tulostaNimi()
{
  printf("Nimesi on %s", nimi);
}

void tulostaIka()
{
  printf("Ikäsi on %d", ika);
}
