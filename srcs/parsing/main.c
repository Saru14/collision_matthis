/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:53 by namenega          #+#    #+#             */
/*   Updated: 2021/02/04 16:17:57 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error_exit(char *s)
{
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
	// free();
	exit(0);
}

int		ft_error_msg(char *s)
{
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
	return (0);
}

int		main(int ac, char const **av)
{
	t_global	*glb;

	glb = ft_calloc_2(sizeof(t_global));
	// glb = ft_init_struct_0(glb);
	glb->map = ft_calloc_2(sizeof(t_map));
	glb->pos = ft_calloc_2(sizeof(t_pos));
	glb->move = ft_calloc_2(sizeof(t_move));
	if (!(ac == 2 || ac == 3))
		return (ft_error_msg("Error\nToo many/few arguments.\nExit Program"));
	if (!(glb->data = ft_data((char*)av[1], (ac == 2), glb->map, glb->pos)))
		return (ft_error_msg("Error\nParsing : Fail\nExit Program"));
	ft_mlx_data(glb->data);
	if (ac == 2)
	{
		hook_loop(glb);
		ft_free_data(glb->data, "End Of Program");
	}
	/*if (ac == 3 && !ft_strncmp((char*)av[2], "-save", 6))
		ft_save(data, (char*)av[1]);*/
	return (0);
}



/*
** Mettre error si ligne random
*/
