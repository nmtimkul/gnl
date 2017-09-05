/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 09:44:00 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/08/10 12:32:44 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static t_buff	read_buffer(const int fd, t_buff b)
{
	long int			k;

	b.buf_pos = 0;
	k = -1;
	b.buf_fd = fd;
	b.eof = read(fd, b.buff, BUFF_SIZE);
	if (b.eof < BUFF_SIZE && b.eof > 0)
	{
		k = b.eof - 1;
		while (k++ <= BUFF_SIZE)
			b.buff[k] = '\0';
	}
	return (b);
}

static char		*re_malloc(char *line, size_t size)
{
	char			*tmp;

	tmp = ft_strnew(size + L_LEN);
	if (size > 0)
	{
		tmp = ft_strcpy(tmp, line);
		free(line);
	}
	return (tmp);
}

static t_buff	get_line(const int fd, char **line, t_buff b)
{
	unsigned int	line_pos;
	char			*l;

	line_pos = 0;
	if (fd != b.buf_fd || b.buf_pos >= BUFF_SIZE || b.eof < 0)
		b = read_buffer(fd, b);
	while (b.buff[b.buf_pos] != '\n' && b.buf_pos < b.eof && b.eof > -1)
	{
		if (((line_pos + 1) % L_LEN == 0) || line_pos == 0)
			l = re_malloc(l, line_pos);
		l[line_pos] = b.buff[b.buf_pos];
		line_pos++;
		b.buf_pos++;
		if (b.buf_pos >= BUFF_SIZE)
			b = read_buffer(fd, b);
	}
	if ((b.eof < BUFF_SIZE && b.eof != -1) && (b.eof <= b.buf_pos))
		b.eof = -2;
	b.buf_pos++;
	if (line_pos == 0)
		*line = 0;
	else
		*line = l;
	return (b);
}

static int		get_buff(const int fd, char **line)
{
	static t_buff	arr[NUM_FILES];
	long int		k;

	k = 0;
  	while (k < NUM_FILES && fd != arr[k].buf_fd)
		k++;
	if (k == NUM_FILES)
		k--;
	if (arr[k].buf_fd == fd)
		arr[k] = get_line(fd, line, arr[k]);
	else
	{
		while (k >= 0 && arr[k].buf_fd != 0 && arr[k].eof > -1)
			k--;
		if (k >= 0)
			arr[k] = get_line(fd, line, arr[k]);
		else
			arr[k] = get_line(fd, line, arr[NUM_FILES - 1]);
	}
	return (arr[k].eof);
}

int				get_next_line(const int fd, char **line)
{
	long int	eof;

	if (BUFF_SIZE > MAX_BUFF || BUFF_SIZE < 1)
		return (-1);
	eof = get_buff(fd, line);
	if (eof == -1)
		return (-1);
	if (eof == -2)
		return (0);
	return (1);
}
