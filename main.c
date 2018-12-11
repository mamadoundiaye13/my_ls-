/*
** ETNA PROJECT, 11/12/2018 by ndiaye_b@etna-alternance.net
** my_ls
** File description:
**      fonction principale du projet .
*/


#include <stdlib.h>
#include "my_ls.h"

int		main(int argc, char **argv)
{
  t_options	*options;
  t_list_file	*list_file;
  int		check_option;
  int		i;

  i = 1;
  check_option = 0;
  list_file = NULL;
  if ((init_options(&options)) == 1)
    return (1);
  while (i < argc)
  {
    if (argv[i][0] == '-')
      check_option = get_option(argv[i], &options);
    else
      check_option += push_file(options, &list_file, argv[i], 0);
    if (check_option != 0)
      return (1);
    i = i + 1;
  }
  if ((my_ls(options, list_file)) == -1)
    return (1);
  free_list_file(&list_file);
  free(options);
  return (0);
}
