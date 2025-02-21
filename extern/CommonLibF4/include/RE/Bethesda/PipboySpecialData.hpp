#pragma once

#include "RE/Bethesda/PipboyArray.hpp"
#include "RE/Bethesda/PipboyDataGroup.hpp"

namespace RE
{
	class __declspec(novtable) PipboySpecialData
		: public PipboyDataGroup,										// 00
		  public BSTEventSink<ActorValueEvents::ActorValueChangedEvent> // 98
	{
	public:
		inline static constexpr auto RTTI{ RTTI::PipboySpecialData };
		inline static constexpr auto VTABLE{ VTABLE::PipboySpecialData };

		virtual ~PipboySpecialData();

		// override
		virtual void Populate(bool a_arg1) override; // 01
		virtual void DoClearData() override;		 // 02
		virtual void DoClearSink() override;		 // 03

		// add
		virtual BSEventNotifyControl ProcessEvent(const ActorValueEvents::ActorValueChangedEvent& a_event, BSTEventSource<ActorValueEvents::ActorValueChangedEvent>* a_source); // 04

		// members
		PipboyArray* specialsArray; // A0
	};
	static_assert(sizeof(PipboySpecialData) == 0xA8);
}
