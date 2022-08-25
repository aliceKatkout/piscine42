/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:20:40 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/24 16:40:39 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	in_base(char c, char	*base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c != base[i])
			i++;
		else
			return (1);
	}
	return (0);
}

int	convert_to_dec(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	check_base(char *base)
{
	int	i;
	int	b;
	int	j;

	b = 0;
	while (*(base + b))
		b++;
	if (b <= 1)
		return (0);
	i = 0;
	while (i < b)
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		j = 1;
		while (j + i <= b)
		{
			if (base[i] != base[j + i])
				j++;
			else
				return (0);
		}
		i++;
	}
	return (b);
}

void	ft_reverse(char *res)
{
	int	size;
	int	i;
	int	tmp;

	size = 0;
	if (res[0] == '-')
		i = 1;
	else
		i = 0;
	while (res[size])
		size++;
	while (i < size -1)
	{
		tmp = res[i];
		res[i] = res[size - 1];
		res[size - 1] = tmp;
		i++;
		size --;
	}
}
