env = Environment()
env.Append(CPPPATH = ['include'])
env.Append(LIBS = ['ncurses'])
env.Append(CCFLAGS = ['-std=c++11', '-g'])
terminal_commander = env.SharedLibrary(target = "terminal_commander", source = ["src/terminal_commander.cpp", "src/pugixml.cpp"])
env.Install('/usr/lib', source=terminal_commander)
env.Alias('install', '/usr/lib');
env.Append(LIBS = ['terminal_commander'])
env.Append(CPPPATH = ['Catch/single_include'])
env.Program(target = "test", source = ["src/unit_test.cpp"])
