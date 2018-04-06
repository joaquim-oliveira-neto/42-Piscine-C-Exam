int		ft_atoi(const char *str)
{
	{
		int		i;
		int		nbr;
		int		negative;

		nbr = 0;
		negative = 0;
		i = 0;
		while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
				(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
			i++;
		if (str[i] == '-')
			negative = 1;
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
		{
			nbr *= 10;
			nbr += (int)str[i] - '0';
			i++;
		}
		if (negative == 1)
			return (-nbr);
		else
			return (nbr);
	}
}

// Ne pas rendre la main - Tester //

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1 , &c, 1);
}

void	*ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		write(1, "Erreur d'argument !\n", 22);
	else {
		ft_putnbr(atoi(av[1]));
		ft_putchar('\n');
		ft_putnbr(ft_atoi(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
