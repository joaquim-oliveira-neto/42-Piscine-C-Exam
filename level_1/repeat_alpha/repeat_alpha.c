#include <unistd.h>

int		main(int ac, char **av)
{
	int		i;
	int		c;

	if (ac !=2)
		write(1, "\n", 1);
	else
	{	
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= 65 && av[1][i] <= 90)
			{
				c = av[1][i] - 65 + 1;
				while (c > 0)
				{
					write(1, &av[1][i], 1);
					c--;
				}
			}
			else if (av[1][i] >= 97 && av[1][i] <= 122)
			{
				c = av[1][i] - 97 + 1;
				while (c > 0)
				{
					write(1, &av[1][i], 1);
					c--;
				}
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}

