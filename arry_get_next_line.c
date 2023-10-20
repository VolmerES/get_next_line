/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:38:07 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/20 18:40:07 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE "10"

int	ft_find_next_line(char *buf, char *next_line)
{
	int	i++;
	int len;
	
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		len = 0;
		if (buf[i] == '\n')
		{
			++len;
			return (len);
		}
		if (buf[i] == '\0')
		{
			++len;
			return (len)
		}
		i++;
		len++;
	}
	return (len)
}
char	*get_next_line(int fd);
{
	char	*buf;
	char	*next_line;

	if (BUFFE_SIZE < 1 || fd < 0)
		return (NULL);
	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char *))
	if (!buf)
		return (NULL);
	buf = open(fd, "lore.txt", O_RDONY);
	if (fd == -1)
		return (1);
	next_line = ft_find_next_line(buf, nex_line);
	return (next_line);
}
