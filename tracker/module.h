#pragma once

#include <string>
#include <map>
#include <vector>
#include <math.h>

namespace chimera
{
	class event
	{
		public:
			typedef enum
			{
				note_on,
				note_off,
				note_release
			} event_type;

			unsigned char note;
			unsigned char instrument;

			event();
			~event();
	};

	class row
	{
		private:
			chimera::event p_event;

		public:
			row();
			~row();
	};

	class pattern
	{
		private:
			std::vector<row> rows;

		public:
			pattern();
			~pattern();
	};

	class channel
	{
		public:
			channel();
			~channel();
	};

	class module
	{
		private:
			// Basic module properties
			unsigned int p_ticks_per_row;
			unsigned int p_bpm;
			unsigned int p_max_pattern_len;
			unsigned int p_speed;

			// Pattern map
			std::map<std::string, chimera::pattern> p_patterns;
			std::map<std::string, chimera::channel> p_channels;

		public:
			module();
			~module();
	};
}
