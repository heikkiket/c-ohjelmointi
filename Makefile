binary = app.bin

matkakortti.bin:
	g++ \
	matkakortti_cpp_fancy/main.cpp \
	matkakortti_cpp_fancy/matkakortti.cpp \
	matkakortti_cpp_fancy/matkalippu.cpp \
	matkakortti_cpp_fancy/leimaaja.cpp \
	matkakortti_cpp_fancy/leimaustapahtuma.cpp \
	-o $(binary)

run:
	./app.bin
