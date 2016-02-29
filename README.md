![terminal_commander gif](https://raw.githubusercontent.com/chenshuiluke/terminal_commander/master/gif.gif)

![terminal_commander](https://raw.githubusercontent.com/chenshuiluke/terminal_commander/master/terminal_commander.png)

terminal_commander is a C++ library that tries to make TUIs from XML files. It's not particularly functional at this point, but it's at a point where it kinda looks cool :)

#Building 

Requirements:

1. meson

2. ninja

3. ncurses/pdcurses

Steps:
1. Clone the repository

2. `mkdir build`

3.

	[luke@luke-server terminal_commander]$ meson build
	The Meson build system
	Version: 0.29.0
	Source dir: /home/luke/git/terminal_commander
	Build dir: /home/luke/git/terminal_commander/build
	Build type: native build
	Build machine cpu family: x86
	Build machine cpu: i686
	Project name: terminal_commander
	Native cpp compiler: c++ (gcc 5.3.0)
	Found pkg-config: /usr/bin/pkg-config (0.29)
	Native dependency ncurses found: YES 6.0.20150808
	Build targets in project: 2
	[luke@luke-server terminal_commander]$ 

4.

	[luke@luke-server terminal_commander]$ cd build
	[luke@luke-server build]$ ninja

	[4/7] Compiling cpp object 'terminal_commander@sha/src_terminal_commander.cpp.o'
	In file included from ../src/terminal_commander.cpp:3:0:
	../include/draw.hpp: In function ‘void drawText(TuiXMLElement)’:
	../include/draw.hpp:105:17: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
	    if(stringPos < element.text.length())
			 ^
	../src/terminal_commander.cpp: In function ‘void createElementLayers(tinyxml2::XMLElement*)’:
	../src/terminal_commander.cpp:135:24: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
	   if(layers.size() - 1 < layerNum)
				^
	../src/terminal_commander.cpp: In function ‘void start(std::__cxx11::string)’:
	../src/terminal_commander.cpp:184:31: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
	  for(int counter = 0; counter < layers.size() - 1; counter++)
				       ^
	../src/terminal_commander.cpp:186:34: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
	   for(int counter1 = 0; counter1 < layers[counter].size(); counter1++)
					  ^
	../src/terminal_commander.cpp: In function ‘int parseDoc()’:
	../src/terminal_commander.cpp:165:1: warning: control reaches end of non-void function [-Wreturn-type]
	 }
	 ^
	[6/7] Compiling cpp object 'unit_test@exe/src_unit_test.cpp.o'
	../src/unit_test.cpp: In function ‘int main()’:
	../src/unit_test.cpp:11:6: warning: unused variable ‘temp’ [-Wunused-variable]
	  int temp = testWriteDoc(testFile);
	      ^
	[7/7] Linking target unit_test

5. `./unit_test`
