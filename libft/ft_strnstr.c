/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:39:28 by hvayon            #+#    #+#             */
/*   Updated: 2021/10/25 22:04:44 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int			n;
	size_t		h;

	if (!(*needle))
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	h = 0;
	while (haystack[h] && h < len)
	{
		n = 0;
		if (haystack[h] == needle[n])
		{
			while (n + h < len && haystack[n + h] == needle[n])
			{
				n++;
				if (!needle[n])
					return ((char *)&haystack[h]);
			}
		}
		h++;
	}
	return (NULL);
}
