all: init build 

build:
	cd cmake_build && cmake --build .
	cd ..

init:
	mkdir -p cmake_build
	cd cmake_build && cmake ../src
	cd ..

clean:
	rm -rf cmake_build