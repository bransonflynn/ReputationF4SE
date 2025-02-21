#include "RE/Bethesda/Calendar.hpp"

#include "RE/Bethesda/TESForms.hpp"

namespace RE
{
	float Calendar::GetHoursPassed() const noexcept
	{
		const auto days = gameDaysPassed ? gameDaysPassed->GetValue() : 1.0F;
		return days * 24.0F;
	}

	std::uint32_t Calendar::GetMonth() const noexcept
	{
		return gameMonth ? static_cast<std::uint32_t>(gameMonth->value) : 8;
	}
}
