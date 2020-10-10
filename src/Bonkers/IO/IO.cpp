#include "PCH.h"
#include "IO.h"

namespace Bonkers
{
	namespace IO
	{
		bool File::ReadRaw(const std::string& path, std::string* out, size_t start, size_t end)
		{
			std::ios_base::openmode mode = std::ios::binary;
			if (end == 0)
				mode |= std::ios::ate;

			std::ifstream inFile(path, mode);
			if (!inFile.is_open())
				return false;

			size_t length;
			if (end == 0)
				length = (size_t)inFile.tellg() - start;
			else
				length = end - start;
			inFile.seekg(start);

			out->resize(length);
			inFile.read(&(*out)[0], length);

			inFile.close();
			return true;
		}

		bool File::ReadText(const std::string& path, std::string* out)
		{
			std::ifstream inFile(path);
			if (!inFile.is_open())
				return false;

			inFile.seekg(0, std::ios::end);
			out->reserve((size_t)inFile.tellg());
			inFile.seekg(0, std::ios::beg);
			out->assign((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

			inFile.close();
			return true;
		}
	}
}