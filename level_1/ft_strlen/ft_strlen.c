int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Ne pas rendre la main - Tester //

#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac != 2)
		write(1, "Erreur d'arguments !\n", 22);
	else
		printf("%d\n", ft_strlen(av[1]));
	return (0);
}
