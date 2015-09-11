env = Environment()
env['SHLIBPREFIX'] = ''
lib_target = "terminal_commander"
lib_sources= ["src/terminal_commander.c", "src/terminal_info.c"]
env.SharedLibrary(target = lib_target, source = lib_sources)
env.Append(CPPPATH = ['include'])
env.Append(CCFLAGS = ['-g', '`xml2-config', '--cflags', '--libs`'])
env.Append(LIBS = ['-lpthread','-lncurses'])
