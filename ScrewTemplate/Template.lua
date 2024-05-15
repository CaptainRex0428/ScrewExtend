project "ScrewTemplateFile"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    files
    {
        "Template01.cpp"
    }

    includedirs
    {
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
    }

    buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus"}

    location (LocationDir)
    targetdir (EXEDir)
    objdir (ObjectDir)

    filter "system:windows" 
        systemversion "latest"
        defines { "_WINDOWS","_WIN64" }

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


project "ScrewTemplateEntity"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    files
    {
        "Template02.cpp"
    }

    includedirs
    {
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
    }

    buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus"}

    location (LocationDir)
    targetdir (EXEDir)
    objdir (ObjectDir)

    filter "system:windows" 
        systemversion "latest"
        defines { "_WINDOWS","_WIN64" }

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