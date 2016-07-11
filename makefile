all:
	g++ -o solution --std=c++14 *.cpp -lpthread

clean:
	rm -f solution *.out *.gch
