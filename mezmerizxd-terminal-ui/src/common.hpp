#pragma once

#include <Windows.h>

#include <chrono>

// #include <filesystem>
// #include <fstream>
#include <iostream>

#include <atomic>
// #include <mutex>
#include <thread>

// #include <sstream>
// #include <string>
// #include <string_view>

#include "terminal/terminal.hpp"
#include "mezmerizxd/mezmerizxd.hpp"

namespace mezmerizxd {
	using namespace std::chrono_literals;
	inline std::atomic_bool g_running{ true };
}