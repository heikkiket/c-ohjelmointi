#include <stdio.h>

void main()
{
  char merkki;
  scanf("%c%*c", &merkki);
  printf("Mikä on nimesi? ");
  fflush(stdin);
  char nimi[256];
  fgets(nimi, 256, stdin);
  printf("Nimesi on: %s\n", nimi);
}
