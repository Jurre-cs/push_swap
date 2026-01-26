/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 17:49:22 by jstomps       #+#    #+#                 */
/*   Updated: 2025/10/16 18:55:08 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0')
		j++;
	if (size == 0 || size <= i)
		return (j + size);
	while (src[k] != '\0' && (i + k) < (size - 1))
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (i + j);
}

// #include <stdio.h>

// int main(void)
// {
// 	int a;
// 	int b;
// 	int i = 0;
// 	char s[40] = "12345";
// 	char d[40] = "123";
// 	a = ft_strlcat(d, s, i);
// 	printf("%s : %d\n",s , a);
// 	b = strlcat(d, s, i);
// 	printf("%s : %d\n", s, b);
// }
