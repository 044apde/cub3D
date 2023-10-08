/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_render_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:05:59 by shikim            #+#    #+#             */
/*   Updated: 2023/10/08 15:11:05 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_texture_set(t_texture_set *texture_set)
{
	free(texture_set->n_texture->data);
	free(texture_set->n_texture);
	free(texture_set->e_texture->data);
	free(texture_set->e_texture);
	free(texture_set->w_texture->data);
	free(texture_set->w_texture);
	free(texture_set->s_texture->data);
	free(texture_set->s_texture);
}

void	free_render_memory(t_render	*render)
{
	free(render->player);
	free(render->window->win);
	free(render->window->mlx);
	free(render->window);
	free_texture_set(render->texture_set);
	free(render->texture_set);
	return ;
}
