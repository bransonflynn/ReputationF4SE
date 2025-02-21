#include "RE/Bethesda/CRC.hpp"

#include "RE/Bethesda/BGSInventoryInterface.hpp"

namespace RE
{
	std::uint32_t BSCRC32<InventoryInterface::Handle>::operator()(InventoryInterface::Handle a_data) const noexcept
	{
		return BSCRC32<std::uint32_t>()(a_data.id);
	}
}
