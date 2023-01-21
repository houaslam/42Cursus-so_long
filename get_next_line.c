/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:43:45 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/21 17:35:14 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_handle(char *buf)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(buf) - i));
	if (!str)
		return (NULL);
	i++;
	while (buf[i])
		str[j++] = buf[i++];
	str[j] = '\0';
	free (buf);
	return (str);
}

char	*after(char *buf)
{
	int		i;
	char	*str;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_check(char *buf, int fd)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!res)
		return (NULL);
	i = 1;
	while (!ft_strchr(buf, '\n') && i != 0)
	{
		i = read(fd, res, BUFFER_SIZE);
		if (i == -1)
		{
			free(res);
			free(buf);
			return (NULL);
		}
		res[i] = '\0';
		buf = ft_strjoin(buf, res);
	}
	free (res);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_check(buf, fd);
	if (!buf)
		return (NULL);
	line = after(buf);
	buf = ft_handle(buf);
	return (line);
}

int	ft_strnstr(char *big, char *small)
{
	size_t	j;
	size_t	i;
	size_t	len;
	int		len1;

	j = 0;
	i = 0;
	len = ft_strlen(big) - 1;
	len1 = ft_strlen(small) - 1;
	while (big[len - j] && j <= ft_strlen(small))
	{
		while (big[len - j] == small[len1 - i] \
		&& small[len1 - i] && big[len - j])
		{
			i++;
			j++;
			if (len1 - i == 0)
				return (1);
		}
		j++;
	}
	return (0);
}
