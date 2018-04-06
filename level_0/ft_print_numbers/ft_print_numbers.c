#include <unistd.h>

void		ft_print_numbers(void)
{
	write(1, "0123456789", 10);
}

// Ne pas rendre la main.c - Tester //

int			main(void)
{
	ft_print_numbers();
	return (0);
}
