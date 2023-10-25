/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:38:07 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/25 17:29:29 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	{
		i++;
	}
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL); //null_check here
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
	{
		return (NULL);
	}
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(str), NULL);
	readed = 1;
	while (!ft_strchr(str, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[readed] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (free(buff), NULL);
	}
	free(buff);
	return (str);
}
char	*get_next_line(int fd)
{
	char *line;
	static char *str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	// if (str == NULL)
	// 	str = "";
	//	str = ft_calloc(BUFFER_SIZE, sizeof(char *));
	str = ft_read_line(fd, str);
	if (!str)
		return (0);
	line = ft_get_jumpline(str);
//	if (!line)
//		return (NULL);
	str = ft_print_jumpline(str);
	return (line);
}

/* void	runleaks(void)
{
	system("leaks a.out");
}

int	main()
{
	int	fd;
	char *line;
	int i;

	fd = open("only_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while (i < 20)
	{
		line = get_next_line(fd);
		if (!line)
	{
			printf("\nError obteniendo nueva linea...\n");
			close(fd);
			return(1);
		}
		printf(" line [%02d] : %s", i, line);
		i++;
		free(line);
	}	
	close(fd);
	// atexit(runleaks);
	return (0);
} */
