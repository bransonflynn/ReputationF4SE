#pragma once

#include "RE/Bethesda/BSSystemFile.hpp"
#include "RE/NetImmerse/NiBinaryStream.hpp"

namespace RE
{
	class __declspec(novtable) NiMemStream
		: public NiBinaryStream // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::NiMemStream };
		inline static constexpr auto VTABLE{ VTABLE::NiMemStream };

		enum class OpenMode;

		// members
		void* buffer;				 // 10
		std::size_t pos;			 // 18
		std::size_t bufferAllocSize; // 20
		std::size_t currentFilePos;	 // 28
		bool good;					 // 30
	};
	static_assert(sizeof(NiMemStream) == 0x38);
}
