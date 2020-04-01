
#phrase1:	main1.cpp
#	g++ -std=c++11  -O2 -g -o phrase1.exe main1.cpp  -lm

#phrase2:	main2.cpp
#	g++ -std=c++11  -O2 -g -o phrase2.exe main2.cpp  -lm

#phrase3:	main3.cpp
#	g++ -std=c++11  -O2 -g -o phrase3.exe main3.cpp  -lm

phrase4:	main4.cpp
	g++ -std=c++11  -O2 -g -o phrase4.exe main4.cpp  -lm

clean:	
	rm *.exe

