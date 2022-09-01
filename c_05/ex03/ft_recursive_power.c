/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:51:54 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/24 16:13:47 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int n, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power >= 1)
		return (n * (ft_recursive_power(n, (power - 1))));
	return (n);
}
