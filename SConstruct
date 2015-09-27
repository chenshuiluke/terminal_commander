env = Environment()
env['CPPPATH'] = ['include']
env.Append(CCFLAGS = ['-std=c++11', '-g'])
lib = env.SharedLibrary('build/terminal_commander', source=['src/terminal_commander.cpp', 'src/tinyxml2.cpp'])
env.Install('/usr/lib', lib)
env.Alias('install','/usr/lib')
#env.Append(LIBPATH=['.', 'build'])
#env.Append(LIBS=['terminal_commander'])
env.Program('unit_test', 'unit_test.cpp', LIBPATH=[',', 'build'], LIBS=['terminal_commander'])
