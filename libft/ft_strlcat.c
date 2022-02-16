/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:52:12 by hvayon            #+#    #+#             */
/*   Updated: 2021/10/22 23:26:05 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *scr, size_t dstsize)
{
	size_t	scr_len;
	size_t	dst_len;
	size_t	res;

	scr_len = 0;
	dst_len = 0;
	res = 0;
	while (dst[dst_len])
	{
		dst_len++;
	}
	while (scr[res])
	{
		res++;
	}
	if (dstsize <= dst_len)
		res += dstsize;
	else
		res += dst_len;
	while (dstsize > dst_len + 1 && scr[scr_len])
		dst[dst_len++] = scr[scr_len++];
	dst[dst_len] = '\0';
	return (res);
}
