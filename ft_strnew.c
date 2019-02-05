/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:56:46 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/11 16:04:53 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	l;

	l = 0;
	if (!(tmp = malloc(sizeof(*tmp) * (size + 1))))
		return (NULL);
	while (l <= size)
	{
		tmp<:l:> = '\0';
		l++;
	}
	return (tmp);
}
