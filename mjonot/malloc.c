#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int length = 15;
  char* str = (char* ) malloc(length);
  strcpy(str, "Testi merkkijono");
  printf("String: %s\n", str);
  return 0;
}
