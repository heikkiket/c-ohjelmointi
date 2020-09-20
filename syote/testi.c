#include <stdio.h>
#include <string.h>

int main()
{
  char mjono[256];
  printf("Anna merkkijono> ");
  fgets(mjono, 256, stdin);
  printf("Merkkijonon \"%s\" pituus on %ld.\n", mjono, strlen(mjono));
  return 0;
}
