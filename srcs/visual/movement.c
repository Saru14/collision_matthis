/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:12:04 by Nathan            #+#    #+#             */
/*   Updated: 2021/02/04 18:00:50 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_rotate_right(t_pos *pos/*, t_global *glb*/)
{
	if (KEYCODE_RIGHTARROW) //rotate to the right
	{
		// both cam dir and cam plane must be rotated
		pos->old_dir.x = pos->dir.x;
		pos->dir.x = pos->dir.x * cos(-RS) - pos->dir.y * sin(-RS);
		pos->dir.y = pos->old_dir.x * sin(-RS) + pos->dir.y * cos(-RS);
		pos->old_pl_cam.x = pos->plane_cam.x;
		pos->plane_cam.x = pos->plane_cam.x * cos(-RS) - pos->plane_cam.y * sin(-RS);
		pos->plane_cam.y = pos->old_pl_cam.x * sin(-RS) + pos->plane_cam.y * cos(-RS);
	}
}

void		ft_rotate_left(t_pos *pos)
{
	if (KEYCODE_LEFTARROW) //rotate to the left
	{
		//both cam dir and cam plane must be rotated
		pos->old_dir.x = pos->dir.x;
		pos->dir.x = pos->dir.x * cos(RS) - pos->dir.y * sin(RS);
		pos->dir.y = pos->old_dir.x * sin(RS) + pos->dir.y * cos(RS);
		pos->old_pl_cam.x = pos->plane_cam.x;
		pos->plane_cam.x = pos->plane_cam.x * cos(RS) - pos->plane_cam.y * sin(RS);
		pos->plane_cam.y = pos->old_pl_cam.x * sin(RS) + pos->plane_cam.y * cos(RS);
		//pos->plane_cam.x++;
	}
}

void		ft_mvforward(t_pos *pos, t_map *map)
{
	if(KEYCODE_W) //move forward if no wall in front of you
	{
		if(map->real_map[(int)(map->x + pos->dir.x * 0.2)][(int)map->y] == 7)
			map->x += pos->dir.x * MS;
		if(map->real_map[(int)map->x][(int)(map->y + pos->dir.y * 0.2)] == 7)
			map->y += pos->dir.y * MS;
	}
}

void		ft_mvbackward(t_pos *pos, t_map *map)
{
	if(KEYCODE_S) //move backward if no wall behind you
	{
		if(map->real_map[(int)(map->x - pos->dir.x * 0.2)][(int)map->y] == 7)
			map->x -= pos->dir.x * MS;
		if(map->real_map[(int)map->x][(int)(map->y - pos->dir.y * 0.2)] == 7)
			map->y -= pos->dir.y * MS;
	}
}

