#include <unistd.h>
#include <stdlib.h>
#include "check_mate.h"


void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		ft_success()
{
	ft_putstr("Success\n");
}

void		ft_fail()
{
	ft_putstr("Fail\n");
}

void		ft_error()
{
	ft_putchar('\n');
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			check_input(t_list *lst, int argc, char **argv)
{
	int		i;

	i = 2;
	if (lst->len_y != argc - 1)
	{  
		return (0);
	}
	while (i < argc)
	{
		if (ft_strlen(argv[i]) != lst->len_y)
			return (0);
		i++;
	}
	return (1);
}

void		print_tab(char **tab, int p)
{
	int		i;
	int		j;

	i = 0;
	while (i < p)
	{
		j = 0;
		while (j < ft_strlen(tab[0]))
		{  
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}  
}

char		**create_tab(int argc, char **argv, t_list *lst)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	if (!(tab = malloc(sizeof(char*) * (argc - 1))))
		return (NULL);
	while (i < argc - 1)
	{
		j = 0;
		if (!(tab[i] = malloc(sizeof(char) * ft_strlen(argv[1]))))
			return (NULL);
		while (j < argc - 1)
		{
			tab[i][j] = argv[i + 1][j];
			if (tab[i][j] == 'K')
			{
				lst->nb_king++;
				lst->x = i;
				lst->y = j;
			}
			j++;
		}
		i++;
	}
	if (lst->nb_king > 1)
		return (NULL);
	return (tab);
}

int			check_p(t_list *lst, char **tab)
{
	if (lst->x + 1 < lst->len_x && lst->y + 1 < lst->len_y)
	{
		if (tab[lst->x + 1][lst->y + 1] == 'P')
			return (1);
	}
	if (lst->x + 1 < lst->len_x && lst->y - 1 >= 0)
	{
		if (tab[lst->x + 1][lst->y - 1] == 'P')
			return (1);
	}
	return (0);
}

int			recursive_cross_horizontal(t_list *lst, char **tab, int x, int y)
{
	char	a;
	int		ct;

	ct = 0;
	if (x == lst->x && y == lst->y)
	{
		ct += recursive_cross_horizontal(lst, tab, x, y + 1);
		ct += recursive_cross_horizontal(lst, tab, x, y - 1);
	}
	else if (y >= 0 && y < lst->len_y)
	{
		a = tab[x][y];
		if (a == 'R' || a == 'Q')
			return (1);
		else if (a == 'B' || a == 'P')
			return (0);
		if (y < lst->y)
			return (recursive_cross_horizontal(lst, tab, x, y - 1));
		if (y > lst->y)
			return (recursive_cross_horizontal(lst, tab, x, y + 1));
	}
	else
		return (0);
	return (ct);
}

int			recursive_cross_vertical(t_list *lst, char **tab, int x, int y)
{
	char	a;
	int		ct;

	ct = 0;
	if (x == lst->x && y == lst->y)
	{  
		ct += recursive_cross_vertical(lst, tab, x - 1, y);
		ct += recursive_cross_vertical(lst, tab, x + 1, y);
	}
	else if (x >= 0 && x < lst->len_x)
	{  a = tab[x][y];
		if (a == 'R' || a == 'Q')
			return (1);
		else if (a == 'B' || a == 'P')
			return (0);
		if (x < lst->x)
			return (recursive_cross_vertical(lst, tab, x - 1, y));
		if (x > lst->x)
			return (recursive_cross_vertical(lst, tab, x + 1, y));
	}
	else
		return (0);
	return (ct);
}

int			recursive_diag(t_list *lst, char **tab, int x, int y)
{
	char	a;
	int		ct;

	ct = 0;
	if (x == lst->x && y == lst->y)
	{
		ct += recursive_diag(lst, tab, x - 1, y - 1);
		ct += recursive_diag(lst, tab, x + 1, y - 1);
		ct += recursive_diag(lst, tab, x - 1, y + 1);
		ct += recursive_diag(lst, tab, x + 1, y + 1);
	}
	else if (x >= 0 && x < lst->len_x && y >= 0 && y < lst->len_y)
	{
		a = tab[x][y];
		if (a == 'B' || a == 'Q')
			return (1);
		else if (a == 'P' || a == 'R')
			return (0);
		if (x < lst->x && y < lst->y)
			return (recursive_diag(lst, tab, x - 1, y - 1));
		if (x < lst->x && y > lst->y)
			return (recursive_diag(lst, tab, x - 1, y + 1));  
		if (x > lst->x && y < lst->y)
			return (recursive_diag(lst, tab, x + 1, y - 1));  
		if (x > lst->x && y > lst->y)
			return (recursive_diag(lst, tab, x + 1, y + 1));  
	}
	else
		return (0);
	return (ct);
}


int			main(int argc, char **argv)
{
	char	**tab;
	t_list	*lst;
	int		count;

	count =  0;
	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (argc == 1)
	{
		ft_error();
		return (0);
	}
	lst->x = 0;
	lst->y = 0;
	lst->nb_king = 0;
	lst->len_x = argc - 1;
	lst->len_y = ft_strlen(argv[1]);
	if (check_input(lst, argc, argv) == 0)
	{
		ft_error();
		return (0);
	}
	if (!(tab = create_tab(argc, argv, lst)))
		return (0);
	count += check_p(lst, tab);
	count += recursive_diag(lst, tab, lst->x, lst->y);
	count += recursive_cross_vertical(lst, tab, lst->x, lst->y);
	count += recursive_cross_horizontal(lst, tab, lst->x, lst->y);
	if (count > 0)
		ft_success();
	else
		ft_fail();
	return (0);
}
