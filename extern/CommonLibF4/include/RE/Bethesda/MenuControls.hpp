#pragma once

#include "RE/Bethesda/BSInputEventReceiver.hpp"
#include "RE/Bethesda/BSInputEventUser.hpp"
#include "RE/Bethesda/BSTArray.hpp"
#include "RE/Bethesda/BSTSingleton.hpp"

namespace RE
{
	class PipboyHandler;

	struct CameraZoomHandler;
	struct ClickHandler;
	struct GFxConvertHandler;
	struct MenuOpenHandler;
	struct QuickSaveLoadHandler;

	class MenuControls
		: public BSInputEventReceiver,		   // 00
		  public BSTSingletonSDM<MenuControls> // 10
	{
	public:
		[[nodiscard]] static MenuControls* GetSingleton()
		{
			static REL::Relocation<MenuControls**> singleton{ REL::RelocationID(520890, 2689089) };
			return *singleton;
		}

		bool QueueScreenshot() const
		{
			if (!screenshotHandler || screenshotHandler->screenshotQueued) {
				return false;
			}
			screenshotHandler->screenshotQueued = true;
			return true;
		}

		// members
		BSTArray<BSInputEventUser*> handlers;		// 18
		GFxConvertHandler* convertHandler;			// 30
		DisconnectHandler* disconnectHandler;		// 38
		ClickHandler* clickHandler;					// 40
		QuickSaveLoadHandler* quickSaveLoadHandler; // 48
		MenuOpenHandler* menuOpenHandler;			// 50
		ScreenshotHandler* screenshotHandler;		// 58
		CameraZoomHandler* cameraZoomHandler;		// 60
		PipboyHandler* pipboyHandler;				// 68
	};
	static_assert(sizeof(MenuControls) == 0x70);
}
