#pragma once

#include "RE/Bethesda/Atomic.hpp"
#include "RE/Bethesda/BSLock.hpp"
#include "RE/Bethesda/BSTArray.hpp"
#include "RE/Bethesda/BSTHashMap.hpp"
#include "RE/Bethesda/BSTSingleton.hpp"
#include "RE/Bethesda/BSTSmartPointer.hpp"

namespace RE
{
	class AlchemyItem;
	class MagicItem;
	class TESForm;

	class BGSCreatedObjectManager
		: public BSTSingletonSDM<BGSCreatedObjectManager> // 00
	{
	public:
		template <class T>
		struct BSTCreatedObjectSmartPointerPolicy
		{
		public:
			static void Acquire(stl::not_null<T*> a_ptr)
			{
				const auto manager = BGSCreatedObjectManager::GetSingleton();
				if (manager &&
					a_ptr->IsCreated() &&
					a_ptr->IsAlchemyItem()) {
					manager->IncrementRef(static_cast<AlchemyItem*>(a_ptr));
				}
			}

			static void Release(stl::not_null<T*> a_ptr)
			{
				const auto manager = BGSCreatedObjectManager::GetSingleton();
				if (manager &&
					a_ptr->IsCreated() &&
					a_ptr->IsAlchemyItem()) {
					manager->DecrementRef(static_cast<AlchemyItem*>(a_ptr));
				}
			}
		};

		struct CreatedMagicItemData
		{
		public:
			// members
			MagicItem* createdItem; // 00
			std::uint32_t count;	// 08
		};
		static_assert(sizeof(CreatedMagicItemData) == 0x10);

		[[nodiscard]] static BGSCreatedObjectManager* GetSingleton()
		{
			static REL::Relocation<BGSCreatedObjectManager**> singleton{ REL::ID(1000678) };
			return *singleton;
		}

		void DecrementRef(AlchemyItem* a_alchItem)
		{
			using func_t = decltype(&BGSCreatedObjectManager::DecrementRef);
			static REL::Relocation<func_t> func{ REL::ID(230928) };
			return func(this, a_alchItem);
		}

		void IncrementRef(AlchemyItem* a_alchItem)
		{
			using func_t = decltype(&BGSCreatedObjectManager::IncrementRef);
			static REL::Relocation<func_t> func{ REL::ID(1042515) };
			return func(this, a_alchItem);
		}

		// members
		BSTArray<CreatedMagicItemData> weaponEnchantments;		 // 08
		BSTArray<CreatedMagicItemData> armorEnchantments;		 // 20
		BSTHashMap<std::uint32_t, CreatedMagicItemData> potions; // 38
		BSTHashMap<std::uint32_t, CreatedMagicItemData> poisons; // 68
		BSTSet<MagicItem*> queuedDeleteMagicItems;				 // 98
		mutable BSSpinLock dataLock;							 // C8
	};
	static_assert(sizeof(BGSCreatedObjectManager) == 0xD0);

	extern template struct BGSCreatedObjectManager::BSTCreatedObjectSmartPointerPolicy<AlchemyItem>;
	extern template struct BGSCreatedObjectManager::BSTCreatedObjectSmartPointerPolicy<TESForm>;

	template <class T>
	using CreatedObjPtr = BSTSmartPointer<T, BGSCreatedObjectManager::BSTCreatedObjectSmartPointerPolicy>;
}
