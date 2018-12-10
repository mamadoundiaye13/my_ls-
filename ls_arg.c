#include "my_ls.h"

int		recurs_ls(t_options *options, char *dir_name,
			  t_list_file *list_files_dir)
{
  char		*name_without_path;
  t_list_file	*tmp;

  tmp = list_files_dir;
  while (tmp)
  {
    name_without_path = cut_name(tmp->name);
    if (name_without_path[0] != '.')
      if ((ls_directory(options, tmp->name, 2, 5)) == -2)
        return (-1);
    tmp = tmp->next;
  }
  return (0);
}

int		is_good_dir_in_arg(t_list_file *list_file)
{
  t_list_file	*tmp;
  struct stat	res_stat;
  int		nb_good_dir;

  tmp = list_file;
  nb_good_dir = 0;
  while (tmp)
  {
    if (lstat(tmp->name, &res_stat) != -1 && (S_ISDIR(res_stat.st_mode)))
      nb_good_dir = nb_good_dir + 1;
    tmp = tmp->next;
  }
  return (nb_good_dir);
}

int		nb_arg(t_list_file *list_file)
{
  t_list_file	*tmp;
  int		nb_arg;

  tmp = list_file;
  nb_arg = 0;
  while (tmp)
  {
    nb_arg = nb_arg + 1;
    tmp = tmp->next;
  }
  return (nb_arg);
}
