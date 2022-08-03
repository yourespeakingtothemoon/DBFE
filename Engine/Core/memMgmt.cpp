#include "memMgmt.h"

namespace dbf
{
	void initalizeMemory()
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	}
}
