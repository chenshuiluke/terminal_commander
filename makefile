terminal_commander: src/main.c src/python/getTerminalDimensions.py src/terminal_info.c include/terminal_info.h
	gcc src/main.c src/terminal_info.c -g -o bin/terminal_commander -Iinclude && cxfreeze src/python/getTerminalDimensions.py && sudo rm -r bin/python && mkdir bin/python && cp -r dist bin/python && cp src/python/getTerminalDimensions.py bin/python
