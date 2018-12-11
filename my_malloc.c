/*
** ETNA PROJECT, 11/12/2018 by ndiaye_b@etna-alternance.net
** my_ls
** File description:
**      L'allocation dynamique
*/

#include <stdlib.h>

void	*my_malloc(size_t size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    my_putstr_error("Could not alloc\n");
  return (ptr);
}
