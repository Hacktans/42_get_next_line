#include "get_next_line.h"

char	*read_file(int fd, char *str)
{
	char	*buff;
	int		rd;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buff)
		return (NULL);
	rd = 1;
	while(!check_newline(str) && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if(rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char    *get_next_line(int fd)
{
	char		*line;
	static	char *str;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_file(fd, str);
	if(!str)
		return(NULL);
	line = get_line(str);
	str = update_line(str);
	return (line);
}

