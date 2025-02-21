#pragma once

#include "RE/Bethesda/BSFixedString.hpp"

namespace RE
{
	class NiAVObject;
}

namespace RE::BSUtilities
{
	inline std::uint16_t ConvertFloatToHalf(float a_value)
	{
		using func_t = decltype(&ConvertFloatToHalf);
		static REL::Relocation<func_t> func{ REL::RelocationID(10414, 2212098) };
		return func(a_value);
	}

	inline float ConvertHalfToFloat(std::uint16_t a_value)
	{
		using func_t = decltype(&ConvertHalfToFloat);
		static REL::Relocation<func_t> func{ REL::RelocationID(1502141, 2195843) };
		return func(a_value);
	}

	inline NiAVObject* GetObjectByName(NiAVObject* a_root, const BSFixedString& a_name, bool a_tryInternal, bool a_dontAttach)
	{
		using func_t = decltype(&GetObjectByName);
		static REL::Relocation<func_t> func{ REL::RelocationID(843650, 2274841) };
		return func(a_root, a_name, a_tryInternal, a_dontAttach);
	}
}
