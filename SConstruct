env = Environment()
env['CPPPATH'] = ['include']
env.SharedLibrary('build/terminal_commander', source=['src/terminal_commander.cpp', 'src/pugixml.cpp'])
env.Program('unit_test', 'unit_test.cpp')
