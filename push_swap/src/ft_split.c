/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:59:16 by aluzingu          #+#    #+#             */
/*   Updated: 2024/05/18 11:59:16 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_w(char *str)
{
	int	i;
	int	tot_w;

	i = 0;
	tot_w = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			tot_w++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
		}
		else
			i++;
	}
	return (tot_w);
}

char	*ft_dup(char *ptr)
{
	int		i;
	char	*retorno;

	i = 0;
	while (ptr[i] && ptr[i] != ' ' && ptr[i] != '\t')
		i++;
	retorno = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (ptr[i] && ptr[i] != ' ' && ptr[i] != '\t')
	{
		retorno[i] = ptr[i];
		i++;
	}
	retorno[i] = '\0';
	return (retorno);
}

char	**ft_split(char *str)
{
	char	**result;
	int		count;
	char	*ptr;

	count = ft_count_w(str);
	result = (char **)malloc((count + 1) * sizeof(char *));
	count = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
		{
			ptr = str;
			while (*str && *str != ' ' && *str != '\t')
				str++;
			result[count] = ft_dup(ptr);
			count++;
		}
		else
			str++;
	}
	result[count] = NULL;
	return (result);
}
