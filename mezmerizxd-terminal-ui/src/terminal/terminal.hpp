namespace mezmerizxd::terminal {
	class Terminal
	{
	public:
		int currentLevel = 0;

		int optionCount = 0;
		int selectedOption = 1;
		bool selectedPressed = false;

		bool ButtonOption(const char* buttonName, void task());
		void LevelOption(const char* levelName, int level);
		void Controls();

		int setLevel(int level);
		void clearTerminal();
	private:

	};

	inline Terminal g_terminal;
}