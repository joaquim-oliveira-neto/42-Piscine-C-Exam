int		max(int *tab, unsigned int len)
{
	unsigned int	cmp;
	int				cpy;

	cmp = 0;
	cpy = tab[0];
	while (cmp < len)
	{
		if (cpy < tab[cmp])
			cpy = tab[cmp];
		++cmp;
	}
	if (cmp == len)
		return (cpy);
	return (0);
}
