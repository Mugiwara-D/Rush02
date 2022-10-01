#include <stdlib.h>

int	is_sep(char cstr, char *sep)
{
	while (*sep)
	{
		if (cstr == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int	ft_len_tosep(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !(is_sep(str[i], sep)))
		i++;

	return (i);
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_slice_forw(char *str, char *sep)
{
	int i;
	char *ret;
	int	n;


	i = ft_len_tosep(str, sep);
	while (str[i] && is_sep(str[i], sep))
		i++;
	n = len(str + i);
	ret = (char *) malloc(n * sizeof(char));
	n = 0;
	while (str[i])
	{
		ret[n] = str[i];
		n++;
		i++;
	}
	return (ret);
}
