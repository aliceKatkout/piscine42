/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:36:25 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/15 10:42:43 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char n)
{	
	if (!(('a' <= n && n <= 'z') || ('A' <= n && n <= 'Z')))
	{
		return (0);
	}	
	return (1);
}

int	is_numeric(char n)
{
	if (!('0' <= n && n <= '9'))
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '\0' && str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 1;
	while (str[i] != '\0')
	{
		if ((!is_alpha(str[i - 1]) && !is_numeric(str[i - 1])))
			if ('a' <= str[i] && str[i] <= 'z')
				str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
