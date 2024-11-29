#include "get_next_line.h"

static char	*read_file(int fd, char *str)
{
	int		rd;
	char	*buff;

	rd = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buff)
		return(NULL);
	while(!newline(str) && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if(rd == -1)
		{
			free(str);
			free(buff);
			return(NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

static char	*get_line(char *str)
{
	char	*line;
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while(str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if(!line)
		return (NULL);
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
	return(line);
}

static char *update_line(char *str)
{
	char *next_line;
	int i;
	int j;

	i = 0;
	j = 0;
	while(str[i] && str[i] != '\n')
		i++;
	if(!str[i])
	{
		free(str);
		return(NULL);
	}
	next_line = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if(!next_line)
		return(NULL);
	i++;
	while(str[i])
	{
		next_line[j] = str[i];
		i++;
		j++;
	}
	next_line[j] = '\0';
	free(str);
	return(next_line);
}

char    *get_next_line(int fd)
{
	static char *str;
	char		*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	str = read_file(fd, str);
	if(!str)
		return (NULL);
	line = get_line(str);
	str = update_line(str);
	
	return(line);
}
