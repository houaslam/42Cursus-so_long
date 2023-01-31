/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:08:13 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/31 19:50:07 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

char	*ft_sign(long int nb, int j, char *str)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		str[i] = '-';
		i++;
	}
	if (nb >= 0)
	{
		while (j > 0)
		{
			str[i] = nb / j + 48;
			nb %= j;
			j /= 10;
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

int	ft_count(long int nb)
{
	int	count;

	count = 1;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		j;
	int		count;
	char	*p;
	int		i;

	i = 0;
	j = 1;
	count = ft_count(n);
	p = (char *)malloc(sizeof(char) * (count + 1));
	if (!p)
		return (NULL);
	if (n < 0)
		count--;
	while (count - 1 > 0)
	{
		j *= 10;
		count--;
	}
	ft_sign(n, j, p);
	return (p);
}
