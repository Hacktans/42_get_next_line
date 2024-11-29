#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int     newline(char *str);
int     ft_strlen(char *str);
char    *ft_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 31
#endif

#endif