#pragma once

#include <iostream>
#include <chrono>
#include <math.h>
#include <utility>
#include <exception>
#include <type_traits>
#include "module.h"

#define PRECISION_SEC_CONVERT(x, y) \
	(double)std::chrono::duration_cast<std::chrono::nanoseconds>(x - y).count() / 1000000000.0;
		
namespace chimera
{
	class tracker
	{
		private:
			// Playhead
			bool playing;
			double ticks_ran;
			double current_bpm;
			std::pair<unsigned int, unsigned int> current_time_sig;
			unsigned int row_position;
			// Set by the module that is playing
			unsigned int ticks_per_second;
			chimera::module current_module;

		public:
			tracker();
			~tracker();
			void play();
			bool step();
			void load_module(chimera::module* module_ptr);
			void stop();

		private:
			void preflight();
			void trigger_tick();
			double ticks_per_beat() const;
	};
}
