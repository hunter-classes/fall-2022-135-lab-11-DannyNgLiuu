main: main.o Profile.o network.o social3.o
	g++ -o main main.o Profile.o network.o social3.o

main.o: main.cpp Profile.h network.h social3.h

Profile.o: Profile.cpp Profile.h

network.o: network.cpp network.h

social3.o: social3.cpp social3.h

tests: tests.o Profile.o network.o social3.o
	g++ -o tests tests.o Profile.o network.o social3.o

tests.o: tests.cpp Profile.h network.h social3.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f main tests main.o tests.o Profile.o network.o social3.o