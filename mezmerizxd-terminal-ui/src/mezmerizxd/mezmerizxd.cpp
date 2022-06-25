#include "common.hpp"

namespace mezmerizxd {
	void mezmerizxd::Init() {
		using namespace terminal;

		switch (g_terminal.currentLevel)
		{
			case start:
			{
				g_terminal.ButtonOption("Test Button 1", []() {
					// Do something
					});
				g_terminal.ButtonOption("Test Button 2", []() {
					// Do something
					});
				g_terminal.LevelOption("Level 2", level2);
			} break;

			case level2:
			{
				g_terminal.ButtonOption("Option Button 1", []() {
					// Do something
					});
				g_terminal.ButtonOption("Option Button 2", []() {
					// Do something
					});
				g_terminal.LevelOption("Start", start);
			} break;
		}
	}

	void mezmerizxd::Update() {
		terminal::g_terminal.Controls();
		terminal::g_terminal.clearTerminal();
		g_mezmerizxd.Init();
	}
}