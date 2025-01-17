/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:47:39 by fmerding          #+#    #+#             */
/*   Updated: 2019/06/24 05:17:06 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_f	init(t_f *f)
{
	int i;

	i = -1;
	f->pos.x = 0;
	f->pos.y = 0;
	f->start.x = -1;
	f->start.y = -1;
	if (!(f->m = (char **)malloc(sizeof(char*) * f->sm_y)))
		ft_exit(f);
	while (++i < f->sm_y)
		f->m[i] = NULL;
	i = 0;
	while (i < f->sm_y)
	{
		f->m[i] = NULL;
		if (!(f->m[i] = (char *)malloc(sizeof(char) * f->sm_x + 1)))
			ft_exit(f);
		f->m[i][f->sm_x] = '\0';
		i++;
	}
	f->ppx = 1000 / f->sm_x;
	f->ppy = 1000 / f->sm_y;
	f->done = 1;
	return (*f);
}

t_f	re_init(t_f *f, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	f->sp_x = 0;
	f->sp_y = 0;
	f->sp_y = ft_getnbr_n(line, 6);
	tmp = ft_itoa(f->sp_y);
	f->sp_x = ft_getnbr_n(line, 7 + ft_strlen(tmp));
	free(tmp);
	if (!(f->p = (char **)malloc(sizeof(char*) * f->sp_y)))
		ft_exit(f);
	while (i < f->sp_y)
	{
		if (!(f->p[i] = (char *)malloc(sizeof(char) * f->sp_x + 1)))
			ft_exit(f);
		f->p[i][f->sp_x] = '\0';
		i++;
	}
	f->minpos.x = -f->sp_x + 1;
	f->minpos.y = -f->sp_y + 1;
	f->done = 2;
	return (*f);
}
