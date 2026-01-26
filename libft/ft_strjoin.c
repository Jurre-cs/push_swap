/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/16 19:19:21 by jstomps       #+#    #+#                 */
/*   Updated: 2025/10/17 16:25:08 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*joined;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	joined = malloc((len1 + (len2 + 1)) * sizeof(char));
	if (!joined)
		return (NULL);
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		joined[len1 + i] = s2[i];
		i++;
	}
	joined[len1 + i] = '\0';
	return (joined);
}
