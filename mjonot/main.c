#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* kysySyote();
void tulostaKehote();
char* yhdistaMerkkijonot(char* mjono1, char* mjono2);
void copyString(char *source, char *destination, int startPoint);
char* trim(char* mjono);

int main()
{
  printf("Kysyn kaksi merkkijonoa ja yhdistän ne. Syötä ensimmäinen merkkijono:");
  char* mjono1 = kysySyote();
  printf("Syötä toinen merkkijono");
  char* mjono2 = kysySyote();
  char* tulos = yhdistaMerkkijonot(mjono1, mjono2);
  printf("Yhdiste on: %s\n", tulos);
  return 0;
}


char* kysySyote()
{
  char mjono[256];
  tulostaKehote();
  fgets(mjono, 256, stdin);
  return trim(mjono);
}

char* trim(char* mjono)
{
  char* trimmed = malloc(strlen(mjono));
  int i = 0;
  int j = 0;

  while(mjono[i] != '\0') {
    if(mjono[i] != '\n') {
      trimmed[j] = mjono[i];
      j++;
    }
    i++;
  }
  trimmed[j] = '\0';

  return trimmed;

}


char* yhdistaMerkkijonot(char* mjono1, char* mjono2)
{
  int length = strlen("asd") + strlen("asd");
  char* combined = (char *) malloc(length);

  printf("Muistia varattu: %d tavua.\n", length);

  copyString(mjono1, combined, 0);
  copyString(mjono2, combined, strlen(mjono1));

  return combined;
}

void copyString(char *source, char *destination, int startPoint)
{
  int i = 0;
  int j = startPoint;

  while(source[i] != '\0') {
    destination[j] = source[i];
    i++;
    j++;
  }
}

void tulostaKehote()
{
  printf("\n>");
}
