all: bin/geometry

bin/geometry: obj/src/geometry/geometry.o obj/src/libgeometry/libgeometry.a
	gcc -Wall -Werror -o $@ $^

obj/src/geometry/geometry.o: src/geometry/geometry.c
	gcc -c -Wall -Werror $< -MMD -o $@ -I src/libgeometry

obj/src/libgeometry/libgeometry.a: obj/src/libgeometry/str_work.o obj/src/libgeometry/print_err.o
	ar rcs $@ $^

obj/src/libgeometry/str_work.o: src/libgeometry/str_work.c src/libgeometry/str_work.h
	gcc -c -Wall -Werror $< -MMD -o $@ -I src/libgeometry

obj/src/libgeometry/print_err.o: src/libgeometry/print_err.c src/libgeometry/print_err.h
	gcc -c -Wall -Werror $< -MMD -o $@ -I src/libgeometry

test: bin/test

bin/test: obj/test/geometry_test.o obj/test/main.o obj/src/libgeometry/libgeometry.a
	gcc -Wall -Werror -MMD -o $@ $^

obj/test/main.o: test/main.c obj/test/geometry_test.o thirdparty/ctest.h
	gcc -c -Wall -Werror $< -MMD -o $@ -I thirdparty -I src/libgeometry

obj/test/geometry_test.o: test/geometry_test.c thirdparty/ctest.h
	gcc -c -Wall -Werror $< -MMD -o $@ -I thirdparty -I src/libgeometry

clean:
	rm -rf bin/geometry
	rm -rf bin/test
	rm -rf obj/src/geometry/*.d
	rm -rf obj/src/geometry/*.o
	rm -rf obj/src/libgeometry/*.a
	rm -rf obj/src/libgeometry/*.d
	rm -rf obj/src/libgeometry/*.o
	rm -rf obj/test/*.d
	rm -rf obj/test/*.o

SRCS := $(shell find . -type f -name '*.c')
HDRS := $(shell find . -type f -name '*.h')

format:
	clang-format -i $(SRCS) $(HDRS)