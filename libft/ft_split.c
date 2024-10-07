/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:21:47 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/12 20:14:49 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeup(char *sp)
{
	int	i;

	i = 0;
	while (sp[i] != '\0')
	{
		free(sp);
		i++;
	}
	free(sp);
}

static int	ft_wordcount(char c, const char *s)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

static void	ft_copy_substring(char *word, char *s, char c, int j)
{
	int		i;

	i = 0;
	while (s[j] != '\0' && s[j] == c)
		j++;
	while (s[j + i] != c && s[j + i] != '\0')
	{
		word[i] = s[j + i];
		i++;
	}
	word[i] = '\0';
}

static char	*split_aux(char *s, char c, int *k)
{
	char	*word;
	int		j;

	j = *k;
	word = NULL;
	while (s[*k] != '\0')
	{
		if (s[*k] != c)
		{
			while (s[*k] != '\0' && s[*k] != c)
				*k += 1;
			word = (char *)malloc(sizeof(char) * (*k + 1));
			if (word == NULL)
				return (NULL);
			break ;
		}
		*k += 1;
	}
	ft_copy_substring(word, s, c, j);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**sp;
	int				j;
	int				i;
	int				pos;

	if (s == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_wordcount(c, s);
	sp = (char **)malloc((j + 1) * sizeof(char *));
	if (sp == NULL)
		return (NULL);
	sp[j] = NULL;
	while (i < j)
	{
		sp[i] = split_aux((char *)s, c, &pos);
		if (sp[i] == NULL)
			ft_freeup(sp[i]);
		i++;
	}
	return (sp);
}

// int	main(void)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	char const	*s = "ahoihappyheaderhere";
// 	//char const *s = "ah";
// 	//char const *s = "ha";
// 	//char const *s = "hhh";
// 	//char const	*s = "testonec";
// 	//char const *s = "ello!hhhhhhhhh";
// 	char c = 'h';
// 	j = ft_wordcount(c, s);
// 	char	**sp = ft_split(s, c);
// 	while (i <= j)
// 	{
// 		printf("El array dividido es %s\n", sp[i]);
// 		free(sp[i]);
// 		i++;
// 	}
// 	free(sp);
// 	return (0);
// }
