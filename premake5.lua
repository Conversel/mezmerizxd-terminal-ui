workspace "mezmerizxd-terminal-ui"
  architecture "x64"
  startproject "mezmerizxd-terminal-ui"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

  outputdir = "%{cfg.buildcfg}"

  IncludeDir = {}
  
  CppVersion = "C++17"
  MsvcToolset = "v143"
  WindowsSdkVersion = "10.0"
  
  function DeclareMSVCOptions()
    filter "system:windows"
    staticruntime "Off"
    systemversion (WindowsSdkVersion)
    toolset (MsvcToolset)
    cppdialect (CppVersion)

    defines
    {
      "_CRT_SECURE_NO_WARNINGS",
      "NOMINMAX",
      "WIN32_LEAN_AND_MEAN",
      "_WIN32_WINNT=0x601" -- Support Windows 7
    }
    
    disablewarnings
    {
      "4100", -- C4100: unreferenced formal parameter
      "4201", -- C4201: nameless struct/union
      "4307"  -- C4307: integral constant overflow
    }
  end
   
  project "mezmerizxd-terminal-ui"
    location "mezmerizxd-terminal-ui"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

    PrecompiledHeaderInclude = "common.hpp"
    PrecompiledHeaderSource = "%{prj.name}/src/common.cpp"
 
    files
    {
      "%{prj.name}/src/**.hpp",
      "%{prj.name}/src/**.cpp",
      "%{prj.name}/src/**.asm"
    }

    includedirs
    {
      "%{prj.name}/src"
    }

    libdirs
    {
      "bin/lib"
    }
    
    DeclareMSVCOptions()

    configuration "Debug"
      symbols "On"
      defines { "_DEBUG" }

    configuration "Release"
      flags { "Optimize" }
      defines { "NDEBUG" }
