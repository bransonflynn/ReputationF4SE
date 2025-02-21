#pragma once

#include "RE/Havok/hkBaseObject.hpp"
#include "RE/Havok/hkSimdFloat.hpp"

namespace RE
{
	struct hknpCollisionResult;

	class __declspec(novtable) hknpCollisionQueryCollector
		: public hkBaseObject // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::hknpCollisionQueryCollector };
		inline static constexpr auto VTABLE{ VTABLE::hknpCollisionQueryCollector };

		// add
		virtual void Reset() = 0;								   // 01
		virtual void AddHit(const hknpCollisionResult& a_hit) = 0; // 02
		virtual bool HasHit() const = 0;						   // 03
		virtual std::int32_t GetNumHits() const = 0;			   // 04
		virtual const hknpCollisionResult* GetHits() const = 0;	   // 05

		// members
		std::int32_t hints;				 // 08
		hkSimdFloat32 earlyOutThreshold; // 10
	};
	static_assert(sizeof(hknpCollisionQueryCollector) == 0x20);
}
