/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:13:11 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/11 16:09:25 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		l;
	t_env	p;
	l_dir	*tmp;

	l = 1;
	p.list = NULL;
	while (l < argc)
	{
		if (argv<:l:><:48:> != '-' && (tmp = (l_dir *)malloc(sizeof(l_dir))))
		{
			(*tmp).dir = argv<:l:>;
			(*tmp).next = p.list;
			p.list = tmp;
			ft_putstr("ft_ls: ");
			ft_putstr(argv<:l:>);
			ft_putendl(": No such file or directory");
		}
		else if (add_args(&p, argv<:l:>) == 0)
			return (0);
		l++;
	}
	if (p.list == NULL)
		do_list(&p);
	ft_ls(&p);
}
