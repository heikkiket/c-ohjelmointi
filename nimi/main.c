#include <stdio.h>
#include <string.h>

char nimi[256];

void kysyNimi();
void tulostaNimi();
void tulostaNimiTakaperin();
void tulostaKehote();
void kapitalisoi();

int main()
{
  kysyNimi();
  printf("Nimesi on ");
  tulostaNimi(&nimi);
  printf("Takaperin se on ");
  tulostaNimiTakaperin(&nimi);
  printf("ISOILLA KIRJAIMILLA:");
  kapitalisoi(&nimi);
  return 0;
}

void tulostaKehote()
{
  printf("\n>");
}


void kysyNimi()
{
  printf("Mikä on nimesi? ");
  tulostaKehote();
  fgets(nimi, 256, stdin);
}

void tulostaNimi(char* pNimi)
{
  char* pointer = pNimi;
  while(*pointer !='\0') {
  	printf("%c", *pointer);
  	pointer++;
  }
}

void tulostaNimiTakaperin(char* pNimi)
{
  // Go to the end, but skip over newline and null character
  char *pointer = pNimi + strlen(pNimi) - 2;

  while(pNimi <= pointer) {
  	printf("%c", *pointer);
  	pointer--;
  }
  printf("\n");
}

void kapitalisoi(char* pNimi)
{
  int charDifference = 32;

  while(*pNimi != '\n') {
    if('a' <= *pNimi && *pNimi <= 'z') {
      printf("%c", (*pNimi) - charDifference);
    } else {
      printf("%c", *pNimi);
    }
    pNimi++;
  }
  printf("%c", '\n');
}
