/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:57:34 by kboulkri          #+#    #+#             */
/*   Updated: 2023/11/20 19:34:34 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Personal functions */

size_t				ft_strlen_until_char(const char *str, char c);

/* get_next_line */

char				*get_next_line(int fd);
int					check_nl(char *buffer);
void				trim_str(char *str);
void				fix_buffer(char *str);
char				*ft_strjoin_gnl(char *s1, char *s2);

/* libft */

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				pf_convert_base(unsigned long nbr, char param, int *len);
void				pf_putnbr_base(unsigned long nbr, char *base, int *len);
void				go_search(va_list args, const char *str, int *len);
int					ft_printf(const char *str, ...);
int					pf_putchar(char c);
void				pf_putstr(char *str, int *len);
void				pf_putnbr(int n, int *len);
unsigned long		pf_strlen(char *str);

#endif