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

clean:
	@rm -rf $(BUILD_DIR)
