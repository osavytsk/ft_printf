/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 19:03:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 19:03:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_split(char current, char c)
{
	return (current == c || current == '\0');
}

static int		count_words(char const *str, char c)
{
	int result;
	int i;
	int temp;

	temp = 0;
	i = 0;
	result = 0;
	while (str[i])
	{
		if (!is_split(str[i], c) && !temp)
		{
			temp = 1;
			result++;
		}
		else if (is_split(str[i], c))
			temp = 0;
		i++;
	}
	return (result + 1);
}

static int		length(char const *str, int i, char c)
{
	int y;

	y = 0;
	while (!is_split(str[y + i], c))
		y++;
	return (y);
}

static char		**free_result(char **res)
{
	ft_strdel(res);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	int		y;
	int		word;

	if (!s || !(result = (char**)malloc(sizeof(char *) * (count_words(s, c)))))
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		if (is_split(s[i], c))
		{
			i++;
			continue;
		}
		y = 0;
		if (!(result[word] = (char*)malloc(sizeof(char) * (length(s, i, c)))))
			return (free_result(result));
		while (!is_split(s[i], c))
			result[word][y++] = s[i++];
		result[word++][y] = '\0';
	}
	result[word] = 0;
	return (result);
}
