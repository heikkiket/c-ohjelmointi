binary = app.bin

matkakortti.bin:
	g++ \
	matkakortti_cpp/main.cpp \
	matkakortti_cpp/matkakortti.cpp \
	matkakortti_cpp/matkalippu.cpp \
	-o $(binary)

run:
	./app.bin
