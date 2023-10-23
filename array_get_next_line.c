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
#define BUFFER_SIZE 10

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
	while (temp && temp[i] && temp[i] != '\n')
		i++;
	dest = malloc(sizeof(*dest) * ft_strlen(temp) - i + 1);
	if (!dest)
		return (NULL);
	j = 0;
	while (temp && temp[i])
		dest[j++] = temp [++i];
	dest[i] = '\0';
	return (dest);

}
char	*ft_get_jumpline(char *buf, int ret)
{
	int		i;
	char	*dest;

	i = 0;
	while (buf && buf[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	if (ft_strchr(buf, '\n') != '\0')
		ret = 1;
	while (buf && buf[i] && buf[i] != '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char	*get_next_line(int fd)
{
	char		*buf;
	int			ret;
	static char	*str;
	char		*temp;
	char		*line;

	if (fd < 0 || fd > 1023 || buf <= 0)
		ret = -1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			ret = -1;
		buf[ret] = '\0';
		temp = str;
		str = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(str, '\n'))
			break;
	}
	if (ret >= 0)
	{
		line = ft_get_jumpline(str, ret);
		temp = str;
		str = ft_print_jumpline(temp);
		free (temp);
	}
	free (buf);
	return (buf);

}

#include <stdio.h>
int	main()
{
	int	fd;
	char *line;

	fd = open("lore.txt", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
