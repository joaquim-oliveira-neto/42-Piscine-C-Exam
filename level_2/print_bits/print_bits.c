#include <unistd.h>

void	print_bits(unsigned char octet)
{
	char	bits[8];
	int		nb;
	int		count;
	char	z;

	nb = octet;
	count = 0;
	while (count < 8)
	{
		bits[count] = nb % 2;
		nb = nb / 2;
		count++;
	}
	while (count - 1 >= 0)
	{
		z = bits[count - 1] + 48;
		write(1, &z, 1);
		count--;
	}
}

// Ne pas rendre la main - Tester //
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	if (ac == 2)
		print_bits(atoi(av[1]));
	else
		printf("Erreur d'arguments\n");
	return (0);
}
