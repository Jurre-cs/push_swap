/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 14:54:16 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/09 19:51:52 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_arr(char **arr, int i)
{
	i--;
	while (i-- >= 0)
		free(arr[i]);
	free(arr);
}

int	strcount(int amount, const char *s, char c)
{
	int	i;

	i = 0;
	if (s[i] != c && s[i] != '\0')
		amount++;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			amount++;
		i++;
	}
	return (amount);
}

char	**strpointeri(const char *s, char **result, char c, int amount)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	start = 0;
	while (i < amount)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		result[i] = ft_substr(s, start, end - start);
		if (!result[i])
		{
			free_arr(result, i);
			return (NULL);
		}
		start = end;
		i++;
	}
	result[amount] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		amount;

	amount = 0;
	amount = strcount(amount, s, c);
	result = malloc((amount + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = strpointeri(s, result, c, amount);
	return (result);
}

// int main(void)
// {
//     char **result;// = ft_split("Tripouille", ' ');
//     int i;
//     i = 0;

//     char * splitme = strdup("Tripouille");
//     //printf("%s\n", splitme);
//     result = ft_split(splitme, ' ');
//     while (result[i] != NULL)
//     {
//         printf("%s\n", result[i]);
//         i++;
//     }
//     printf("%s", result[i]);
//     return (0);
// }
