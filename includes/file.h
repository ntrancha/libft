/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:47:17 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/16 02:58:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include <sys/types.h>
# include <dirent.h> 
# include "list.h"

typedef struct          s_dir
{
    struct s_files      *files;
    char                *path;
    int                 size;
    struct s_dir        *next;
    struct s_dir        *prev;
}                       t_dir;

typedef struct          s_files
{
    struct s_file       *file;
    struct s_files      *next;
    struct s_files      *prev;
}                       t_files;

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
DIR     *ft_opendir(char *path);
int     ft_closedir(DIR *rep);
t_file  *ft_fileinfo(char *file);

#endif
