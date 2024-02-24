#include "libft.h"

static int	ft_count_digits_base_l(long n, size_t base_l)
{
	unsigned long	nbr;
	int				d;

	nbr = n;
	d = (nbr == 0);
	while (nbr > 0)
	{
		nbr /= base_l;
		d++;
	}
	return (d);
}

char	*ft_ltoa_base(const char *base, long n)
{
	int				d;
	unsigned long	nbr;
	size_t			base_l;
	short			is_neg;
	char			*str;

	base_l = ft_strlen(base);
	if (!base_l)
		return (0);
	d = ft_count_digits_base_l(n, base_l);
	is_neg = (n < 0);
	str = malloc(sizeof(char) * (d + is_neg + 1));
	if (!str)
		return (0);
	if (is_neg)
		str[0] = '-';
	nbr = n;
	str[d + is_neg] = '\0';
	while (d--)
	{
		str[d + is_neg] = base[(nbr % base_l)];
		nbr /= base_l;
	}
	return (str);
}
