namespace mezmerizxd {
	class mezmerizxd
	{
	public:
		bool test1Selected = false;

		enum TerminalLevels {
			start,
			level2
		};

		void Init();
		void Update();
	private:
	};

	inline mezmerizxd g_mezmerizxd;
}