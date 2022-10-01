/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:09:06 by aloubier          #+#    #+#             */
/*   Updated: 2022/09/29 15:01:17 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_issep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i] || c == '\0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_cycle_str(char *str, char *charset)
{
	int	i;
	int	str_count;

	i = 0;
	str_count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_issep(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
			str_count++;
		while (str[i] && ft_issep(str[i], charset) == 0)
			i++;
	}
	return (str_count);
}

int	ft_strlen(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !ft_issep(str[i], sep))
		i++;
	return (i);
}

char	*ft_string_extract(char *src, char *sep)
{
	int		i;
	char	*dest;
	int		length;

	i = 0;
	length = ft_strlen(src, sep);
	if (length == 0)
		return (0);
	dest = malloc(sizeof (char) * (ft_strlen(src, sep) + 1));
	if (!dest)
		return (0);
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		string_count;
	char	**split_string;

	i = 0;
	string_count = ft_cycle_str(str, charset);
	split_string = malloc(sizeof (str) * (string_count + 1));
	if (!split_string)
		return (0);
	while (*str != '\0')
	{
		while (*str != '\0' && ft_issep(*str, charset) == 1)
			str++;
		if (*str != '\0' && ft_issep(*str, charset) == 0)
		{
			split_string[i] = ft_string_extract(str, charset);
			if (i < string_count)
				i++;
		}
		while (*str != '\0' && ft_issep(*str, charset) == 0)
			str++;
	}
	split_string[i] = 0;
	return (split_string);
}

/*
int	main(void)
{
	char test[] = " Salut-comment-ca+va?";
	char sep[] = " ";
	char **dest;
	int i;

	i = 0;
	dest = ft_split(test, sep);
	while (dest[i] != '\0')
	{
		printf("%s\n", dest[i]);
		i++;
	}
	free(dest);
	return (0);
}
*/
