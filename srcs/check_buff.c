#include "printf.h"
#include <stdio.h>

void check_buff(char *final, char *str, size_t len)
{
  unsigned int final_len;
  unsigned int loop;
  unsigned int limit;

  limit = (unsigned int)(FLEN / (unsigned int)5 * (unsigned int)4);
  final_len = ft_strlen(final);
  loop = 0;
// new idea : never overflow final, check buff set at 80% of buffer, hence impossible to overflow
    if (len + final_len >= limit) // check if buffer is full, then cat whatever you can into remaining space in buuffer
    {
      while ((loop < len) && (len + final_len >= limit))
      {
        ft_strncat(final, &str[loop], limit - final_len);
        loop += limit - final_len;
        output_final(final, FLEN, 0);
        final_len = ft_strlen(final);
      }
      if (len + final_len < limit)
        ft_strncat(final, &str[loop], len);
    }
    else
      ft_strncat(final, str, len);
}
