#include "minitalk.h"
#include <stdio.h>



int check_number(char *str)
{
    int i;
    long nbr;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        i++;
    }
    nbr = ft_atoi(str);
    return nbr;
}

int env_bit(int p_id, char c)
{
    int i = 128;
    int j = 0;

    while (i > 0)
    {
        if ((int)c & i)
            kill(p_id, SIGUSR2);
        else
            kill(p_id, SIGUSR1);
        i >>= 1;
        j++;
        usleep(500);
    }
    return 0;
}

int env_message(int p_id, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        env_bit(p_id, str[i]);
        i++;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        char *number;
        char *msg;
        int p_id;

        number = av[1];
        msg = av[2];
        p_id = check_number(number);
        if (p_id == -1)
            return (write(2, "PID INCORRECT\n", 14), 1);
        env_message(p_id, msg);
    }
    else
        write(2, "MANY ARGUMENT\n", 14);
    return 0;
}
