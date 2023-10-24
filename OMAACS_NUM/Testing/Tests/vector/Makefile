all: build run


build:
	clang -std=c17 -Wall -Wextra -Wpointer-arith -Wcast-align -Wwrite-strings -Wswitch-default -Wunreachable-code -Winit-self -Wmissing-field-initializers -Wno-unknown-pragmas -Wstrict-prototypes -Wundef -Wold-style-definition -I../../Unity/src ../../Unity/src/unity.c vector.c -I ../../../src/vector.h -o test1.out

run:
	./test1.out