/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:38:07 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/26 18:04:49 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = malloc((ft_strlen((char *)str) + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (str[i] != '\0')
	{	
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_print_jumpline(char *temp)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!dest)
	{
		return (free(temp), NULL);
	}
	j = 0;
	while (temp[i])
		dest[j++] = temp[++i];
	dest[j] = '\0';
	free(temp);
	return (dest);
}

char	*ft_get_jumpline(char *buf)
{
	int		i;
	char	*dest;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

char	*ft_read_line(int fd, char *str)
{
	char	*buff;
	int		readed;

	if (!str)
		str = ft_calloc(1, 1);
	if (!str)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(str), NULL);
	readed = 1;
	while (!ft_strchr(str, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
			return (free(buff), free(str), NULL);
		buff[readed] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (free(buff), NULL);
	}
	return (free(buff), str);
}

char	*get_next_line(int fd)
{
	static char	*str[1023];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_read_line(fd, str[fd]);
	if (!str[fd])
		return (0);
	line = ft_get_jumpline(str[fd]);
	if (!line)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = ft_print_jumpline(str[fd]);
	return (line);
}

/*
int	main()
{
	int	fd1;
	int fd2;
	char *line;
	int i;
	int j;

	fd1 = open("./tests/lore.txt", O_RDONLY);
	fd2 = open("./tests/read_error.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf(" line [%02d] : %s", i++, line);
	line = get_next_line(fd2);
	printf(" line [%02d] : %s", j++, line);
	line = get_next_line(fd1);
	printf(" line [%02d] : %s", i++, line);
	line = get_next_line(fd2);
	printf(" line [%02d] : %s", j++, line);
	line = get_next_line(fd1);
	printf(" line [%02d] : %s", i++, line);
	line = get_next_line(fd2);
	printf(" line [%02d] : %s", j++, line);
	line = get_next_line(fd1);
	printf(" line [%02d] : %s", i++, line);
	line = get_next_line(fd2);
	printf(" line [%02d] : %s", j++, line);
	line = get_next_line(fd1);
	printf(" line [%02d] : %s", i++, line);
	line = get_next_line(fd2);
	printf(" line [%02d] : %s", j++, line);
	free(line);
	close(fd1);
	close(fd2);
	return (0);
}*/
