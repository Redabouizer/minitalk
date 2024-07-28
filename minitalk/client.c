/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:59:46 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/27 23:04:51 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_number(char *str)
{
	int		i;
	long	nbr;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	nbr = ft_atoi(str);
	return (nbr);
}

void	env_bit(int p_id, char c)
{
	int		bit;
	int		i;

	i = 0;
	bit = 128;
	while (i < 8)
	{
		if (c & bit)
			kill(p_id, SIGUSR1);
		else
			kill(p_id, SIGUSR2);
		c <<= 1;
		i++;
		usleep(500);
	}
}

int	env_message(int p_id, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		env_bit(p_id, str[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	*number;
	char	*msg;
	int		p_id;

	if (ac == 3)
	{
		number = av[1];
		msg = av[2];
		p_id = check_number(number);
		if (p_id == -1)
			return (write(2, "PID INCORRECT\n", 14), 1);
		env_message(p_id, msg);
	}
	else
		write(2, "ARGUMENT INCORRECT\n", 19);
	return (0);
}
