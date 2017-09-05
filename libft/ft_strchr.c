/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:42:26 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/07/22 10:20:41 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *haystack, int c)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	len = ft_strlen(haystack) + 1;
	while (len)
	{
		if (haystack[i] == (char)c)
		{
			temp = (char *)(haystack + i);
			return ((char *)temp);
		}
		len--;
		i++;
	}
	return (NULL);
}
