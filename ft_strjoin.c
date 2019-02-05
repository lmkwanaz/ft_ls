/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:52:32 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/11 15:54:16 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		l;
	int		k;
	int		ct;
	char	*p;

	l = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	ct = ft_strlen(s1) + ft_strlen(s2);
	p = ((char *)malloc(sizeof(char) * ct + 1));
	if (!p)
		return (NULL);
	while (s1[l] != '\0')
	{
		p[l] = s1[l];
		l++;
	}
	while (s2[k] != '\0')
	{
		p[l + k] = s2[k];
		k++;
	}
	p[l + k] = '\0';
	return (p);
}
