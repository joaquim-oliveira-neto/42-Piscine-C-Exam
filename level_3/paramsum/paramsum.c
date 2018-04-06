#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar('0' + nb);
	}
}

int		main(int argc, char **argv)
{
	(void)argv;
	ft_putnbr(argc - 1);
	ft_putchar('\n');
	return (0);
}
