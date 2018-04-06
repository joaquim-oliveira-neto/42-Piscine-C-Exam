#include <unistd.h>

char	letter(char c)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = "abcdefghijklmnopqrstuvwxyz";
	s2 = "nopqrstuvwxyzabcdefghijklm";
	i = 0;
	while (s1[i])
	{
		if (c == s1[i])
			return(s2[i]);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] = letter(av[1][i]);
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] = letter(av[1][i] + 32) - 32;
			i++;
		}
		i = 0;
		while (av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
