// map: an extension of set 
/* A map is an associated container containing a key / value mapping.
    Like a set, the keys are unique.
    Unlike a set, there is a value associated with each key.
*/)
#include <iostream>
#include <utility>
#include <map>
int main(){
map<int, string> students; // mapping studentIDs to studentNames

// Use bracket notation for creation
students[0] = "Richert";
students[1] = "John Doe";
students[2] = "Jane Doe";
cout << "students[1] = " << students[1] << endl;

// Check if a student id exists, similar to set
if (students.find(1) == students.end()) {
	cout << "Can’t find id = 1" << endl;
} else {
	cout << "Found student id = 1, Name = " << students[1] << endl;
}

//example 
map<string, double> stateTaxes;

stateTaxes["CA"] = 0.88;
stateTaxes["NY"] = 1.65;

if (stateTaxes.find("OR") == stateTaxes.end()) {
	cout << "Can't find OR" << endl;
} else {
	cout << "Found state OR" << endl;
}

// Example between insert vs. []
//#include <utility> // for std::pair

// ...

students.insert(pair<int, string>(2, "Chris Gaucho")); // does not replace
students[2] = "Chris Gaucho"; // replaces
cout << students[2] << endl;

	
}
