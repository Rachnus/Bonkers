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
#include "XML.h"

namespace Bonkers
{
	namespace Format
	{
		namespace XML
		{
			XMLDocument* ToXML(const String& xml)
			{
				XMLDocument* doc = new XMLDocument();
				int error = 0;
				if ((error = doc->Parse(xml.c_str())) != XML_SUCCESS)
				{
					printf("Could not load XML - Error: %d\n", error);
					assert(false);
					// Error
					return nullptr;
				}

				return doc;
			}

			std::string ToString(const XMLDocument& xml)
			{
				XMLPrinter print;
				xml.Print(&print);
				return print.CStr();
			}
		}
	}
}
