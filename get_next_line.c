/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:58:48 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/10/01 11:16:43 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int		get_content(const int fd, char **line)
{
	char	*buff;
	char	*temp;
	int		data;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	data = read(fd, buff, BUFF_SIZE);
	if (data > 0)
	{
		buff[data] = '\0';
		temp = ft_strjoin(*line, buff);
		free(*line);
		*line = temp;
	}
	free(buff);
	return (data);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*stack = NULL;
	char			*buff;
	int				ret;

	if ((!stack && (stack = (char *)malloc(sizeof(*stack))) == NULL) ||
			!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	buff = ft_strchr(stack, '\n');
	while (buff == NULL)
	{
		ret = get_content(fd, &stack);
		if (ret == 0)
		{
			if (ft_strlen(stack) == 0)
				return (0);
			stack = ft_strjoin(stack, "\n");
		}
		if (ret < 0)
			return (-1);
		else
			buff = ft_strchr(stack, '\n');
	}
	*line = ft_strsub(stack, 0, ft_strlen(stack) - ft_strlen(buff));
	stack = ft_strdup(buff + 1);
	return (1);
}
