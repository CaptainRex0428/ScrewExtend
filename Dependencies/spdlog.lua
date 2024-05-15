project "spdlog"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    files
    {
        "spdlog/src/**.cpp"
    }

    includedirs
    {
        "spdlog/include"
    }

    links
    {
    }

    defines
	{
        "SPDLOG_COMPILED_LIB"
	}

    flags
    {
        -- "NoRuntimeChecks",
		-- "NoBufferSecurityCheck"
    }

    location (LocationDir)
    targetdir (TargetDir)
    objdir (ObjectDir)

    -- postbuildcommands
	-- {
		-- ("{COPY} %{cfg.buildtarget.relpath} "..DynamicDir)
	-- }

    filter "system:windows" 
        systemversion "latest"
        defines { "_WINDOWS" }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        defines { "_DEBUG" }

    filter "configurations:Release"
        runtime "Release"
        symbols "On"
        defines { "NDEBUG" }

    filter "configurations:Dist"
        runtime "Release"
        symbols "On"
        defines { "NDEBUG" }