/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:42:01 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/07/22 10:08:36 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	char	*temp2;
	int		i;

	temp = (char *)dest;
	temp2 = (char *)src;
	if (temp > temp2)
	{
		i = n - 1;
		while (i >= 0)
		{
			temp[i] = temp2[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return ((void *)dest);
}
