bin/main:src/main.cpp src/pointer_use.cpp src/howuse.cpp
	g++ -g -o main src/main.cpp src/howuse.cpp src/address.pb.cc -L/usr/local/Cellar/protobuf@2.5/2.5.0/lib -lprotobuf -lprotoc -I/usr/local/Cellar/protobuf@2.5/2.5.0/include -pthread
	cp -a src/*.h include/
 
