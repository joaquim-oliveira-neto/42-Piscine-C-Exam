#include <unistd.h>

int		main(void)
{
	int		i;
	char	a;
	char	b;

	i = 0;
	a = 'a';
	b = 'B';
	while (i < 26)
	{
		if (i % 2 == 0)
		{
			write(1, &a, 1);
			a += 2;
		}
		else
		{
			write(1, &b, 1);
			b += 2;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
