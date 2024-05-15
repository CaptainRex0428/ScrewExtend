project "ScrewSandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    files
    {
        "src/**.cpp","include/**.h"
    }

    includedirs
    {
        "include",
        "%{ProjIncludeDir.ScrewExtend}",
        "%{DepIncludeDir.spdlog}"
    }

    links
    {
        "ScrewExtend",
        "spdlog"
    }

    defines
	{
	}

    flags
    {
        "NoRuntimeChecks", -- Only used on Visual Studio.
		"NoBufferSecurityCheck"
    }

    -- buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus"}

    -- warnings "off"

    location (LocationDir)
    targetdir (EXEDir)
    objdir (ObjectDir)

    -- inlining    "Explicit"
	-- intrinsics  "Off"

    filter "system:windows" 
        -- staticruntime "Off"
        systemversion "latest"
        defines { "_WINDOWS","_WIN64" }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        defines { "_DEBUG" }

    filter "configurations:Release"
        runtime "Release"
        optimize "Speed"
        symbols "On"
        defines { "NDEBUG" }

    filter "configurations:Dist"
        runtime "Release"
        optimize "Full"
        symbols "Off"
        defines { "NDEBUG" }