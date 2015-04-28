terminal_commander: src/main.c src/python/getTerminalDimensions.py src/terminal_info.c include/terminal_info.h
	 echo "Compiling C Source " && gcc  src/main.c src/terminal_info.c -g -o bin/terminal_commander -Iinclude && cxfreeze src/python/getTerminalDimensions.py --target-name=getTerminalDimensions && rm -r bin/python && mkdir bin/python && cp -r dist bin/python && cp src/python/getTerminalDimensions.py bin/python

windows: src/main.c src/python/getTerminalDimensions.py src/terminal_info.c include/terminal_info.h
	 C:\Python34\python.exe C:\Python34\Scripts\cxfreeze src/python/getTerminalDimensions.py --target-name=getTerminalDimensions && gcc  src/main.c src/terminal_info.c -g -o bin/terminal_commander -Iinclude && echo "Compiled C Source " &&  move dist bin/python && echo "Moved over files" && robocopy src/python/getTerminalDimensions.py bin/python
