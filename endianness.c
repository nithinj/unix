#include<stdio.h>



/* 
   Function check_for_endianness() returns 1, if architecture 
   is little endian, 0 in case of big endian.
 */
 
int check_for_endianness()
{
  unsigned int x = 1;
  char *c = (char*) &x;
  return (int)*c;
}

int
main()
{
 if (check_for_endianness())
	printf("Little Endian\n");
else
	printf("Big Endian\n");

return 0;
}
