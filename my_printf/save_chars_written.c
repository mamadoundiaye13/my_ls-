/*
** ETNA PROJECT, 10/12/2018 by ndiaye_b@etna-alternance.net
** my_ls
** File description:
**      fonction pour sauvegarder un char
*/

#include "my_printf.h"

unsigned int	save_chars(t_tmp_arg *tmp, unsigned int chars_to_save)
{
  *(tmp->chars_to_save) = chars_to_save;
  return (0);
}
