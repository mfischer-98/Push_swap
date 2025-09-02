/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:27:18 by mefische          #+#    #+#             */
/*   Updated: 2025/09/02 12:32:33 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>

char	**ft_split(char const *s, char c);
long	ft_atol(const char *nptr);

//printf
int		ft_printf(const char *f, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_unsig_putnbr(unsigned int n);
int		ft_printhexa(unsigned long n, char *base);
int		ft_pointer(void *ptr);

#endif
