#pragma once

#include "RE/Bethesda/BSTHashMap.hpp"
#include "RE/Bethesda/BSTSingleton.hpp"
#include "RE/Bethesda/InputDevice.hpp"

namespace RE
{
	class __declspec(novtable) BSInputDevice
	{
	public:
		inline static constexpr auto RTTI{ RTTI::BSInputDevice };
		inline static constexpr auto VTABLE{ VTABLE::BSInputDevice };

		struct InputButton
		{
		public:
			// members
			BSFixedStringCS name;  // 00
			float heldDownSecs;	   // 08
			std::uint32_t keyCode; // 0C
		};
		static_assert(sizeof(InputButton) == 0x10);

		// add
		virtual void Initialize() = 0;					  // 00
		virtual void Poll(float a_pollDelta) = 0;		  // 01
		virtual void Shutdown() = 0;					  // 02
		virtual bool IsConnected() const { return true; } // 03
		virtual ~BSInputDevice();						  // 04
		virtual void ClearInputState() = 0;				  // 05

		// members
		REX::Enum<INPUT_DEVICE, std::int32_t> deviceType;			// 08
		std::int32_t deviceID;										// 0C
		BSTHashMap<std::uint32_t, InputButton*> deviceButtons;		// 10
		BSTHashMap<BSFixedStringCS, std::uint32_t> buttonNameIDMap; // 40
	};
	static_assert(sizeof(BSInputDevice) == 0x70);

	class BSInputDeviceManager
		: public BSTSingletonSDM<BSInputDeviceManager> // 00
	{
	public:
		enum class BS_DEVICES
		{
			kKeyboard,
			kMouse,
			kGamepad,
			kDebugGamepad,
			kVirtualKeyboard,

			kTotal
		};

		[[nodiscard]] static BSInputDeviceManager* GetSingleton()
		{
			static REL::Relocation<BSInputDeviceManager**> singleton{ REL::ID(1284221) };
			return *singleton;
		}

		[[nodiscard]] BSInputDevice* GetGamepad() const noexcept
		{
			return devices[std::to_underlying(INPUT_DEVICE::kGamepad)];
		}

		[[nodiscard]] bool IsGamepadConnected() const
		{
			const auto gamepad = GetGamepad();
			return gamepad && gamepad->IsConnected();
		}

		// members
		BSInputDevice* devices[std::to_underlying(INPUT_DEVICE::kTotal)]; // 08
		bool deviceLightStates[3];										  // 30
		bool queuedGamepadEnableValue;									  // 33
		bool valueQueued;												  // 34
		bool pollingEnabled;											  // 35
	};
	static_assert(sizeof(BSInputDeviceManager) == 0x38);
}
