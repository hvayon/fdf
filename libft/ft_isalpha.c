/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:29:40 by hvayon            #+#    #+#             */
/*   Updated: 2021/10/25 21:47:37 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

static int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
