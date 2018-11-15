bin/main:src/main.cpp src/pointer_use.cpp
	g++ -o bin/main src/main.cpp src/pointer_use.cpp
	cp -a src/*.h include/
