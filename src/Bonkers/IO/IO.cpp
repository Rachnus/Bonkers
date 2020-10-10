/*

https://github.com/Rachnus/
MIT License (MIT)
Copyright (c) 2020 Jimi Bertlin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "BONKERS_PCH.h"
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