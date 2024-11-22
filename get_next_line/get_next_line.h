#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int     check_newline(char *str);
int     ft_strlen(char *str);
char    *ft_strjoin(char *s1, char *s2);
char    *get_line(char *str);
char	*update_line(char *str);

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#endif