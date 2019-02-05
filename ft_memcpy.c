/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:51:39 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/11 14:52:53 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_memcpy(void *dst, const void *src, size_t l)
{
	unsigned char	*p;
	unsigned char	*i;

	p = dst;
	i = (unsigned char*)src;
	while (l--)
	{
		*p++ = *i++;
	}
	return (dst);
}
