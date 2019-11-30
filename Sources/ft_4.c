//
// Created by Pamelia Lettie on 28/11/2019.
//

#include "../Includes/sh.h"

//int					kol_args(char **str)
//{
//	int				i;
//
//	i = 1;
//	while (str[i])
//		i++;
//	return (i);
//}
char		*ft_strndup(const char *s1, int n)
{
	int		i;
	char 	*str;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (n + 1))))
		return (0);
	while (i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}