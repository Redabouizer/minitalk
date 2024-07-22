#include "utils.h"

long    ft_atoi(const char *str)
{
	int		s;
	long	r;
	int		i;

	s = 1;
	i = 0;
	r = 0;
	while (str[i] && ((str[i] == 32) || ((str[i] >= 9) && (str[i] <= 13))))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			s *= -1;
		i++;
	}
	while ((*(str + i) >= '0' && *(str + i) <= '9') && *(str + i))
	{
		r = r * 10 + str[i] - '0';
        if ((r > 100000 && s == 1) || s == -1)
			return (-1);
		i++;
	}
	return (s * r);
}