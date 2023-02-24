LIB = s21_matrix_oop.a
BUILD_DIR = build

all: $(LIB) test

$(LIB):
	mkdir -p $(BUILD_DIR)
	cmake . -B $(BUILD_DIR)
	$(MAKE) -C $(BUILD_DIR) s21_matrix_oop

test: $(LIB)
	$(MAKE) -C $(BUILD_DIR) tests
	./build/tests

clang:
	clang-format -n lib/*.cc inc/*.h tests/*

valgrind:
	valgrind --leak-check=full ./build/tests

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all test clang valgrind clean
