#include "printf.h"
#include <stdio.h>

void check_buff(char *final, char *str, size_t len)
{
  unsigned int final_len;
  unsigned int loop;

  final_len = ft_strlen(final);
  loop = 0;


    if (len + final_len >= FLEN) // check if buffer is full, then cat whatever you can into remaining space in buuffer
    {
      while ((loop < len) && (len + final_len >= FLEN))
      {
        ft_strncat(final, &str[loop], FLEN - final_len);
        loop += FLEN - final_len;
        output_final(final);
        final_len = ft_strlen(final);
      }
      if (len + final_len < FLEN)
        ft_strncat(final, &str[loop], len);
    }
    else
      ft_strncat(final, str, len);
}
