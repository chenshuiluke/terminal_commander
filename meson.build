project('terminal_commander', 'cpp')

lib_inc_dir = include_directories('include')
add_global_arguments('-std=c++11', language:'cpp')

ncurses = dependency('ncurses', required : false)
if ncurses.found()
	lib = shared_library('terminal_commander', 'src/terminal_commander.cpp', 'src/TuiXMLElement.cpp', 'src/tinyxml2.cpp', include_directories:lib_inc_dir, dependencies: [ncurses])
	executable('unit_test', 'src/unit_test.cpp', include_directories:lib_inc_dir, link_with:lib)

else
	lib = shared_library('terminal_commander', 'src/terminal_commander.cpp', 'src/TuiXMLElement.cpp', 'src/tinyxml2.cpp', include_directories:lib_inc_dir, link_args : '-lpdcurses')
	executable('unit_test', 'src/unit_test.cpp', include_directories:lib_inc_dir, link_with:lib)
endif