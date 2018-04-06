#include <unistd.h>

void	letter(char c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	else if ( c >= 97 && c <= 122)
		c = c -32;
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		while (av[1][i])
		{
			letter(av[1][i]);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
