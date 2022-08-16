#include <stdio.h>

int	is_space(char	c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_numeric(char	c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	str_to_int(char *str)
{
	int	k;
	int	res;

	res = 0;
	k = 0;
	while (str[k] != 0)
	{
		res *= 10;
		res += str[k] - 48;
		k++;
	}
	return (res);
}

int	ft_atoi(char *str)
{
	char	nbr[100];
	int	minus;
	int	i;
	int	j;

	i = 0;
	minus = 0;
	j = 0;
	while (str[i] != '\0' && !is_numeric(str[i]))
	{
		if (str[i] == '-')
			minus ++;
		if (is_space(str[i]) || str[i] == '-' || str[i] == '+')
			i++;
	}
	while (is_numeric(str[i + j]) && str[i + j] != 0)
	{
		nbr[j] = str[i + j];
		j++;
	}
	printf("nbr en  char : %s\n", nbr);
	nbr[j] = 0;
	if (minus % 2 == 0)
		return (str_to_int(nbr));
	else
		return (str_to_int(nbr) * -1);
		
}

int	main()
{
	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
}
