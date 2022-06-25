#include "common.hpp"

namespace mezmerizxd::terminal {
	bool Terminal::ButtonOption(const char* buttonName, void task()) {
		optionCount++;
		bool onThis = selectedOption == optionCount ? true : false;
		onThis ? std::cout << "> " << buttonName << std::endl : std::cout << buttonName << std::endl;
		if (selectedOption == optionCount) {
			if (selectedPressed == true) {
				selectedPressed = false;
				task();
				return true;
			}
		}
		return false;
	}

	void Terminal::LevelOption(const char* levelName, int level) {
		optionCount++;
		bool onThis = selectedOption == optionCount ? true : false;
		onThis ? std::cout << "> " << levelName << " --->" << std::endl : std::cout << levelName << " --->" << std::endl;
		if (selectedOption == optionCount) {
			if (selectedPressed == true) {
				selectedPressed = false;
				setLevel(level);
			}
		}
	}

	void Terminal::Controls() {
		if (GetAsyncKeyState(VK_DOWN)) {
			if (selectedOption + 1 > optionCount) {
				// Set back to the top
				g_terminal.selectedOption = 1;
			}
			else {
				g_terminal.selectedOption += 1;
			}
		}

		if (GetAsyncKeyState(VK_UP)) {
			if (selectedOption - 1 == 0) {
				// Set to the bottom
				g_terminal.selectedOption = optionCount;
			}
			else {
				g_terminal.selectedOption -= 1;
			}
		}

		if (GetAsyncKeyState(VK_RIGHT)) {
			g_terminal.selectedPressed = true;
		}
	}

	int Terminal::setLevel(int level) {
		selectedOption = 1;
		currentLevel = level;
		return currentLevel;
	}

	void Terminal::clearTerminal() {
#if defined _WIN32
		system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");
#elif defined (__APPLE__)
		system("clear");
#endif
		g_terminal.optionCount = 0;
	}
}