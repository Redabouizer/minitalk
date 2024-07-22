#include "minitalk.h"

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void ft_ascii_Art()
{
    const char *green = "\033[0;32m";
    const char *reset = "\033[0m";

    write(1, green, 7);
    write(1, "   _____ __________ _    ____________ \n", 39);
    write(1, "  / ___// ____/ __ \\ |  / / ____/ __ \\\n", 40);
    write(1, "  \\__ \\/ __/ / /_/ / | / / __/ / /_/ /\n", 40);
    write(1, " ___/ / /___/ _, _/| |/ / /___/ _, _/ \n", 40);
    write(1, "/____/_____/_/ |_| |___/_____/_/ |_|  \n", 41);
    write(1, "\n", 1);
    write(1, reset, 4);
}

void f(int sig, siginfo_t *data, void *context)
{
    static int bit_count;
    static char tab[8];
    static char c;
    static int  pid;
    int i;

    if (pid != data->si_pid)
    {
        pid = data->si_pid;
        c = 0;
        bit_count = 0;
        while (i < 8)
            tab[i++] = 0;
    }
    if (sig == SIGUSR1)
        tab[bit_count] = 0;
    else
        tab[bit_count] = 1;
    bit_count++;
    if (bit_count == 8)
    {
        c = 0;
        i = 0;
        while (i < 8)
        {
            c |= (tab[i] << (7 - i));
            i++;
        }
        write(1, &c, 1);
        bit_count = 0;
    }
}

void afficher_msg(struct sigaction *sig)
{
    // signal(SIGUSR1, f);
    // signal(SIGUSR2, f);
    sigaction(SIGUSR1, sig, NULL);
    sigaction(SIGUSR2, sig, NULL);
}

void ft_put_nbr(int nb)
{
    char str[10] = "0123456789";

    if (nb > 9)
        ft_put_nbr(nb / 10);
    write(1, &str[nb % 10], 1);
}

int main()
{
    const char *red = "\033[0;31m";
    const char *reset = "\033[0m";
    struct sigaction sig;

    sig.sa_sigaction = f;
    sig.sa_flags = SA_SIGINFO;
    ft_ascii_Art();
    write(1, red, 7);
    write(1, "PID : ", 6);
    ft_put_nbr(getpid());
    write(1, reset, 4);
    write(1, "\n", 1);
    afficher_msg(&sig);
    while (1)
        ;
    return 0;
}