/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:39:23 by namenega          #+#    #+#             */
/*   Updated: 2021/02/04 13:14:16 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_mlx_pxl_put(t_data *data, int x, int y, t_rgb color)
{
	(void)color;
	(data->addr)[y * (data->pxl_line) + x] = color.r + color.g + color.b;
}

void		ft_verline(t_data *data, t_move *move, t_pos *pos, t_map *map)
{
	int		i;

	i = -1;
	while (++i < move->draw_start)
		ft_mlx_pxl_put(data, pos->x, i, map->colorc);
	while (move->draw_start < move->draw_end)
	{
		ft_mlx_pxl_put(data, pos->x, move->draw_start, map->color);
		move->draw_start++;
		i++;
	}
	i--;
	while(++i < data->height)
		ft_mlx_pxl_put(data, pos->x, i, map->colorf);
}

void		*ft_calloc_2(size_t nmemb)
{
	void	*tab;

	tab = malloc(nmemb);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nmemb);
	return (tab);
}

void		ft_mlx_data(t_data *data)
{
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, data->width,
		data->height, "CUB3D")) == NULL)
		ft_free_data(data, "Error\nTask - parsing : Fail_3 !");
	if ((data->img = mlx_new_image(data->mlx_ptr, data->width,
		data->height)) == NULL)
		return ;
	if ((data->addr = (int *)mlx_get_data_addr(data->img,
		&data->bits_per_pxl, &data->line_length, &data->endian)) == NULL)
		return ;
	// mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	data->pxl_line = data->line_length / (data->bits_per_pxl / 8);
}
