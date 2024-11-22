#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int check_newline(char *str)
{
	int i;

	i = 0;
	if(!str)
		return (0);
	while(str[i])
	{
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char    *ft_strjoin(char *s1, char *s2)
{
	int     i;
	int     j;
	char    *new;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while(s1[i])
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while(s2[i])
	{
		new[j] = s2[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char    *get_line(char *str)
{
	char	*line;
	int		i;

	while(str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	i = 0;
	while(str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if(str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_line(char *str)
{
	int i;
	int j;
	char	*update_str;

	i = 0;
	j = 0;
	while(str[i] && str[i] != '\n')
		i++;
	update_str = malloc(ft_strlen(str) - i + 1);
	i += 1;
	while(str[i])
	{
		update_str[j] = str[i];
		i++;
		j++;
	}
	update_str[j] = '\0';
	return (update_str);
}