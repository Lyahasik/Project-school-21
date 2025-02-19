#include "processor.h"

#include "engine/main/core/object/object_manipulator/object_manipulator.h"
#include "engine/main/core/object/object_storage/object_storage/object_storage.h"
#include "engine/main/system/window/window/window.h"
#include "engine/main/system/input/input.h"
#include "engine/main/system/time/timer/timer.h"
#include "engine/main/rendering/layout/layout/layout.h"
#include "engine/main/rendering/layout/layout_manager/layout_manager.h"
#include "engine/main/processor/processor_settings.h"

using namespace	engine;

void			processor::execute()
{
	do
	{
		process_input();
		process_activation();
		process_updating();
		process_rendering();
	}
	while (not window::is_closed());

	object_storage::clean();
}

void			processor::process_input()
{
	static bool	empty_polygons = false;

	input::reset_keys();
	input::update_mouse();

	glfwPollEvents();

	if (input::is_pressed(input::key::escape))
		window::close();
	if (input::is_pressed(input::key::letter_p))
	{
		empty_polygons = not empty_polygons;
		glPolygonMode(GL_FRONT_AND_BACK, empty_polygons ? GL_LINE : GL_FILL);
	}
}

void			processor::process_activation()
{
	for (const auto &layout : layout_manager::get_layouts())
	for (auto &object : layout->get_objects())
	{
		if (object->get_state() == object::state::initialized)
			object->activate();
	}
}

void			processor::process_updating()
{
	for (const auto &layout : layout_manager::get_layouts())
	for (auto &object : layout->get_objects())
	{
		if (object->get_state() == object::state::activated)
			object->update();
	}
}

void			processor::process_rendering()
{
	window::clear(processor_settings::background);

	for (const auto &layout : layout_manager::get_layouts())
	{
		layout->apply_options();

		for (auto &object : layout->get_objects())
		{
			if (object->get_state() == object::state::activated)
				object->render();
		}
	}

	window::swap_buffers();
}