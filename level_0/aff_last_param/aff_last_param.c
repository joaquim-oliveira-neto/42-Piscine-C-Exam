#include <unistd.h>

int		main(int argc, char **argv)
{
	int		a;
	int		i;

	a = argc - 1;
	i = 0;
	if (argc < 2)
		write(1, "\n", 1);
	else
	{
		while (argv[a][i])
		{
			write(1, &argv[a][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
