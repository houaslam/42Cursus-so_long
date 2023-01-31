/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:34:29 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/31 19:50:57 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h" 

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
		i = 0;
		while (big[len - j] == small[len1 - i] \
		&& small[len1 - i] && big[len - j])
		{
			i++;
			j++;
			if (len1 - i == 0 && big[len - j] == small[len1 - i])
				return (1);
		}
		j++;
	}
	return (0);
}

void	ft_putstr_fd(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	exit(1);
}

void	ft_free(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
}
