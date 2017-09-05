/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmtimkul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 09:44:14 by nmtimkul          #+#    #+#             */
/*   Updated: 2017/08/10 12:33:02 by nmtimkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 64
# define L_LEN 50
# define NUM_FILES 10
# define MAX_BUFF 800000

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

int					get_next_line(const int fd, char **line);

typedef struct		s_buff
{
	char			buff[BUFF_SIZE];
	int				buf_pos;
	int				buf_fd;
	int				eof;
}					t_buff;

#endif
