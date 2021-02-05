/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:49:04 by namenega          #+#    #+#             */
/*   Updated: 2021/02/05 20:45:11 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_mvleft(t_pos *pos, t_map *map)
{
	double i;
	double j;

	i = 0.2 - (0.4 * (pos->dir.y > 0));
	j = 0.2 - (0.4 * (pos->dir.x < 0));
	if(map->real_map[(int)map->x][(int)(map->y + j)] == 7)
		map->y += pos->dir.x * MS;
	if(map->real_map[(int)(map->x + i)][(int)map->y] == 7)
		map->x -= pos->dir.y * MS;

}

void		ft_mvright(t_pos *pos, t_map *map)
{
	double i;
	double j;

	i = 0.2 - (0.4 * (pos->dir.y < 0));
	j = 0.2 - (0.4 * (pos->dir.x > 0));
		if(map->real_map[(int)(map->x + i)][(int)map->y] == 7)
			map->x += pos->dir.y * MS;
		if(map->real_map[(int)map->x][(int)(map->y + j)] == 7)
			map->y -= pos->dir.x * MS;

}

// int			hook_loop(t_pos *pos/*, t_map *map*/)
// {
// 	ft_rotate_left(pos);
// 	ft_rotate_right(pos);
// 	// ft_rotate_mvright(pos, map);
// 	// ft_rotate_mvleft(pos, map);
// 	// ft_rotate_mvforward(pos, map);
// 	// ft_rotate_mvbackward(pos, map);
// 	return (0);
// }
