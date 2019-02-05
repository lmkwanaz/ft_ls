/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:04:38 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/11 16:50:25 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/dir.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <unistd.h>

typedef struct		s_dir
{
	int				a;
	char			*dir;
	char			*path;
	time_t			time;
	int				is_dir;
	struct s_dir	*next;
}					l_dir;

typedef struct		s_env
{
	int				l;
	int				a;
	int				r;
	int				t;
	int				rr;
	char			*path;
	DIR				*dirp;
	struct dirent	*dp;
	struct stat		sb;
	l_dir			*list;
}					t_env;

void				ft_permission(l_dir *tmp, struct stat fstat);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				sort_list(l_dir **head, int (*cmp)(l_dir, l_dir), int done);
char				*get_user(struct stat fstat);
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
void				get_time(struct stat fstat, l_dir *tmp);
void				*ft_memcpy(void *dst, const void *src, size_t l);
void				do_list(t_env *p);
void				ft_putendl(char const *s);
void				ft_ls(t_env *p);
void				do_ls(char *dir, t_env *p);
void				print_l(l_dir *list);
int					ft_strcmp(const char *s1, const char *s2);
int					compare_strings(l_dir d1, l_dir d2);
void				ft_rev_list(l_dir **head_ref);
void				ft_putnbr(int n);
char				*ft_itoa(int n);
int					compare_time(l_dir d1, l_dir d2);
void				big_r(l_dir *list, t_env *p);
char				*ft_strnew(size_t size);
int					add_args(t_env *e, char *arg);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				print_l(l_dir *list);
int					main(int argc, char **argv);
#endif
