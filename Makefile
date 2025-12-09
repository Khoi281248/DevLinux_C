.PHONY: all clean run

TARGET = run

all:
	gcc main.c src/*.c -I include -o $(TARGET)

clean:
	rm -rf $(TARGET)

run: all
	./$(TARGET)
