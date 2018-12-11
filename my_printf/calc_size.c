/*
** ETNA PROJECT, 10/12/2018 by ndiaye_b@etna-alternance.fr
** my_ls
** File description:
**      fonction qui calcule les tailles
*/


unsigned int	calc_int(long long nb)
{
  unsigned int	size;

  size = 1;
  if (nb < 0)
  {
    size = 2;
    nb = -nb;
  }
  while (nb / 10 > 0)
  {
    size = size + 1;
    nb = nb / 10;
  }
  return (size);
}

unsigned int	calc_uint(unsigned long long nb)
{
  unsigned int	size;

  size = 1;
  while (nb / 10 > 0)
  {
    size = size + 1;
    nb = nb / 10;
  }
  return (size);
}

unsigned int	calc_octal(unsigned long long nb)
{
  unsigned int	size;

  size = 1;
  while (nb / 8 > 0)
  {
    nb = nb / 8;
    size = size + 1;
  }
  return (size);
}

unsigned int	calc_hexa(unsigned long long nb)
{
  unsigned int	size;

  size = 1;
  while (nb / 16 > 0)
  {
    nb = nb / 16;
    size = size + 1;
  }
  return (size);
}

unsigned int	calc_binary(unsigned long long nb)
{
  unsigned int	size;

  size = 1;
  while (nb / 2 > 0)
  {
    nb = nb / 2;
    size = size + 1;
  }
  return (size);
}
