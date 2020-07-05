hello: main.o functions.o 
	g++ main.o functions.o -o hello

main.o: main.cpp functions.h 
	g++ main.cpp -c 

functions.o: functions.cpp functions.h 
	g++ functions.cpp -c 

clean:
	rm hello main.o functions.o 

gpa: gpa.cpp
	g++ -o gpa gpa.cpp; \
	./gpa phy22 B+ math4a B+ chem1a B+ phy21 A- dance45 A+

buggy: buggyGPA.cpp
	g++ -o buggy buggyGPA.cpp; \
	./buggy phy22 B+ math4a B+ chem1a B+ phy21 A- dance45 A+


