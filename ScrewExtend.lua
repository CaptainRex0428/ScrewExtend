project "ScrewExtend"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"

    files
    {
        "src/**.cpp",
        "include/**.h"
    }

    includedirs
    {
        "include",
        "%{DepIncludeDir.spdlog}"
    }

    links
    {
        "spdlog"
    }

    defines
	{
        "_CRT_SECURE_NO_WARNINGS",
        "SCREW_EXTEND_BUILD_DLL_EXPORT"
	}

    flags
    {
        -- "NoRuntimeChecks",
		-- "NoBufferSecurityCheck"
    }

    -- vectorextensions  "SSE"               -- Necessary to run x32.

    -- buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus"}

    -- warnings "off"

    location (LocationDir)
    targetdir (TargetDir)
    objdir (ObjectDir)

    -- inlining    "Explicit"
	-- intrinsics  "Off"

    postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} "..DynamicDir)
	}

    filter "system:windows" 
        staticruntime "Off"
        systemversion "latest"
        defines { "_WINDOWS" }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        defines { "_DEBUG" }

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        symbols "On"
        defines { "_RELEASE","NDEBUG" }

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"
        symbols "Off"
        defines { "_DIST","NDEBUG" }