#ifndef BONKERS_IO_H
#define BONKERS_IO_H

#include "PCH.h"

namespace Bonkers
{
	namespace IO
	{
		class File
		{
		public:
			static bool ReadRaw(const std::string& path, std::string* out, size_t start = 0, size_t end = 0);
			static bool ReadText(const std::string& path, std::string* out);
		};
		
	}
}

#endif // BONKERS_IO_H