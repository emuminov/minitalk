/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:06:06 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/26 07:49:40 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "../libft/libft.h"
# define CHAR_BITS 8
# define INT_BITS 32

typedef struct s_server_state
{
	int		size;
	int		size_received;
	char	*message;
	int		message_received;
}	t_server_state;

#endif
