/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:30:41 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/16 17:26:13 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	main(int ac, char **av)
{
	t_general	general;

	if (ac == 3)
	{
		init_general(&general);
		general.object.obj = av[1];
		general.object.bmp = av[2];
		if (!init_glfw(&general) || !init_glew(&general)
			|| !create_shader_program(&general.shaders))
		{
			return (shutdown(&general));
		}
		launch_rendering(&general);
		shutdown(&general);
		glfwTerminate();
	}
	return (1);
}
