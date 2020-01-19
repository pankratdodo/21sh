#include "../Includes/sh.h"

void		ft_putendl_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

char 		*ft_strccpy(char *str, char c)
{
	char 	*src;
	int		i;
	int 	len;

	i = 0;
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	if (!(src = malloc(sizeof(char*) * len + 1)))
		on_crash(MALLOC_ERR);
	while (str[i] && str[i] != c)
	{
		src[i] = str[i];
		i++;
	}
	i++;
	src[i] = '\0';
	return (src);
}

int 		ft_strclen(char *str, char c)
{
	int 	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char 		*ft_strcpy_len(char *com, int first, int last)
{
	char *str;
	int i;

	i = 0;
	if (!(str = malloc(sizeof(char *) * (last - first + 2))))
		on_crash(MALLOC_ERR);
	while (first <= last)
	{
		str[i] = com[first];
		first++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
