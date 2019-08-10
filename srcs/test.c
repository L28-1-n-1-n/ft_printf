#include "printf.h"
#include <stdio.h>

int main()
{
  printf("Test for formats:\n\n");
  ft_printf("HEX 00042 %#x\n", 00042);
  printf("HEX 00042 %#x\n\n", 00042);

  ft_printf("HEX 4242 %-#x\n", 4242);
  printf("HEX 4242 %-#x\n\n", 4242);

  ft_printf("HEX 4242 %0#X\n", 4242);
  printf("HEX 4242 %0#X\n\n", 4242);

  ft_printf("HEX 4242 %0#30x\n", 4242);
  printf("HEX 4242 %0#30x\n\n", 4242);

  ft_printf("HEX 4242 %-#30x\n", 4242);
  printf("HEX 4242 %-#30x\n\n", 4242);

  ft_printf("OCT 00042 %#o\n", 00042);
  printf("OCT 00042 %#o\n\n", 00042);

  ft_printf("OCT 4242 %-#o\n", 4242);
  printf("OCT 4242 %-#o\n\n", 4242);

  ft_printf("OCT 4242 %0#o\n", 4242);
  printf("OCT 4242 %0#o\n\n", 4242);

  ft_printf("OCT 4242 %0#30o\n", 4242);
  printf("OCT 4242 %0#30o\n\n", 4242);

  ft_printf("OCT 4242 %-#30o\n", 4242);
  printf("OCT 4242 %-#30o\n\n", 4242);

  printf("Test for limits:\n\n");
  ft_printf("HEX 2^31 = 2147483648 %lx\n", 2147483648);
  printf("HEX 2^31 = 2147483648 %lx\n\n", 2147483648);

  ft_printf("HEX -2^31 = -2147483648 %lx\n", -2147483648);
  printf("HEX -2^31 = -2147483648 %lx\n\n", -2147483648);

  ft_printf("HEX 2^63 - 1 = 9223372036854775808 %lx\n", 9223372036854775807);
  printf("HEX 2^63 - 1 = 9223372036854775808 %lx\n\n", 9223372036854775807);

  ft_printf("HEX 2^63 = -9223372036854775807 %lx\n", -9223372036854775807);
  printf("HEX 2^63 = -9223372036854775807 %lx\n\n", -9223372036854775807);

  ft_printf("OCT 2^31 = 2147483648 %lo\n", 2147483648);
  printf("OCT 2^31 = 2147483648 %lo\n\n", 2147483648);

  ft_printf("OCT -2^31 = -2147483648 %lo\n", -2147483648);
  printf("OCT -2^31 = -2147483648 %lo\n\n", -2147483648);

  ft_printf("OCT 2^63 = 9223372036854775808 %lo\n", 9223372036854775807);
  printf("OCT 2^63 = 9223372036854775808 %lo\n\n", 9223372036854775807);

  ft_printf("OCT 2^63 = -9223372036854775807 %lo\n", -9223372036854775807);
  printf("OCT 2^63 = -9223372036854775807 %lo\n\n", -9223372036854775807);

  return (0);
}
