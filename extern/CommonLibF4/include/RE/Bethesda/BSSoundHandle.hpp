#pragma once

namespace RE
{
	class BSSoundHandle
	{
	public:
		~BSSoundHandle() noexcept {} // NOLINT(modernize-use-equals-default)

		bool FadeInPlay(std::uint16_t a_milliseconds)
		{
			using func_t = decltype(&BSSoundHandle::FadeInPlay);
			static REL::Relocation<func_t> func{ REL::RelocationID(353528, 2267075) };
			return func(this, a_milliseconds);
		}

		bool FadeOutAndRelease(std::uint16_t a_milliseconds)
		{
			using func_t = decltype(&BSSoundHandle::FadeOutAndRelease);
			static REL::Relocation<func_t> func{ REL::RelocationID(260328, 2267076) };
			return func(this, a_milliseconds);
		}

		// members
		std::uint32_t soundID; // 00
		bool assumeSuccess;	   // 04
		std::int8_t state;	   // 05
	};
	static_assert(sizeof(BSSoundHandle) == 0x8);
}
