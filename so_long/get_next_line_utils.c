/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   get_next_line_utils.c	  :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: hseven <hseven@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2022/09/25 20:43:44 by hseven	#+#	#+#	 */
/*   Updated: 2022/09/30 13:39:36 by hseven	   ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "so_long.h"

int	check(char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == '\n')
		{
			return (0);
		}
		a++;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	char	*str;
	int		b;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	a = -1;
	while (s1[++a] != '\0')
		str[a] = s1[a];
	b = -1;
	while (s2[++b] != '\0')
		str[a + b] = s2[b];
	str[a + b] = '\0';
	free(s1);
	return (str);
}

void	*ft_calloc_gnl(size_t nitems, size_t size)
{
	void	*a;

	a = malloc(size * nitems);
	if (!a)
		return (0);
	ft_memset(a, '\0', nitems);
	return (a);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
