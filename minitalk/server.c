/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:07:09 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/27 22:14:58 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ascii_art(void)
{
	const char	*green;
	const char	*reset;

	green = "\033[0;32m";
	reset = "\033[0m";
	write(1, green, 7);
	write(1, "   _____ __________ _    ____________ \n", 39);
	write(1, "  / ___// ____/ __ \\ |  / / ____/ __ \\\n", 40);
	write(1, "  \\__ \\/ __/ / /_/ / | / / __/ / /_/ /\n", 40);
	write(1, " ___/ / /___/ _, _/| |/ / /___/ _, _/ \n", 40);
	write(1, "/____/_____/_/ |_| |___/_____/_/ |_|  \n", 41);
	write(1, "\n", 1);
	write(1, reset, 4);
}

void	f(int sig, siginfo_t *data, void *context)
{
	static int	bit_count;
	static char	tab[8];
	static char	c;
	static int	pid;
	int			i;

	(void )context;
	i = 0;
	if (pid != data->si_pid)
	{
		1 && (pid = data->si_pid, c = 0, bit_count = 0);
		while (i < 8)
			tab[i++] = 0;
	}
	if (sig == SIGUSR1)
		tab[bit_count++] = 0;
	else
		tab[bit_count++] = 1;
	if (bit_count == 8)
	{
		2 && (c = 0, i = -1, bit_count = 0);
		while (++i < 8)
			c |= (tab[i] << (7 - i));
		write(1, &c, 1);
	}
}

void	affiche_msg(struct sigaction *sig)
{
	sigaction(SIGUSR1, sig, NULL);
	sigaction(SIGUSR2, sig, NULL);
}

void	ft_put_nbr(int nb)
{
	char	*str;

	str = "0123456789";
	if (nb > 9)
		ft_put_nbr(nb / 10);
	write(1, &str[nb % 10], 1);
}

int	main(void)
{
	const char			*red;
	const char			*reset;
	struct sigaction	sig;

	reset = "\033[0m";
	red = "\033[0;31m";
	sig.sa_sigaction = f;
	sig.sa_flags = SA_SIGINFO;
	ascii_art();
	write(1, red, 7);
	write(1, "PID : ", 6);
	ft_put_nbr(getpid());
	write(1, "\n", 1);
	write(1, reset, 4);
	write(1, "\n", 1);
	affiche_msg(&sig);
	while (1)
		;
	return (0);
}
