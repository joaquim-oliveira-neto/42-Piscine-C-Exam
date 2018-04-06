#include <unistd.h>

int		main(int argc, char **argv)
{

	int a;
	int i;

	i = 0;
	a = argc - 1;
	if (argc > 1)
	{
		while (argv[a][i])
		{
			write(1, &argv[a][i], 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
