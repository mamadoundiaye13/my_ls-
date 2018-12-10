#include <stdlib.h>

void	*my_malloc(size_t size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    my_putstr_error("Could not alloc\n");
  return (ptr);
}
