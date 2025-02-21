#pragma once

#include "RE/Bethesda/BSTHashMap.hpp"
#include "RE/Bethesda/PipboyDataGroup.hpp"

namespace RE
{
	class __declspec(novtable) PipboyMapData
		: public PipboyDataGroup,										// 00
		  public BSTEventSink<TravelMarkerStateChange::Event>,			// 98
		  public BSTEventSink<PlayerUpdateEvent>,						// A0
		  public BSTEventSink<BGSActorCellEvent>,						// A8
		  public BSTEventSink<TESQuestEvent::Event>,					// B0
		  public BSTEventSink<PlayerCharacterQuestEvent::Event>,		// B8
		  public BSTEventSink<CustomMarkerUpdate::Event>,				// C0
		  public BSTEventSink<LocationMarkerArrayUpdate::Event>,		// C8
		  public BSTEventSink<LocalMapCameraUpdate::Event>,				// D0
		  public BSTEventSink<TESLocationClearedEvent>,					// D8
		  public BSTEventSink<ActorValueEvents::ActorValueChangedEvent> // E0
	{
	public:
		inline static constexpr auto RTTI{ RTTI::PipboyMapData };
		inline static constexpr auto VTABLE{ VTABLE::PipboyMapData };

		virtual ~PipboyMapData() = default;

		virtual BSEventNotifyControl ProcessEvent(const TravelMarkerStateChange::Event& a_event, BSTEventSource<TravelMarkerStateChange::Event>* a_source);						// 01
		virtual BSEventNotifyControl ProcessEvent(const PlayerUpdateEvent& a_event, BSTEventSource<PlayerUpdateEvent>* a_source);												// 02
		virtual BSEventNotifyControl ProcessEvent(const BGSActorCellEvent& a_event, BSTEventSource<BGSActorCellEvent>* a_source);												// 03
		virtual BSEventNotifyControl ProcessEvent(const TESQuestEvent::Event& a_event, BSTEventSource<TESQuestEvent::Event>* a_source);											// 04
		virtual BSEventNotifyControl ProcessEvent(const PlayerCharacterQuestEvent::Event& a_event, BSTEventSource<PlayerCharacterQuestEvent::Event>* a_source);					// 05
		virtual BSEventNotifyControl ProcessEvent(const CustomMarkerUpdate::Event& a_event, BSTEventSource<CustomMarkerUpdate::Event>* a_source);								// 06
		virtual BSEventNotifyControl ProcessEvent(const LocationMarkerArrayUpdate::Event& a_event, BSTEventSource<LocationMarkerArrayUpdate::Event>* a_source);					// 07
		virtual BSEventNotifyControl ProcessEvent(const LocalMapCameraUpdate::Event& a_event, BSTEventSource<LocalMapCameraUpdate::Event>* a_source);							// 08
		virtual BSEventNotifyControl ProcessEvent(const TESLocationClearedEvent& a_event, BSTEventSource<TESLocationClearedEvent>* a_source);									// 09
		virtual BSEventNotifyControl ProcessEvent(const ActorValueEvents::ActorValueChangedEvent& a_event, BSTEventSource<ActorValueEvents::ActorValueChangedEvent>* a_source); // 0A

		// override
		virtual void Populate(bool a_arg1) override; // 0B
		virtual void DoClearData() override;		 // 0C
		virtual void DoClearSink() override;		 // 0D

		// members
		PipboyObject* mapObject;																							// E8
		BSTHashMap<const MapMarkerData*, PipboyObject*> travelLocationsMarkers;												// F0
		BSTHashMap<std::uint32_t, BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21, 5>>> travelLocationRefrHandles; // 120
		BSTArray<PipboyObject*> doorMarkers;																				// 150
		BSTArray<BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21, 5>>> doorRefHandles;								// 168
		BSTHashMap<BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21, 5>>, PipboyObject*> localQuestMarkers;			// 180
		BSTHashMap<BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21, 5>>, PipboyObject*> worldQuestMarkers;			// 1B0
		NiPoint3 playerLastLocationPosition;																				// 1E0
		NiPoint3 playerLastWorldPosition;																					// 1EC
		PipboyObject* localPlayerMarker;																					// 1F8
		PipboyObject* worldPlayerMarker;																					// 200
		PipboyObject* localCustomMarker;																					// 208
		PipboyObject* worldCustomMarker;																					// 210
		PipboyObject* localPowerArmorMarker;																				// 218
		PipboyObject* worldPowerArmorMarker;																				// 220
		PipboyObject* worldMapExtents;																						// 230
		PipboyObject* localMapExtents;																						// 238
	};
	static_assert(sizeof(PipboyMapData) == 0x238);
}
