/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:11:50 by fbouleau          #+#    #+#             */
/*   Updated: 2022/08/27 14:39:17 by fbouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <write_number.h>

int	good_number_format(char *nb_str)
{
	char	ui_max;
	int		len;
	int		i;

	len = ft_strlen(nb_str);
	if (len > 10)
		return (0);
	i = 0;
	while (nb_str[i])
	{
		if (!is_numeric(nb_str[i]))
			return (0);
		i++;
	}
	if (len < 10)
		return (1);
	ui_max = "4294967295";
	i = 0;
	while (i < 10 && nb_str[i] == ui_max[i])
		i++;
	if (i == 10 || nb_str[i] < ui_max[i])
		return (1);
	return (0);
}
