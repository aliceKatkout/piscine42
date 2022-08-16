void	put_str(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}
