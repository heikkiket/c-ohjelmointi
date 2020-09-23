binary = app.bin

matkakortti.bin:
	g++ \
	matkakortti_cpp_heap/main.cpp \
	matkakortti_cpp_heap/matkakortti.cpp \
	matkakortti_cpp_heap/matkalippu.cpp \
	-o $(binary)

run:
	./app.bin
