#include <stdio.h>

void lueLuvut(int *taulukko);
int lueLuku(int i);
void tulostaTaulukko(int *taulukko);

int main()
{
  int taulukko[10] = {0};
  lueLuvut(taulukko);
  tulostaTaulukko(taulukko);
  return 0;
}

void lueLuvut(int *taulukko)
{
  for(int i = 0; i < sizeof(taulukko); i+=2) {
    taulukko[i] = lueLuku(i);
  }
}

int lueLuku(int i)
{
  int luku;
  printf("Anna luku alkioon %d:", i);
  scanf("%d%*c", &luku);

  return luku;
}

void tulostaTaulukko(int *taulukko)
{
  char sarake1[] = "Alkio";
  char sarake2[] = "Sisältö";
  char sarake3[] = "Muistiosoite (heksa)";
  char sarake4[] = "Muistiosoite (desimaali)";
  printf("| %5s | %7s | %20s | %24s |\n", sarake1, sarake2, sarake3, sarake4);
  char erotin[] = "+-------+---------+----------------------+--------------------------+\n";
    printf("%s", erotin);
  for(int i = 0; i < sizeof(taulukko); i++) {
    printf("| %5d ", i);
    printf("| %7d ", taulukko[i]);
    printf("| %20p ", (void*) taulukko+i);
    printf("| %24d ", (int*) taulukko+i);
    printf("|\n");
  }
  printf("%s", erotin);
}
