/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:11:03 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/16 16:13:59 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	setting_viewport(t_general *general)
{
	int	width;
	int	height;

	glfwGetFramebufferSize(general->glfw->window, &width, &height);
	glViewport(0, 0, width, height);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	general->camera.position = vec3(0.0f, 0.0f, 10.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

void	launch_rendering(t_general *general)
{
	setting_viewport(general);
	if (!create_object(&general->object))
		return ;
	while (processing_events(general, &general->object, &general->camera))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (!(transformations(general, general->object.transform)))
			break ;
		color_change(&general->shaders);
		glUseProgram(general->shaders.program);
		glBindVertexArray(general->object.vao);
		glDrawArrays(GL_TRIANGLES, 0, general->object.triagle_count * 3);
		glBindVertexArray(0);
		glfwSwapBuffers(general->glfw->window);
	}
}
