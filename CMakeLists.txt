cmake_minimum_required(VERSION 3.10)

project(philosophers)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_EXE_LINKER_FLAGS "-lpthread")

set(LIBFT ${CMAKE_CURRENT_SOURCE_DIR}/lib/libft42/libft.a)

add_custom_command(OUTPUT ${LIBFT}
					COMMAND make
					WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/libft42)

link_libraries(${LIBFT})
aux_source_directory(src SRC)
aux_source_directory(src_bonus SRC_BONUS)

add_executable(philo ${SRC} ${LIBFT})
add_executable(philo_bonus ${SRC_BONUS} ${LIBFT})
target_include_directories(philo
							PUBLIC inc
							PUBLIC lib/libft42/inc)
target_include_directories(philo_bonus
							PUBLIC inc_bonus
							PUBLIC lib/libft42/inc)
