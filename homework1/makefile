.PHONY: clean

TEST= test/ut_main.cpp test/ut_rectangle.h test/ut_circle.h test/ut_triangle.h test/ut_two_dimensional_vector.h
SRC= src/rectangle.h src/circle.h src/shape.h src/triangle.h src/two_dimensional_vector.h

bin/test: test/ut_main.cpp $(TEST) $(SRC) # what
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

clean:
	rm -f bin/*