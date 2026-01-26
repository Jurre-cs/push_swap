/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 10:30:35 by jstomps       #+#    #+#                 */
/*   Updated: 2025/10/16 14:53:38 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*x;

	x = s;
	while (n > 0)
	{
		*x = (unsigned char)c;
		x++;
		n--;
	}
	return (s);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char s[200] = ";ja;fkjzbvlbiawe";
// 	ft_memset(s + 5, '0', 5*sizeof(char));
// 	printf("%s", s);
// }
