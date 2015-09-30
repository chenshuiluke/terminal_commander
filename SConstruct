import os
env = Environment()
env['CPPPATH'] = ['include']
env.Append(CCFLAGS = ['-std=c++11', '-g', '-static'])
lib = env.SharedLibrary('build/terminal_commander', source=['src/terminal_commander.cpp', 'src/tinyxml2.cpp', 'src/TuiXMLElement.cpp'])
if os.name == 'nt':
	env.Append(LIBS=['pdcurses'])
else:
	env.Append(LIBS=['ncurses'])
env.Install('/usr/lib', lib)
env.Alias('install','/usr/lib')
#env.Append(LIBPATH=['.', 'build'])
#env.Append(LIBS=['terminal_commander'])
env.Program('build/unit_test', 'src/unit_test.cpp', LIBPATH=['./build'], LIBS=['terminal_commander'])
