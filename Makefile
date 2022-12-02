main: main.o Profile.o network.o
	g++ -o main main.o Profile.o network.o

main.o: main.cpp Profile.h network.h

Profile.o: Profile.cpp Profile.h

network.o: network.cpp network.h


clean:
	rm -f main.o Profile.o n