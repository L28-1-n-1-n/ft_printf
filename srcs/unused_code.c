int check_neg(intmax_t n, t_block *blksk)
{
  if (blksk->modifier == hh)
    if (n >> 7)
      return (1);
  if (blksk->modifier == h)
    if (n >> 15)
      return (1);
  if ((blksk->modifier == ll) || (blksk->modifier == l) ||
      (blksk->modifier == L) || (blksk->modifier == z))
      {
        printf("hola !\n");
        if ((n >= 429496729) || (n <= -32769))
        {
          printf("hola 2!\n");
          printf("n is %jd\n", n);

        // actuall this is too annoying.
        // Just 15 & n -> get last 4 digits, put them in string
        // then n >> 4, repeat, until
          if (n >> 63)
            return (1);
        }
        else
        {
          if (n >> 31)
          {
            printf("n >> 31 is %jd", n >> 31);
            return (1);
          }
        }
      }

  // x is unsigned int, 2^32
  if (blksk->modifier == 0)
    if (n >> 31)
      return (1);
  return (0);
}

void string_neg_hex(intmax_t n, char *final, char *str, t_block *blksk, char *hex) //  the only type to call this is x and X
{
//  char hex[16];
  char tmp[4];
  int i;
  int count;
  intmax_t k;

  count = 0;
  printf("we got here\n");
  ft_bzero(tmp, 4);

  if ((blksk->modifier == ll) || (blksk->modifier == l) ||
      (blksk->modifier == L) || (blksk->modifier == z))
      {
        if ((n >= 429496729) || (n <= -32769))
          count = 60; //60-4
        else
          count = 28; //32-4
      }
  else
    if ((blksk->modifier == h) || (blksk->modifier == 0))
        count = 12; // 16-4
  else
    if (blksk->modifier == hh)
      count = 4; // 8-4, first get left most 4 bits
/*  if (blksk->type = 'X')
    hex = "0123456789ABCDEF";
  if (blksk->type = 'x')
    hex = "0123456789abcdef";*/
    print_n(n);
    printf("initial count is %d\n", count);
  while (count > 0)
  {
    k = (n & (15 << count));
    count -=4;
    k = k >> count;
    i = 3;
    while (i >= 0)
    {
      tmp[i] = hex[k % 16];
      k = k / 16;
      i--;
    }
    ft_strcat(str, tmp);
   // you get 8 bit 2nd time round, so need to << 4 as well
  }
  printf("str is finally %s\n", str);
  ft_strcat(final, str);
}
