/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 18:16:55 by dwillard          #+#    #+#             */
/*   Updated: 2022/01/01 18:16:58 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*freedom(char ***arr)
{
	char	**temp;

	temp = *arr;
	while (temp)
	{
		free(*temp);
		temp += sizeof(char *);
	}
	free(*arr);
	return (NULL);
}

char	**ft_arrdup(char **arr)
{
	char	**temp;
	int		index;
	int		counter;

	index = 0;
	counter = 0;
	while (arr[counter])
		counter++;
	temp = malloc(sizeof(char *) * counter + sizeof(char *));
	if (!temp)
		return (NULL);
	while (index < counter)
	{
		temp[index] = ft_strdup(arr[index]);
		if (!temp[index])
			return (freedom(&temp));
		index++;
	}
	temp[index] = NULL;
	return (temp);
}