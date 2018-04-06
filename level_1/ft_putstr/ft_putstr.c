#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

// Ne pas rendre la main - Tester //

int		main(int ac, char **av)
{
	(void)ac;
	ft_putstr(av[1]);
	ft_putstr("\n");
	return (0);
}
