#pragma once

#include "RE/Bethesda/PipboyArray.hpp"
#include "RE/Bethesda/PipboyDataGroup.hpp"

namespace RE
{
	namespace RadioManager
	{
		struct PipboyFrequencyDetectionEvent;
		struct PipboyRadioTuningEvent;
	}

	class __declspec(novtable) PipboyRadioData
		: public PipboyDataGroup,											// 00
		  public BSTEventSink<RadioManager::PipboyFrequencyDetectionEvent>, // 98
		  public BSTEventSink<RadioManager::PipboyRadioTuningEvent>			// A0
	{
	public:
		inline static constexpr auto RTTI{ RTTI::PipboyRadioData };
		inline static constexpr auto VTABLE{ VTABLE::PipboyRadioData };

		virtual ~PipboyRadioData() = default;

		virtual BSEventNotifyControl ProcessEvent(const RadioManager::PipboyFrequencyDetectionEvent& a_event, BSTEventSource<RadioManager::PipboyFrequencyDetectionEvent>* a_source); // 01
		virtual BSEventNotifyControl ProcessEvent(const RadioManager::PipboyRadioTuningEvent& a_event, BSTEventSource<RadioManager::PipboyRadioTuningEvent>* a_source);				  // 02

		virtual void Populate(bool a_arg1) override; // 03
		virtual void DoClearData() override;		 // 04
		virtual void DoClearSink() override;		 // 05

		// members
		PipboyArray* radioStations; // A8
	};
	static_assert(sizeof(PipboyRadioData) == 0xB0);
}
