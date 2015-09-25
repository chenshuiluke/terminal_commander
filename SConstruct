env = Environment()
env['SHLIBPREFIX'] = ''
lib_target = "bin/terminal_commander"
lib_sources= ["src/terminal_commander.cpp", "src/terminal_info.cpp"]
env.SharedLibrary(target = lib_target, source = lib_sources)
env.Append(CPPPATH = ['include'])
env.Append(CCFLAGS = ['-g', '`xml2-config', '--cflags', '--libs`'])
env.Append(LIBS = ['-lpthread','-lncurses'])

env.Program(target = 'bin/unit_test', source='unit_test.cpp')
