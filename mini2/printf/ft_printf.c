/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:19:52 by opaulman          #+#    #+#             */
/*   Updated: 2025/07/14 19:46:41 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	fyuumi;
	int		numofparameters;
	char	*copy;
	char	*parameters;
	int		len;

	va_start(fyuumi, s);
	copy = ft_strdup(s);
	numofparameters = ft_paramcount(copy);
	parameters = (ft_typeofparam(copy, numofparameters));
	if (parameters == 0)
		return (0);
	len = ft_writestring(copy, fyuumi, parameters);
	va_end(fyuumi);
	free(copy);
	free(parameters);
	return (len);
}
