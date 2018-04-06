#include <unistd.h>

void	ft_first_word(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_first_word(av[1]);
		return (0);
	}
	else
		write(1, "\n", 1);
	return (0);
}
