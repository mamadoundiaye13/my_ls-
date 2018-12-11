/*
** ETNA PROJECT, 11/12/2018 by ndiaye_b@etna-alternance.net
** my_ls
** File description:
**      fonctions pour les listes chainées des fichiers
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_ls.h"

t_list_file	*create_elem(char *name)
{
  t_list_file	*new;

  new = NULL;
  new = (t_list_file*)my_malloc(sizeof(*new));
  if (new)
  {
    new->name = name;
    new->infos = NULL;
    new->next = NULL;
  }
  return (new);
}

int	push_file(t_options *options, t_list_file **pile_file, char *name,
		  time_t time)
{
  if (*pile_file)
  {
    if (options->r == 0 && options->t == 0)
      return (push_sort_file(pile_file, name));
    else if (options->r == 1 && options->t == 0)
      return (push_rsort_file(pile_file, name));
    else if (options->r == 0 && options->t == 1)
      return (push_time_file(pile_file, name, time));
    else
      return (push_rtime_file(pile_file, name, time));
  }
  else
  {
    if ((*pile_file = create_elem(name)) == NULL)
      return (-1);
    (*pile_file)->time = time;
  }
  return (0);
}

void		free_list_file(t_list_file **pile)
{
  t_list_file	*tmp;
  t_list_file	*tmp_next;

  tmp = *pile;
  while (tmp)
  {
    tmp_next = tmp->next;
    free(tmp->infos);
    free(tmp);
    tmp = tmp_next;
  }
}
