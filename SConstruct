env = Environment()
env['CPPPATH'] = ['include']
env.Append(CCFLAGS = ['-std=c++11', '-g'])
lib = env.Library('build/terminal_commander', source=['src/terminal_commander.cpp', 'src/tinyxml2.cpp', 'src/TuiXMLElement.cpp'])
env.Install('/usr/lib', lib)
env.Alias('install','/usr/lib')
#env.Append(LIBPATH=['.', 'build'])
#env.Append(LIBS=['terminal_commander'])
env.Program('build/unit_test', 'src/unit_test.cpp', LIBPATH=['./build'], LIBS=['terminal_commander'])
