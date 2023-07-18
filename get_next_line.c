/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:55:00 by ctasar            #+#    #+#             */
/*   Updated: 2023/07/17 20:57:29 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	add_line()
{
	
}

void	read_all(char *line, int fd) // \n bulana kadar buffer_size kadar read
{
	char *buff;
	int	count_bytes;

	while (!check_end_line(line))
	{
		buff = (char *)malloc(sizeof(char *) * BUFFER_SIZE);
		if (!buff)
			return ;
		count_bytes = read(fd, buff, BUFFER_SIZE);
		if (count_bytes == 0)
		{
			free(buff);
			return ;
		}
		buff[count_bytes] = 0;
		printf("-%d-\n", count_bytes);
		printf("--%s--\n", buff);
	}
		printf("-string:-%s--\n", buff);
}

char	*get_next_line(int fd)
{
	static char	*line;
	read_all(line, fd);
	return (line);
}

int	main(int argc, char const *argv[])
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
