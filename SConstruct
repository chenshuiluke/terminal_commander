env = Environment()
env['SHLIBPREFIX'] = ''
#lib_target = "terminal_commander"
#env.SharedLibrary(target = lib_target, source = lib_sources)
#lib_sources= ["src/terminal_commander.cpp", "src/terminal_info.cpp"]
unit_test_target = "unit_test"
env.Program(target = unit_test_target, source = 'unit_test.cpp')
env.Append(CPPPATH = ['include'])
#catch.hpp will not compile if using GCC 5 without the -std=c++11 flag 
env.Append(CCFLAGS = ['-g','-std=c++11'])
env.Append(LIBS = ['-lpthread','-lncurses'])

env.Program(target = 'bin/unit_test', source='unit_test.cpp')
