#include <unistd.h>

void    ft_putnbr(int nbr)
{
        int                     i;
        int                     result[11];
        char            c;
        long long       n;

        n = nbr;
        i = 0;
        while (1)
        {
                result[i] = n % 10;
                n /= 10;
                i++;
                if (n == 0)
                        break ;
        }
        i--;
        while (i >= 0)
        {
                c = result[i] + '0';
                write(1, &c, 1);
                i--;
        }
        write(1, "\n", 1);
}

int main(void)
{
	ft_putnbr(5285794);
}
