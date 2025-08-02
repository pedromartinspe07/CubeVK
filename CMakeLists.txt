cmake_minimum_required(VERSION 3.10)
project(MinecraftClone C)

find_package(Vulkan REQUIRED)

add_executable(mc
    main.c
    render/vulkan_init.c
    render/renderer.c
    world/chunk.c
    world/block.c
    player/player.c
    util/math.c
)

target_include_directories(mc PRIVATE
    ${Vulkan_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/world
    ${PROJECT_SOURCE_DIR}/render
    ${PROJECT_SOURCE_DIR}/player
    ${PROJECT_SOURCE_DIR}/util
)

target_link_libraries(mc PRIVATE ${Vulkan_LIBRARIES})
