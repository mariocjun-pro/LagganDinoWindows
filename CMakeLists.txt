# Versao do Cmake que sera utilizada
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
set(PROJECT_NAME "LagganDino")
project(${PROJECT_NAME})

# Adiciona a flag de debug
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Configura o diretorio de links
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/libs/SFML/lib/cmake/SFML")
file(COPY libs/SFML/bin/openal32.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Criando a lista de flags para o compilador
list(APPEND FLAGS "-std=c++11") # C++11
list(APPEND FLAGS "-w")         # Desabilita os warnings (para ativar, comente essa linha)
list(APPEND FLAGS "-Wall")      # Warnings
list(APPEND FLAGS "-Wextra")    # Warnings extras
list(JOIN FLAGS " " FLAGS)

# Adiciona flags de compilação para o projeto
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS}")

#link_libraries(stdc++fs)

file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_FILES})

set(THREADS "-lpthread")
find_package(Threads REQUIRED)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system)