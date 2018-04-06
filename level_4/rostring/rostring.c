#include <unistd.h>

int		issp(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

int		main(int ac, char **av)
{
	int		i;
	int		firstwordstart;
	int		fwlen;

	if (ac > 1)
	{
		firstwordstart = 0;
		while (issp(av[1][firstwordstart]) && av[1][firstwordstart] != '\0')
			firstwordstart++;
		fwlen = 0;
		while (!issp(av[1][firstwordstart + fwlen]))
			fwlen++;
		i = firstwordstart + fwlen;
		while (av[1][i] != '\0')
		{
			while (issp(av[1][i]) && av[1][i] != '\0')
				i++;
			if (av[1][i] == '\0')
				break;
			if (ac == 0)
				write(1, " ", 1);
			ac = 0;
			while (!issp(av[1][i]))
			{
				write(1, av[1] + i++, 1);
			}
		}
		if (fwlen && ac == 0)
			write(1, " ", 1);
		write(1, av[1] + firstwordstart, fwlen);
	}
	write(1, "\n", 1);
	return (0);
}
