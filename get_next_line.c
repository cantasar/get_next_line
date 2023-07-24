/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:58:19 by ctasar            #+#    #+#             */
/*   Updated: 2023/07/23 16:29:29 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_all(int fd, char *all_line)
{
	char *buff;
	int count_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	count_bytes = 1;
	while (!check_nl(all_line) && count_bytes != 0)
	{
		count_bytes = read(fd, buff, BUFFER_SIZE);
		if (count_bytes == -1)
		{
			free(buff);
			free(all_line);
			return(NULL);
		}
		buff[count_bytes] = '\0';
		//printf("%s", buff);
		all_line = ft_strjoin(all_line, buff);
	}
	free(buff);
	return (all_line);
}

char *get_first_line(char *all_line)
{
	char *buff;
	int i;

	if (!all_line)
		return (NULL);
	i = 0;
	while (all_line[i] && all_line[i] != '\n')
		i++;
	buff = malloc(sizeof(char) * i + 2);
	if (!buff)
		return (NULL);
	i = 0;
	while (all_line[i] != '\n' && all_line[i])
	{
		buff[i] = all_line[i];
		i++;
	}
	if (all_line[i] == '\n')
	{
		buff[i] = all_line[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char *move_all(char *all_line)
{
	char *new_all;
	int i;
	int j;

	i = 0;
	while (all_line[i] && all_line[i] != '\n')
		i++;
	if (!all_line[i])
	{
		free(all_line);
		all_line = NULL;
		return (NULL);
	}
	new_all = (char *)malloc(sizeof(char) * (ft_strlen(all_line) - i + 1));
	if (!new_all)
		return (NULL);
	i++;
	j = 0;
	while (all_line[i])
		new_all[j++] = all_line[i++];
	new_all[j] = '\0';
	free(all_line);
	return (new_all);
}

char *get_next_line(int fd)
{
	static char *all_line;
	char *line;

	if (fd < 0 || BUFFER_SIZE  <= 0)
		return (0);
	all_line = read_all(fd, all_line);
	if (!all_line || !*all_line)
	{
		if (all_line)
			free(all_line);
		all_line = NULL;
		return (NULL);
	}
	line = get_first_line(all_line);
	all_line = move_all(all_line);
	return (line);
}

// int main()
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	printf("1%s**", get_next_line(fd));
// 	printf("2%s**", get_next_line(fd));
// 	printf("3%s**", get_next_line(fd));
// 	printf("4%s**", get_next_line(fd));
// 	printf("5%s**", get_next_line(fd));
// 	printf("6%s**", get_next_line(fd));
// 	printf("7%s**", get_next_line(fd));
// 	printf("8%s**", get_next_line(fd));
// 	//system("leaks a.out");
// 	return 0;
// }
