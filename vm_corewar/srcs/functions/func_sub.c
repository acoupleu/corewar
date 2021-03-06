/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:03:03 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/24 01:26:43 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	substraction(t_map *map, t_process *proc)
{
	int		pos;

	if (proc->do_funk == 1)
		do_funk(proc, 8, 5, 0);
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		if (!is_reg((int)ARENA[(pos + 2) % MEM_SIZE], proc, 5) ||
			!is_reg((int)ARENA[(pos + 3) % MEM_SIZE], proc, 5) ||
			!is_reg((int)ARENA[(pos + 4) % MEM_SIZE], proc, 5))
			return ;
		else
		{
			proc->reg[ARENA[(pos + 4) % MEM_SIZE] - 1] =
			proc->reg[ARENA[(pos + 2) % MEM_SIZE] - 1] -
			proc->reg[ARENA[(pos + 3) % MEM_SIZE] - 1];
			proc->carry = !proc->reg[ARENA[(pos + 4) % MEM_SIZE] - 1];
			proc->pc = proc->pc + 5;
		}
	}
}
