/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:31:02 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/16 17:31:23 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H

# define SCOP_H

# include "libft.h"
# include "glew.h"
# include "glfw3.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "vectors.h"
# include "matrices.h"
# include "messages.h"

# define BUFF_CODE		1000000
# define SIZE_W			1080
# define SIZE_H			720
# define FOV			45

typedef struct	s_triagle
{
	t_vec3		position;
	t_vec2		uv;
}				t_triagle[3];

typedef struct	s_shader
{
	const GLchar	*code;
	GLuint			id;
}				t_shader;

typedef struct	s_shaders
{
	t_shader	vertex;
	t_shader	fragment;
	GLuint		program;
	int			change;
	float		red;
}				t_shaders;

typedef struct	s_glfw
{
	GLFWwindow	*window;
}				t_glfw;

typedef struct	s_texture
{
	GLuint			id;
	unsigned char	*image;
	unsigned int	size;
	unsigned int	width;
	unsigned int	height;
}				t_texture;

typedef struct	s_transform
{
	t_vec3		scale;
	t_vec3		rotate;
	t_vec3		position;
}				t_transform;

typedef struct	s_temp
{
	int		vertex_index;
	int		uv_index;
}				t_temp[3];

typedef struct	s_object
{
	char			*bmp;
	char			*obj;
	t_triagle		*triagle;
	int				triagle_count;
	t_vec3			*vertex;
	int				vertex_count;
	t_vec2			*uv;
	int				uv_count;
	t_transform		transform;
	GLuint			count;
	GLuint			vbo;
	GLuint			vao;
	t_texture		texture;
}				t_object;

typedef struct	s_camera
{
	t_vec3		rotate;
	t_vec3		position;
}				t_camera;

typedef struct	s_general
{
	t_glfw		*glfw;
	t_object	object;
	t_camera	camera;
	t_shaders	shaders;
}				t_general;

/*
** Transformations
*/

int				transformations(t_general *general, t_transform transform);
GLfloat			radians(float degrees);
GLfloat			degrees(float radians);

/*
**	Triagle
*/

void			triagle_position(t_triagle *triagle,
				t_vec3 point1, t_vec3 point2, t_vec3 point3);
void			triagle_uv(t_triagle *triagle,
				t_vec2 point1, t_vec2 point2, t_vec2 point3);

/*
** Initializations
*/

void			init_general(t_general *general);
int				init_glfw(t_general *general);
int				init_glew(t_general *general);

/*
** Objects
*/

int				create_object(t_object *object);

/*
** Update_center
*/

void			update_center(t_object *object);

/*
** Bmp
*/

int				read_bmp(const char *path, t_texture *texture);

/*
** Obj
*/

int				read_obj(t_object *object);

/*
** Shaders_program
*/

int				create_shader_program(t_shaders *shaders);

/*
** Shaders
*/

void			color_change(t_shaders *shaders);
int				create_shader(t_shader *shader, const char *path, int type);
int				create_shader_fragment(t_shader *shader);

/*
** Rendering
*/

void			launch_rendering(t_general *general);

/*
** Events
*/

int				processing_events(
				t_general *general, t_object *object, t_camera *camera);

/*
** Shutdown
*/

int				shutdown(t_general *general);

#endif
