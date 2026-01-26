/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 15:59:54 by jstomps       #+#    #+#                 */
/*   Updated: 2025/10/28 13:57:07 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1tmp;
	unsigned char	*s2tmp;

	s1tmp = (unsigned char *)s1;
	s2tmp = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1tmp[i] != s2tmp[i])
			return (s1tmp[i] - s2tmp[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int i = 2;
// 	char c[40] = "jafb;";
// 	char s[40] = "jafb;kah";
// 	i = ft_memcmp(s, c, i);
// 	printf("%d", i);
// }