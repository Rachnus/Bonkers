#ifndef BONKERS_TIME_H
#define BONKERS_TIME_H

#include "BONKERS_PCH.h"

namespace Bonkers
{
	class Timer
	{
	public:
		Timer()
		{
			Start();
		}

		inline void Start() { m_flStart = std::chrono::high_resolution_clock::now(); }

		// Returns milliseconds
		inline float GetMilliseconds() { return (m_flDuration = std::chrono::high_resolution_clock::now() - m_flStart).count() * 1000.0f; }
		inline float GetSeconds() { return (m_flDuration = std::chrono::high_resolution_clock::now() - m_flStart).count(); }

		std::chrono::duration<float> m_flDuration;
		std::chrono::time_point<std::chrono::steady_clock> m_flStart;
	};
}

#endif // BONKERS_TIME_H