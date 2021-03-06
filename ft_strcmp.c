/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:46:54 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/11 15:51:28 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		l;

	l = 0;
	while (s1[l] != '\0' && s1[l] == s2[l])
	{
		s1++;
		s2++;
	}
	return ((unsigned char)s1[l] - (unsigned char)s2[l]);
}
