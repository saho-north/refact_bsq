/* static long long	convert_num(const char *str, bool is_negative)
{
	long long	ov_div;
	long long	ov_mod;
	long long	num;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	if (is_negative)
		ov_mod++;
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (num > ov_div || (num == ov_div && (*str - '0') > ov_mod))
		{
			if (!is_negative)
				return (-1);
			else
				return (0);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	if (is_negative)
		num *= -1;
	return (num);
}

int	ft_atoi(const char *str)
{
	long long	num;
	bool		is_negative;

	is_negative = false;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = true;
		str++;
	}
	num = convert_num(str, is_negative);
	return ((int)num);
}
 */
