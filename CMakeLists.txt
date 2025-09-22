cmake_minimum_required(VERSION 3.20)
project(MeuProjeto C)

# Definir padrão de compilação
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Habilitar warnings (opcional, mas recomendado)
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Incluir FetchContent para baixar SDL2 e SDL2_mixer
include(FetchContent)

# SDL2
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.28.0
)
FetchContent_MakeAvailable(SDL2)

# SDL2_mixer
FetchContent_Declare(
    SDL2_mixer
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
    GIT_TAG release-2.6.0
)
FetchContent_MakeAvailable(SDL2_mixer)

# Criar executável
file(GLOB SRC_FILES "src/*.c")
add_executable(mkplayer ${SRC_FILES})

# Incluir diretórios de headers
target_include_directories(mkplayer PRIVATE src ${SDL2_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})

# Linkar SDL2 e SDL2_mixer
target_link_libraries(mkplayer PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_mixer::SDL2_mixer)
