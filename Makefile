all:
	make build && make run && make clean

build:
	g++ main.cpp Application.cpp CommandController/Controller/CommandController.cpp CommandController/Parser/Parser.cpp CommandController/CommandRegistry/CommandRegistry.cpp CommandController/Command/Commands.cpp CommandController/ItemRegistry/ItemRegistry.cpp Document/Document/Document.cpp Document/Slide/Slide.cpp Document/Item/Item.cpp Document/Item/Items.cpp Document/Item/Geometry.cpp Document/Item/Attributes.cpp -o oop

run:
	./oop

clean:
	rm -rf oop