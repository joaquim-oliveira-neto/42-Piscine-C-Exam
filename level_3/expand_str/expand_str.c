#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_more_char(char *str, int i)
{
	while (str[i])
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
			return (1);
	return (0);
}

int		print_spaces(char c, int lol)
{
	if (lol)
	{
		ft_putchar(c);
		ft_putchar(c);
		ft_putchar(c);
		return (0);
	}
	else
	{
		ft_putchar(c);
		return (1);
	}
}

void	expand_str(char *str)
{
	int		i;
	int		flag_end_word;
	int		flag_sup;

	i = 0;
	flag_end_word = 0;
	flag_sup = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			flag_end_word = print_spaces(str[i], 0);
		else if (flag_end_word && is_more_char(str, i))
			flag_end_word = print_spaces(' ', 1);
		while (str[i] == ' ' || str[i] == '\t')
		{
			flag_sup = 1;
			i++;
		}
		if (flag_sup && i-- > -10)
			flag_sup = 0;
		i++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	expand_str(argv[1]);
	return (0);
}
