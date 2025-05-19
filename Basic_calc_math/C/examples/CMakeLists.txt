cmake_minimum_required(VERSION 2.8)	 # Проверка версии CMake.
										# Если версия установленной программы
										# старее указаной, произойдёт аварийный выход.

project(bs)			# Название проекта

set(SOURCE_EXE MyBI.c)		# Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB /home/SubLimeProjects/Basic_calc_math/lib/interpolation.c 
		/home/SubLimeProjects/Basic_calc_math/lib/basic_type.c 
		/home/SubLimeProjects/Basic_calc_math/lib/LinearSystemSolvers/Diagonal_matrix_solver.c
		/home/SubLimeProjects/Basic_calc_math/lib/integration.c
		/home/SubLimeProjects/Basic_calc_math/lib/LinearSystemSolvers/DirectGauss.c
		/home/SubLimeProjects/Basic_calc_math/BigDigits/bigd.c
		/home/SubLimeProjects/Basic_calc_math/BigDigits/bigdigits.c)			# Тоже самое, но для библиотеки

add_library(rect SHARED ${SOURCE_LIB})	# Создание статической библиотеки с именем foo

include_directories(/home/SubLimeProjects/Basic_calc_math/include
					/home/SubLimeProjects/Basic_calc_math/BigDigits)

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

set(MYCOMPILE_FLAGS "-lm")

add_definitions(${MYCOMPILE_FLAGS})

target_link_libraries(main rect)		# Линковка программы с библиотекой