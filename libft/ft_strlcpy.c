/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 17:01:24 by jstomps       #+#    #+#                 */
/*   Updated: 2025/10/27 18:45:55 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (i + 1 < size)
		ft_memcpy(dst, src, i + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = 0;
	}
	return (i);
}

// #include <stdio.h>

// int main(void)
// {
// 	int a;
// 	int b;
// 	int i = 6;
// 	char c[40] = "jafb;kah";
// 	char s[40] = ";knsa;fknsADA";
// 	a = ft_strlcpy(s, c, i);
// 	printf("%s : %d\n", s, a);
// 	b = strlcpy(s, c, i);
// 	printf("%s : %d\n", s, b);
// }
