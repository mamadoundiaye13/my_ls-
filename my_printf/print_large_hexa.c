/*
** ETNA PROJECT, 10/12/2018 by ndiaye_b@etna-alternance.net
** my_ls
** File description:
**      les fonctions qui affichent en hexadecimal
*/

#include "my_printf.h"

void	finish_large_hexa(t_tmp_arg *tmp, t_params *params,
			  unsigned int s_to_add,
			  unsigned int s_to_print)
{
  if (params->less == 1)
  {
    if (params->diez == 1 && tmp->uint != 0)
      my_putstr("0X");
    my_put_unsigned_nb(tmp->uint, s_to_print, "0123456789ABCDEF");
  }
  if (params->width >= params->precision && params->zero == 1
      && params->is_precision == 0 && params->less == 0
      && params->width > s_to_print)
    add_zero(s_to_add);
  else if (params->width >= (params->precision) && params->width > s_to_print)
    add_space(s_to_add);
  if (params->less == 0)
  {
    if (params->diez == 1 && tmp->uint != 0)
      my_putstr("0X");
    my_put_unsigned_nb(tmp->uint, s_to_print, "0123456789ABCDEF");
  }
}

unsigned int	print_large_hexa(t_tmp_arg *tmp, t_params *params,
				 unsigned int s_to_add,
				 unsigned int s_to_print)
{
  unsigned int	chars_written;

  chars_written = 0;
  tmp->uint = convert_hexa_length(tmp->uint, params);
  s_to_print = calc_size_to_print(tmp, 'X');
  if (s_to_print < params->precision)
    s_to_print = params->precision;
  if (s_to_print < params->width)
    s_to_add = params->width - s_to_print;
  chars_written = s_to_print + s_to_add;
  if (params->diez == 1)
    s_to_add = s_to_add - 2;
  if (params->diez == 1 && params->is_precision == 0
      && params->zero == 1)
  {
    my_putstr("0X");
    params->diez = 0;
  }
  finish_large_hexa(tmp, params, s_to_add, s_to_print);
  return (chars_written);
}
