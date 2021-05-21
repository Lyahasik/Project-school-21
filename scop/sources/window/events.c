/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:10:39 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/16 17:50:57 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	settings_face(t_general *general)
{
	if (glfwGetKey(general->glfw->window, GLFW_KEY_R) == GLFW_PRESS)
		glCullFace(GL_FRONT);
	if (glfwGetKey(general->glfw->window, GLFW_KEY_T) == GLFW_PRESS)
		glCullFace(GL_BACK);
	if (glfwGetKey(general->glfw->window, GLFW_KEY_C) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (glfwGetKey(general->glfw->window, GLFW_KEY_V) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (glfwGetKey(general->glfw->window, GLFW_KEY_B) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
}

int		processing_events(t_general *general,
							t_object *object,
							t_camera *camera)
{
	if (glfwGetKey(general->glfw->window, GLFW_KEY_ESCAPE) == GLFW_PRESS
		|| glfwWindowShouldClose(general->glfw->window) != GLFW_FALSE)
		return (0);
	if (glfwGetKey(general->glfw->window, GLFW_KEY_Q) == GLFW_PRESS)
		camera->position.x += 0.05f;
	if (glfwGetKey(general->glfw->window, GLFW_KEY_A) == GLFW_PRESS)
		camera->position.x -= 0.05f;
	if (glfwGetKey(general->glfw->window, GLFW_KEY_W) == GLFW_PRESS)
		camera->position.y += 0.05f;
	if (glfwGetKey(general->glfw->window, GLFW_KEY_S) == GLFW_PRESS)
		camera->position.y -= 0.05f;
	if (glfwGetKey(general->glfw->window, GLFW_KEY_E) == GLFW_PRESS)
		camera->position.z += 0.05f;
	if (glfwGetKey(general->glfw->window, GLFW_KEY_D) == GLFW_PRESS)
		camera->position.z -= 0.05f;
	if (glfwGetKey(general->glfw->window, GLFW_KEY_Z) == GLFW_PRESS)
		general->shaders.change = 0;
	if (glfwGetKey(general->glfw->window, GLFW_KEY_X) == GLFW_PRESS)
		general->shaders.change = 1;
	settings_face(general);
	return (1);
}
