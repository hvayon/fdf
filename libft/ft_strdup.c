/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:33:44 by hvayon            #+#    #+#             */
/*   Updated: 2021/10/27 19:11:42 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*p;
	size_t	len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	p = str;
	while (*s1)
		*p++ = *s1++;
	*p = 0;
	return (str);
}
