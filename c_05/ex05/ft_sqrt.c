/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:19:01 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/24 09:45:17 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 2;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return ((int)i);
		else
			i ++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("%d", ft_sqrt(INT_MAX));
}
*/
