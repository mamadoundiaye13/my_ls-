#include "my_printf.h"

unsigned int	save_chars(t_tmp_arg *tmp, unsigned int chars_to_save)
{
  *(tmp->chars_to_save) = chars_to_save;
  return (0);
}
