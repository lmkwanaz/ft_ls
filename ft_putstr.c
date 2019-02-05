/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:45:06 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/11 15:45:54 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putstr(char const *str)
{
	int		l;

	if (str)
	{
		l = 0;
		while (str[l] != '\0')
		{
			ft_putchar(str[l]);
			l++;
		}
	}
}
