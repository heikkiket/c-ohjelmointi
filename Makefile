binary = app.bin

matkakortti.bin:
	g++ \
	matkakortti_cpp_fancy/main.cpp \
	matkakortti_cpp_fancy/matkakortti.cpp \
	matkakortti_cpp_fancy/matkalippu.cpp \
	matkakortti_cpp_fancy/leimaaja.cpp \
	matkakortti_cpp_fancy/leimaustapahtuma.cpp \
	matkakortti_cpp_fancy/paneeli.cpp \
	matkakortti_cpp_fancy/omistaja.cpp \
	matkakortti_cpp_fancy/henkilokortti.cpp \
	matkakortti_cpp_fancy/lompakko.cpp \
	-o $(binary)

run:
	./app.bin
