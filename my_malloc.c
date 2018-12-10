/*
** my_malloc.c for my_ls in /home/chapui_s/travaux/my_ls
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Nov 25 21:32:02 2013 chapui_s
** Last update Sat Nov 30 17:05:30 2013 chapui_s
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
