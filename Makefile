CC = gcc

CFLAGS = \
    -std=c17 \
    -Wall \
    -Wextra \
    -pedantic \
    -O2

TARGET = taranctl

SRC = \
    src/main.c \
    src/system/system_info.c \
    src/doctor/doctor.c

INCLUDES = -Iinclude

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
