#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 31
# endif

# include <stdlib.h>
# include <unistd.h>

# include <fcntl.h>
# include <stdio.h>

char *get_next_line(int fd);
char *read_all(int fd, char *all_line);

int ft_strlen(char *s);
int check_nl(char *all_line);
char *ft_strjoin(char *s1, char *s2);

#endif