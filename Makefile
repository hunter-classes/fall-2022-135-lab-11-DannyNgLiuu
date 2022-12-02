main: main.o Profile.o network.o social3.o
	g++ -o main main.o Profile.o network.o social3.o

main.o: main.cpp Profile.h network.h social3.h

Profile.o: Profile.cpp Profile.h

network.o: network.cpp network.h

social3.o: social3.cpp social3.h

clean:
	rm -f main.o Profile.o n