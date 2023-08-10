workspace "Mycle" -- MCL for prefix
    configurations { "Debug", "Release", "Dist"}
    architecture "x64"


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "MycleEngine"
    location "MycleEngine"
    kind "Sharedlib"
    language "C++"

    targetdir ("output/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("output/int/" .. outputdir .. "/%{prj.name}")
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.hpp"
    }
    includedirs {
        "%{prj.name}/dep/GLEW/include",
        "%{prj.name}/dep/GLFW/include"
    }
    libdirs {
        "%{prj.name}/dep/GLFW/lib-vc2022",
        "%{prj.name}/dep/GLEW/lib/Release/x64"
    }
    links {
        "glew32s.lib",
        "glfw3_mt.lib",
        "opengl32.lib"
    }
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        defines {
            "MCL_PLATFORM_WINDOWS",
            "MCL_SHARED",
            "MCL_BUILD"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../output/bin/" .. outputdir .. "/Sandbox")
        }
    filter "configurations:Debug"
        defines {
            "MCL_DEBUG"
        }
        symbols "On"
    filter "configurations:Release"
        defines {
            "MCL_RELEASE"
        }
        symbols "On"
        optimize "On"
        
    filter "configurations:Dist"
        defines {
            "MCL_DIST"
        }
        symbols "Off"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"   
    language "C++"
    targetdir ("output/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("output/int/" .. outputdir .. "/%{prj.name}")
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.hpp"
    }
    includedirs {
        "MycleEngine/src"
    }
    links {
        "MycleEngine"
    }
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        defines {
            "MCL_PLATFORM_WINDOWS",
            "MCL_SHARED",
        }
    filter "configurations:Debug"
        defines {
            "MCL_DEBUG"
        }
        symbols "On"
    filter "configurations:Release"
        defines {
            "MCL_RELEASE"
        }
        symbols "On"
        optimize "On"
        
    filter "configurations:Dist"
        defines {
            "MCL_DIST"
        }
        symbols "Off"
        optimize "On"
    