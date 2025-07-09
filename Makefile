./bin/Linux/main: src/**/*.cpp src/**/*.h include/**/*.h
	@mkdir -p bin/Linux
	g++ -std=c++11 -Wall -Wno-unused-function -g -I./include -o ./bin/Linux/main \
	src/main.cpp \
	src/glad.c \
	src/textrendering.cpp \
	src/tiny_obj_loader.cpp \
	src/stb_image.cpp \
	src/Bezier/bezier.cpp \
	src/Collision/collision.cpp \
	src/Rings/rings.cpp \
	./lib-linux/libglfw3.a -lrt -lm -ldl -lX11 -lpthread -lXrandr -lXinerama -lXxf86vm -lXcursor

clean:
	rm -f bin/Linux/main

run: ./bin/Linux/main
	cd bin/Linux && ./main