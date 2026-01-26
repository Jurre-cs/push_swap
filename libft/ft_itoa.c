/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/21 15:39:29 by jstomps       #+#    #+#                 */
/*   Updated: 2025/10/30 18:30:22 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	nbrlen(long long n1)
{
	size_t	count;

	count = 1;
	if (n1 < 0)
	{
		n1 *= -1;
		count++;
	}
	while (n1 > 9)
	{
		n1 /= 10;
		count++;
	}
	return (count);
}

void	put(long n, char *result, int *i)
{
	if (n > 9)
	{
		put(n / 10, result, i);
		put(n % 10, result, i);
	}
	else
		result[(*i)++] = n + '0';
}

char	*ft_itoa(int n)
{
	char	*result;
	long	n1;
	int		i;

	n1 = n;
	result = malloc(sizeof(char) * (nbrlen(n1) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (n1 < 0)
	{
		result[i++] = '-';
		n1 *= -1;
	}
	put(n1, result, &i);
	result[i] = '\0';
	return (result);
}
