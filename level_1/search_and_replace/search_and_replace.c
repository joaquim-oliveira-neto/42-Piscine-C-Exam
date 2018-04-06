#include <unistd.h>

void	putstr(char *str)
{
	int		i;

	i = 0;
	while(*str)
		write(1, str++, 1);
}

int		strlen(char *str)
{
	int		i;

	i = 0;
	while (*str)
		i++;
	return (i);
}

char	*search_and_replace(char *str, char a, char b)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == a)
			str[i] = b;
	return (str);
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 4)
		if (strlen(av[2]) == 1 && strlen(av[3]) == 1)
			putstr(search_and_replace(av[1][i], av[2][0], av[3][0]));
	write(1, "\n", 1);
	return (0);
}
