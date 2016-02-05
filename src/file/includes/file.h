/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:47:17 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/03 12:44:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include <sys/types.h>
# include <dirent.h> 
# include "list.h"

typedef t_list          t_dos;
typedef t_list          t_fdos;

typedef struct          s_file
{
    char                *name;
    int                 mode;
    int                 uid;
    int                 gid;
    int                 size;
}                       t_file;

int 	ft_gnl(int const fd, char **line);
int 	ft_gnl_list(int const fd, char **line);
int     ft_readstdin(char **str);
int 	ft_readfile(int const fd, char **str);
int 	ft_readfile_list(int const fd, t_list *list);
int	    ft_catfile(const int fd);
char    *ft_get_file(const char *pathname);
int     ft_write_file(const char *pathname, char *content);
int     ft_write_file_end(const char *pathname, char *content);
DIR     *ft_opendir(char *path, char *error);
int     ft_closedir(DIR *rep);
t_file  *ft_fileinfo(char *file);
int     ft_fileget_rights(t_file *file);
int     ft_filedel(char *file);
int     ft_filecopy(char *file_src, char *path_dst);
int     ft_filemove(char *file_src, char *path_dst);
int     ft_filefind(char *file, char *search);
int     ft_filestrrpl(char *file, char *src, char *mod);
t_fdos  *ft_getdir(char *path, char *error);
int     ft_getdirdeep(char *path, char *error);
char    **ft_getdirtab(char *path, char *error);
char    **ft_getdirtab_f(char *path, char *error, char type);
t_fdos  *ft_getdir_rec(char *path, char *error);
int     ft_fileindos(char *path, char *error, char *file);
int     ft_fileindos_rec(char *path, char *error, char *file);
void    ft_fdos_displaycol(t_fdos *list, int col);
void    ft_fdos_del(t_fdos *list);
void    ft_dos_del(t_dos *list);
char    ft_filetype(t_file *file);
char    *ft_dinpath(char *pathfile);
char    *ft_finpath(char *pathfile);
int		ft_pathisdir(char *path);
int		ft_pathisfile(char *path);
int		ft_pathexist(char *path);
void    ft_deldir(t_list *list);
int     ft_catfile_list(const int fd);
int     ft_dircreate(const char *path);

#endif
