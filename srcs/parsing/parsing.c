/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:41:39 by namenega          #+#    #+#             */
/*   Updated: 2021/02/04 13:14:35 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_parsing_data(t_list *el, t_data *data, t_map *map, t_pos *pos)
{
	char	*line;

	line = (char *)(el->content);
	if (!line)
		return (0);
	else if (line[0] == 0)
		return (1);
	else if (line[0] == 'R' && ft_isspace(line[1]))
		return (ft_resolution(data, &line[1]));
	else if (line[0] == 'N' && line[1] == 'O' && ft_isspace(line[2]))
		return (ft_north(data, &line[2]));
	else if (line[0] == 'S' && line[1] == 'O' && ft_isspace(line[2]))
		return (ft_south(data, &line[2]));
	else if (line[0] == 'W' && line[1] == 'E' && ft_isspace(line[2]))
		return (ft_west(data, &line[2]));
	else if (line[0] == 'E' && line[1] == 'A' && ft_isspace(line[2]))
		return (ft_east(data, &line[2]));
	else if (line[0] == 'S' && ft_isspace(line[1]))
		return (ft_sprite(data, &line[1]));
	else if ((line[0] == 'F') && ft_isspace(line[1]))
		return (ft_color_ground(data, &line[1]));
	else if ((line[0] == 'C') && ft_isspace(line[1]))
		return (ft_color_sky(data, &line[1]));
	else if (line[0] != '1' && !ft_isspace(line[0]))
		ft_error_exit("Error\nA line is wrong.\nExit Program");
	if (data->parsed == 8)
	{
		data->first_token = el;
		return (ft_map(el, data, map, pos));
	}
	return (1);
}

int		ft_gnl(int fd, t_data *data, t_map *map, t_pos *pos)
{
	int		res;
	char	*line;
	t_list	*tmp;
	t_list	*each_line;

	res = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		tmp = ft_lstnew(line);
		if (!tmp)
			return (0);
		ft_lstadd_back(&data->lst_line, tmp);
		res = 1;
	}
	tmp = ft_lstnew(line);
	if (!tmp)
		return (0);
	ft_lstadd_back(&data->lst_line, tmp);
	each_line = data->lst_line;
	while (each_line)
	{
		ft_parsing_data(each_line, data, map, pos);
		each_line = each_line->next;
	}
	return (res);
}

int		ft_get_data(t_data *data, char *file, t_map *map, t_pos *pos)
{
	int		fd;
	int		res;

	res = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_exit("Error\nWrong File.\nExit Program");
	res = ft_gnl(fd, data, map, pos);
	close(fd);
	if (fd > 0 && res)
		return (1);
	else
		return (0);
}

t_data	*ft_data(char *file, int ac, t_map *map, t_pos *pos)
{
	t_data	*data;

	data = ft_calloc_2(sizeof(t_data));
	if (ac == 1)
		if ((data->mlx_ptr = mlx_init()) == NULL)
			return (0);
	if (!(ft_get_data(data, file, map, pos)))
		ft_free_data(data, "Error\nTask - parsing : Fail_2 !");
	// if (ac == 1)
	// 	ft_mlx_data(data);
	return (data);
}
