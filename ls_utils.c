/*
** ETNA PROJECT, 11/12/2018 by ndiaye_b@etna-alternance.net
** my_ls
** File description:
**      mes fonctions utiles (de depannage ) pour le projet my_ls
*/


#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return ;
  while (str[i])
  {
    my_putchar(str[i]);
    i = i + 1;
  }
}

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

void	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  while (str[i])
  {
    my_putchar_error(str[i]);
    i = i + 1;
  }
}

int	size_nb(unsigned long long nb)
{
  int	size;

  size = 1;
  while (nb >= 10)
  {
    nb = nb / 10;
    size = size + 1;
  }
  return (size);
}
