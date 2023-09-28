/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:02:23 by tquemato          #+#    #+#             */
/*   Updated: 2023/09/26 15:02:25 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_handle_pointer(va_list ap)
{
	void	*n;

	n = va_arg(ap, void *);
	write(1, "0x", 2);
	return (ft_putnbr_base((unsigned long long)n, "0123456789abcdef") + 2);
}
