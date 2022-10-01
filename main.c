#include <stdlib.h>
#include "rush.h"
#include <stdio.h>
int	main(int ac, char **av)
{
	(void) ac;
	char *file;
	char *anum;

	file = ft_open("numbers.dict");
	anum = ft_slice_forw(file, " ");
	free(file);
	printf("%s", anum);
	free(anum);
	return (0);
}
