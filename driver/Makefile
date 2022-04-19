CC = g++
AFL_DIR := ../tool/afl-2.52b
CFLAGS += -std=gnu99 -g -w $(shell pkg-config --cflags libpmemobj)
LDFLAGS += $(shell pkg-config --libs libpmemobj)

APP := driver
FUZZ_APP := driver-fuzz
OUTPUT ?= output

all: $(APP) $(FUZZ_APP)

$(APP): driver.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(FUZZ_APP): driver.cpp
	$(AFL_DIR)/afl-g++ $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

check: check.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)


clean:
	rm -rf $(APP) $(FUZZ_APP)

.PHONY: all clean
