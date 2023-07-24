/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:24:24 by ctasar            #+#    #+#             */
/*   Updated: 2023/07/23 16:14:45 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int check_nl(char *all_line)
{
	int i;

	i = 0;
	if (!all_line)
		return (0);
	while (all_line[i])
	{
		if (all_line[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *new_str;
	int i;
	int j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		*s1 = '\0';
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}
