CC := gcc
LIB_NAME := s21_matrix_oop.a

CXXFLAGS := -lstdc++ -Wall -Werror -Wextra -std=c++17 -pedantic -fanalyzer -g \
						-pthread

SRC_FILES := $(shell find ./lib -maxdepth 1 -name "*.cc")
SRC_OBJS := $(addprefix ./lib/objects/, $(notdir $(SRC_FILES:.cc=.o)))
SRC_INC := $(shell find ./inc -maxdepth 1 -name "*.h")

CURR_DIR := .
BUILD_DIR := $(CURR_DIR)/build
CORE_DIR := $(CURR_DIR)/lib

RM := rm -f
MK := mkdir -p

EXEC := S21Matrix.test
ARCHIVE := $(CURR_DIR)/S21MAtrix

all: $(LIB_NAME) #test

$(LIB_NAME): $(SRC_OBJS) $(SRC_INC)
	ar rc $@ $(SRC_OBJS)
	ranlib $@

$(SRC_OBJS): ./lib/objects%.o: ./lib%.cc $(SRC_INC)
	@mkdir -p ./lib/objects
	$(CC) $(CXXFLAGS) -o $@ -c $<

install:
	@$(MK) $(BUILD_DIR)
	cmake $(CURR_DIR) -S $(CURR_DIR) -B $(BUILD_DIR)
	@cd $(BUILD_DIR) ; make ; cd ./..

uninstall:
	@$(RM) -r $(BUILD_DIR)

run:
	$(BUILD_DIR)/$(EXEC)

tests:

gcov_report:

clean: uninstall
