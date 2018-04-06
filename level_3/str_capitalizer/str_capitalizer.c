#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_sep(char c)
{
	if (c == '\t' || c == '\n' || c == ' ' || c == '\v' || c == '\f'|| c == '\r')
		return (1);
	else
		return (0);
}

void	ft_str_capitalizer(char *str)
{
	int		i;

	if (str[0] >= 'a' && str[0] <= 'z')
		ft_putchar(str[0] - 32);
	else
		ft_putchar(str[0]);
	i = 1;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
				&& is_sep(str[i - 1]))
			ft_putchar(str[i] - 32);
		else if ((str[i] >= 'A' && str[i] <= 'Z')
				&& !is_sep(str[i - 1]))
			ft_putchar(str[i] + 32);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		ft_str_capitalizer(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
