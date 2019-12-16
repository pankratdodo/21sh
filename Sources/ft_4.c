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
	MALLOC(src, sizeof(char *) * len + 1);
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

char 		*ft_strcpy_len(char *str, int first, int last)
{
	char 	*src;
	int 	i;

	i = 0;
	if (!str || ft_strlen(str) < last)
		return (NULL);
	MALLOC(src, sizeof(char *) * (last - first + 2));
	while (str[first] && first <= last)
	{
		src[i] = str[first];
		i++;
		first++;
	}
	first++;
	src[first] = '\0';
	return (src);
}
