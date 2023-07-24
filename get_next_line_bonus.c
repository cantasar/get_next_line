/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:40:58 by ctasar            #+#    #+#             */
/*   Updated: 2023/07/24 14:08:32 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_all(int fd, char *all)
{
	char	*buff;
	int		count_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	count_bytes = 1;
	while (!check_nl(all) && count_bytes != 0)
	{
		count_bytes = read(fd, buff, BUFFER_SIZE);
		if (count_bytes == -1)
		{
			free(buff);
			free(all);
			return (NULL);
		}
		buff[count_bytes] = '\0';
		all = ft_strjoin(all, buff);
	}
	free(buff);
	return (all);
}

char	*get_first_line(char *all)
{
	char	*line;
	int		i;

	if (!all)
		return (NULL);
	i = 0;
	while (all[i] && all[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (all[i] && all[i] != '\n')
	{
		line[i] = all[i];
		i++;
	}
	if (all[i] == '\n')
	{
		line[i] = all[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*move_all(char *all)
{
	char	*new_all;
	int		i;
	int		j;

	i = 0;
	while (all[i] && all[i] != '\n')
		i++;
	if (!all[i])
	{
		free(all);
		all = NULL;
		return (NULL);
	}
	new_all = (char *)malloc(sizeof(char) * (ft_strlen(all) - i + 1));
	if (!new_all)
		return (NULL);
	i++;
	j = 0;
	while (all[i])
		new_all[j++] = all[i++];
	new_all[j] = '\0';
	free(all);
	return (new_all);
}

char	*get_next_line(int fd)
{
	static char	*all[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all[fd] = read_all(fd, all[fd]);
	if (!all[fd] || !*all[fd])
	{
		if (all[fd])
			free(all[fd]);
		all[fd] = NULL;
		return (NULL);
	}
	line = get_first_line(all[fd]);
	all[fd] = move_all(all[fd]);
	return (line);
}
