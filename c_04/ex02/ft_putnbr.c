#include <limits.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int	nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	else if (nb < 0)
	{	
		write(1, "-", 1);
		ft_putnbr(nb * -1);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

/*int	main(void)
{
	ft_putnbr(2344557);
	write(1, "\n", 1);
	ft_putnbr(-237);
	write(1, "\n", 1);
	ft_putnbr(42);
}*/
