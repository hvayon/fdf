/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:08:29 by hvayon            #+#    #+#             */
/*   Updated: 2021/10/26 22:20:40 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*st;

	st = (char *)s;
	while (*s)
		s++;
	while (s >= st)
	{
		if ((unsigned char)*s-- == (unsigned char)c)
			return ((char *)s + 1);
	}
	return (NULL);
}
