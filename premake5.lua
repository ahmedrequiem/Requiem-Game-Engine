workspace "Requiem-Engine"
  configurations { "Debug", "Release", "Dist" }
  architecture "x86_64"
  toolset "clang"
  startproject "sandbox"
  platforms { "x64" }

project "engine"
  location "engine"
  kind "SharedLib"
  language "C"

  targetdir "bin/%{cfg.buildcfg}/%{prj.name}/"
  objdir "bin-int/%{cfg.buildcfg}/%{prj.name}/"

  files { "engine/src/**.c", "engine/src/**.h" }

  includedirs { "$(VULKAN_SDK)/Include", "engine/src", "vendor/glfw/include" }
  libdirs { "$(VULKAN_SDK)/Lib", "vendor/glfw" }

  defines { "RQ_EXPORT", "GLFW_INCLUDE_VULKAN" }

  links { "vulkan-1", "glfw3" }

  filter { "system:windows" }
    cdialect "C17"
    staticruntime "On"
    systemversion "latest"
    defines { "RQ_PLATFORM_WINDOWS", }

  filter { "configurations:Debug" }
    symbols "On"
    defines { "RQ_BUILD_DEBUG" }
  filter { "configurations:Release" }
    optimize "On"
    defines { "RQ_BUILD_RELEASE" }
  filter { "configurations:Dist" }
    optimize "On"
    defines { "RQ_BUILD_DIST" }

project "sandbox"
  location "sandbox"
  kind "ConsoleApp"
  language "C"

  targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
  objdir "bin-int/%{cfg.buildcfg}/%{prj.name}"

  files { "sandbox/src/**.c", "sandbox/src/**.h" }

  includedirs { "$(VULKAN_SDK)/Include", "engine/src" }
  libdirs { "$(VULKAN_SDK)/Lib", "bin/%{cfg.buildcfg}/engine/" }

  links { "vulkan-1", "engine" }

  filter { "system:windows" }
    cdialect "C17"
    staticruntime "On"
    systemversion "latest"
    defines { "RQ_PLATFORM_WINDOWS", }

  filter { "configurations:Debug" }
    symbols "On"
    defines { "RQ_BUILD_DEBUG" }
  filter { "configurations:Release" }
    optimize "On"
    defines { "RQ_BUILD_RELEASE" }
  filter { "configurations:Dist" }
    optimize "On"
    defines { "RQ_BUILD_DIST" }