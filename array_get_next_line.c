/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:38:07 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/23 20:35:55 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 100

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&s[i]);
	return (0);
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
	dest = malloc(sizeof(*dest) * ft_strlen(temp) - i + 1);
	if (!dest)
		return (NULL);
	j = 0;
	while (temp[i])
		dest[j++] = temp [++i];
	dest[i] = '\0';
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
	while (buf && buf[i] != '\n')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_read_line(int fd, char *str)
{
	char	*buff;
	int	readed;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	readed = 1;
	while (!ft_strchr(str, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readed] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char *line;
	static char *str;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	str = ft_read_line(fd, str);
	if (!str)
		return (0);
	line = ft_get_jumpline(str);
	str = ft_print_jumpline(str);
	return (line);
}

#include <stdio.h>
int	main()
{
	int	fd;
	char *line;
	int i;

	fd = open("lore.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}

	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("Error obteniendo nueva linea...\n");
			close(fd);
			return(1);
		}
		printf("line [%02d] : %s", i, line);
		free(line);
	}
	close(fd);
	return (0);
}
