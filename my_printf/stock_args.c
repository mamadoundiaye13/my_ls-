/*
** ETNA PROJECT, 10/12/2018 by ndiaye_b@etna-alternance.fr
** my_ls
** File description:
**      fonction pour stocker des arguments
*/

#include "my_printf.h"
#include <stdarg.h>
#include <stddef.h>


void	stock_arg(va_list *arg, t_tmp_arg *tmp, char c)
{
  tmp->uint = 0;
  tmp->t_int = 0;
  tmp->t_char = NULL;
  tmp->ptr = NULL;
  tmp->chars_to_save = NULL;

  if (c == 's' || c == 'S')
    tmp->t_char = va_arg(*arg, char *);
  else if (c == 'p')
    tmp->ptr = va_arg(*arg, void *);
  else if (c == 'c' || c == 'd' || c == 'i')
    tmp->t_int = va_arg(*arg, long long);
  else if (c == 'n')
    tmp->chars_to_save = va_arg(*arg, unsigned int *);
  else
    tmp->uint = va_arg(*arg, unsigned long long);
}
