#pragma once

#include "RE/Bethesda/BSTSmartPointer.hpp"

namespace RE::BSScript
{
	class BoundScript; // stub

	class MergedBoundScript
	{
	public:
		// members
		BSTSmartPointer<BoundScript> childScript;  // 00
		BSTSmartPointer<BoundScript> parentScript; // 08
	};
	static_assert(sizeof(MergedBoundScript) == 0x10);
}
