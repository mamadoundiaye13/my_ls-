/*
** ETNA PROJECT, 10/12/2018 by ndiaye_b@etna-alternance.net
** my_ls
** File description:
**      mes fonctions utiles pour le projet.
*/

#include "my_printf.h"
#include <unistd.h>

void	add_space(unsigned int size_to_add)
{
  while (size_to_add > 0)
  {
    write(1, " ", 1);
    size_to_add = size_to_add - 1;
  }
}

void	add_zero(unsigned int size_to_add)
{
  while (size_to_add > 0)
  {
    write(1, "0", 1);
    size_to_add = size_to_add - 1;
  }
}

int	my_atoi(const char *str)
{
  int	i;
  int	number;

  i = 0;
  number = 0;
  while (str[i] >= '0' && str[i] <= '9')
  {
    number = number * 10;
    number = number + ((int)str[i] - '0');
    i = i + 1;
  }
  return (number);
}
