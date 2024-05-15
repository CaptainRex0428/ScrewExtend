include "Dependencies.lua"
include "Directory.lua"

workspace "ScrewExtend"
	architecture "x64"
	startproject "ScrewSandbox"
	configurations{
		"Debug",
		"Release",
        "Dist"
	}

    filter "system:windows"
    buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
	
group "Lib"
	include "ScrewExtend.lua"

group "Sandbox"
	include "ScrewSandbox/ScrewSandbox.lua"
	include "ScrewTemplate/Template.lua"

group "Dependencies"
	include "Dependencies/spdlog.lua"