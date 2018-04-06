#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while(src[i])
	{
		i++;
	}
	if ((dest = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return(dest);
}

// Ne pas rendre la main - Tester //

#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	char	*src;

	src = "coucou";
	printf("%s \n", ft_strdup(src));
	return (0);
}
