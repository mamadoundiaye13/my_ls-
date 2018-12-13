/*
** ETNA PROJECT, 11/12/2018 by ndiaye_b@etna-alternance.net
** my_ls
** File description:
**      les fonctions pour rcuperer les options de ls
*/


#include <stdlib.h>
#include "my_ls.h"


// On initialise toutes les options
int	init_options(t_options **options)
{
  if ((*options = (t_options*)my_malloc(sizeof(t_options))) == NULL)
    return (1);
  (*options)->l = 0;
  (*options)->L = 0;
  (*options)->r = 0;
  (*options)->R = 0;
  (*options)->a = 0;
  (*options)->A = 0;
  (*options)->d = 0;
  (*options)->t = 0;
  (*options)->g = 0;
  return (0);
}

// On cherche une option
int	search_options(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i])
  {
    if (str[i] == c)
      return (1);
    i = i + 1;
  }
  return (0);
}


// message d'Erreur si l'option n'existe pas
int	search_bad_options(char *str)
{
  int	i;

  i = 0;
  while (str[i])
  {
    if (str[i] != '-' && str[i] != 'l' && str[i] != 'R' && str[i] != 'd'
        && str[i] != 'r' && str[i] != 't' && str[i] != 'g' && str[i] != 'a' && str[i] != 'A' && str[i] != 'L' && str[i] != 'D')
    {
      my_putstr_error("my_ls: invalid option -- '");
      my_putchar_error(str[i]);
      my_putstr_error("'\n");
      return (1);
    }
    i = i + 1;
  }
  return (0);
}

// Recuperer les options
int	get_option(char *str, t_options **options)
{
  (search_options(str, 'l') == 1) ? ((*options)->l = 1) : (0);
  (search_options(str, 'L') == 1) ? ((*options)->L = 1) : (0);
  (search_options(str, 'R') == 1) ? ((*options)->R = 1) : (0);
  (search_options(str, 'd') == 1) ? ((*options)->d = 1) : (0);
  (search_options(str, 'r') == 1) ? ((*options)->r = 1) : (0);
  (search_options(str, 't') == 1) ? ((*options)->t = 1) : (0);
  (search_options(str, 'g') == 1) ? ((*options)->l = 1) : (0); // Option bonus -g 
  (search_options(str, 'a') == 1) ? ((*options)->R = 1) : (0);
  (search_options(str, 'A') == 1) ? ((*options)->A = 1) : (0);
  if (search_bad_options(str) == 1)
    return (-1);
  return (0);
}
