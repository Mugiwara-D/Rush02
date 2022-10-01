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

char	*ft_slice_forw(char *str, char *sep)
{
	int i;
	char *ret;
	int	n;


	i = ft_len_tosep(str, sep);
	while (str[i] && is_sep(str[i], sep))
		i++;
	ret = (char *) malloc(i * sizeof(char));
	n = 0;
	while (str[i])
	{
		ret[n] = str[i];
		n++;
		i++;
	}
	return (ret);
}
#include <stdio.h>
int	main(int ac, char **av)
{
	(void) ac;
	char *str;

	str = ft_slice_forw(av[1],av[2]);
	printf("%s\n", str);
	free(str);
	return (0);
}
