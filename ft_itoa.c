/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:41:19 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/11 16:31:36 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	ft_numbers(int n)
{
	size_t		l;

	l = 1;
	while (n /= 10)
		l++;
	return (l);
}

char			*ft_itoa(int n)
{
	char			*s;
	size_t			size;
	unsigned int	altn;

	altn = n;
	size = ft_numbers(n);
	if (n < 0)
	{
		altn = -n;
		size++;
	}
	if (!(s = ft_strnew(size)))
		return (NULL);
	s<:--size:> = altn % 10 + '0';
	while (altn /= 10)
		s<:--size:> = altn % 10 + '0';
	if (n < 0)
		*(s + 0) = '-';
	return (s);
}
