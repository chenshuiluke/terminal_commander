import os
env = Environment()
env.Append(CPPPATH = ['include'])
if os.name == 'posix':
	env.Append(LIBS = ['ncurses'])
else:
	if os.name == 'nt':
		env.Append(LIBS = ['pdcurses'])
env.Append(CCFLAGS = ['-std=c++11', '-g'])
terminal_commander = env.SharedLibrary(target = "terminal_commander", source = ["src/terminal_commander.cpp", "src/pugixml.cpp"])
env.Install('/usr/lib', source=terminal_commander)
env.Alias('install', '/usr/lib');
env.Append(CPPPATH = ['Catch/single_include'])
env.Program(target = "test", source = ["src/unit_test.cpp"], LIBS = ['terminal_commander'])
