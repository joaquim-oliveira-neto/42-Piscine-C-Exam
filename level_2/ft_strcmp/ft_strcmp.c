int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

// Ne pas rendre la main - Tester //
#include <stdio.h>

int		main(int ac, char **av)
{
	printf("%d\n", ft_strcmp(av[1], av[2]));
	return (0);
}
