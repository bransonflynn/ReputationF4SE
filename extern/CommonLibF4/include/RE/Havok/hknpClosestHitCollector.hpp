#pragma once

#include "RE/Havok/hkArray.hpp"
#include "RE/Havok/hknpCollisionQueryCollector.hpp"
#include "RE/Havok/hknpCollisionResult.hpp"

namespace RE
{
	class __declspec(novtable) hknpClosestHitCollector
		: public hknpCollisionQueryCollector // 000
	{
	public:
		inline static constexpr auto RTTI{ RTTI::hknpClosestHitCollector };
		inline static constexpr auto VTABLE{ VTABLE::hknpClosestHitCollector };

		hknpClosestHitCollector()
		{
			typedef hknpClosestHitCollector* func_t(hknpClosestHitCollector*);
			static REL::Relocation<func_t> func{ REL::ID(951692), 0x10 };
			func(this);
		}

		// override (hknpCollisionQueryCollector)
		void Reset() override;								 // 01
		void AddHit(const hknpCollisionResult&) override;	 // 02
		bool HasHit() const override;						 // 03
		std::int32_t GetNumHits() const override;			 // 04
		const hknpCollisionResult* GetHits() const override; // 05

		// members
		hknpCollisionResult result; // 20
		bool hasHit;				// 80
	};
	static_assert(sizeof(hknpClosestHitCollector) == 0x90);
}
