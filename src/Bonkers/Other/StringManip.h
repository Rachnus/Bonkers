#ifndef BONKERS_STRING_MANIP_H
#define BONKERS_STRING_MANIP_H

#include "BONKERS_PCH.h"

namespace Bonkers
{
	namespace StringManip
	{
		static bool Replace(std::string& buffer, const std::string& find, const std::string& replace)
		{
			size_t startPos = buffer.find(find);
			if (startPos == std::string::npos)
				return false;

			buffer.replace(startPos, find.length(), replace);
			return true;
		}

		static void ReplaceAll(std::string& buffer, const std::string& find, const std::string& replace)
		{
			size_t startPos = 0;
			while ((startPos = buffer.find(find, startPos)) != std::string::npos)
			{
				buffer.replace(startPos, find.length(), replace);
				startPos += replace.length();
			}
		}
	}
}

#endif // BONKERS_STRING_MANIP_H