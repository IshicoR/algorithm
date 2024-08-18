CC = gcc
CFLAGS = -Wall -O1

TARGET_DIR = target
TARGET = $(TARGET_DIR)/hash_search

SRCS = src/main.c src/member.c src/chain_hash.c
OBJS = $(SRCS:src/%.c=$(TARGET_DIR)/%.o)

DEPS = src/chain_hash.h src/member.h

$(TARGET): $(OBJS)
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(TARGET_DIR)/%.o: src/%.c $(DEPS)
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)