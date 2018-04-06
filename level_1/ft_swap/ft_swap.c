void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// Ne pas rendre la main - Tester //

#include <stdio.h>

int		main(void)
{
	int		a;
	int		b;

	a = 24;
	b = 42;
	printf("a : %d\n", a);
	printf("b : %d\n", b);
	ft_swap(&a, &b);
	printf("%s\n", "Resultat");
	printf("a : %d\n", a);
	printf("b : %d\n", b);
	return (0);
}
