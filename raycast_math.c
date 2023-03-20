/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoller <mkoller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:10:54 by mkoller           #+#    #+#             */
/*   Updated: 2023/02/24 14:12:28 by mkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycast.h"

float	radconvert(float degree)
{
	float	rad;

	rad = degree * M_PI / 180;
	return (rad);
}

float	within_twopi(float rad)
{
	float	rad2;

	rad2 = rad;
	while (rad2 >= (2 * M_PI))
		rad2 -= 2 * M_PI;
	while (rad2 < 0)
		rad2 += 2 * M_PI;
	return (rad2);
}

float	get_distance(float x1, float y1, float x2, float y2)
{
	double	result;
	double	x;
	double	y;

	x = (x2 - x1) * (x2 - x1);
	y = (y2 - y1) * (y2 - y1);
	result = sqrt(x + y);
	return ((float)result);
}

unsigned int	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
