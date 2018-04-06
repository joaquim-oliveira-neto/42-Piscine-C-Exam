unsigned char   reverse_bits(unsigned char octet)
{
    return  (((octet >> 0) & 1) << 7) | \
            (((octet >> 1) & 1) << 6) | \
            (((octet >> 2) & 1) << 5) | \
            (((octet >> 3) & 1) << 4) | \
            (((octet >> 4) & 1) << 3) | \
            (((octet >> 5) & 1) << 2) | \
            (((octet >> 6) & 1) << 1) | \
            (((octet >> 7) & 1) << 0);
}

unsigned char	reverse_bits2(unsigned char octet)
{
	unsigned char	res;
	int				count;

	res = 0;
	count = 8;
	while (count)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		count--;
	}
	return (res);
}

// Ne pas rendre la main - Tester //

#include <stdlib.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%d\n", reverse_bits(atoi(av[1])));
		printf("%d\n", reverse_bits2(atoi(av[1])));
	}
	else
		printf("%s\n", "Aucun d'argument");
	return (0);
}
