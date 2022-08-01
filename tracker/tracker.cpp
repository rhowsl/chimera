#include "tracker.h"

chimera::tracker::tracker()
{
	// test values
	this->ticks_per_second = 720;
	this->current_bpm = 165;
	this->current_time_sig = std::make_pair(4, 4);
}

chimera::tracker::~tracker()
{

}

void chimera::tracker::trigger_tick()
{
	if (std::fmod(std::round(this->ticks_ran), std::round(this->ticks_per_beat() / this->current_time_sig.second)) == 0)
	{
		this->row_position++;
		std::cout << "row: " << this->row_position << "; tick: " << this->ticks_ran << std::endl;
	}
}

void chimera::tracker::play()
{
	this->playing = true;
	while (this->playing)
	{
		if (!this->step())
			return;
	}
}

void chimera::tracker::stop()
{
	this->playing = false;
	this->ticks_ran = 0;
}

bool chimera::tracker::step()
{
	if (!this->playing)
		return false;

	this->preflight();

	std::chrono::steady_clock pclock;

	const double secs_per_tick = 1 / (double)this->ticks_per_second;
	auto initial_time = pclock.now();
	auto last_tick = pclock.now();

	while (true)
	{
		// trigger tick
		const auto now_seconds = PRECISION_SEC_CONVERT(pclock.now(), initial_time);
		const auto since_last_tick = PRECISION_SEC_CONVERT(pclock.now(), last_tick);

		if (since_last_tick > secs_per_tick)
		{
			this->ticks_ran += now_seconds / secs_per_tick;
			this->trigger_tick();

			last_tick = pclock.now();
			return true;
		}
	}
}

double chimera::tracker::ticks_per_beat() const
{
	return 
		(60.0 / (double)this->current_bpm) /
		(1.0 / (double)this->ticks_per_second);
}

void chimera::tracker::preflight()
{
	if (this->ticks_per_second < 10)
		throw std::logic_error("ticks per second too low");

	if (this->current_time_sig.first < 1 || this->current_time_sig.second < 1)
		throw std::logic_error("invalid time sig");
}
