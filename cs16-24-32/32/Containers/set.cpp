#include <set>

using namespaces std;

int main() {
	set<string> s;
	s.insert("Harry");
	s.insert("Hermione");
	s.insert("Ron");
	s.insert("Harry"); // duplicate (only stored once)
	s.insert("Snape");
	// print out the contents
	for (set<string>::iterator i = s.begin(); i != s.end(); i++) {
		cout << *i << endl;
	}
}
// default: alpha. order 
// <unordered_set>
for(set<string>::iterator i = s.begin(); i < s.end(); i++){
	cout << *i << << endl;
}

// find() returns an iterator to the item in a set if it exists.
// 		Otherwise, find() returns an iterator == set.end()

if (s.find("Harry") != s.end()) {
	cout << "Harry exists!" << endl; // prints this
} else {
	cout << "Harry DNE" << endl;
}

if (s.find("Hagrid") != s.end()) {
	cout << "Hagrid exists!" << endl;
} else {
	cout << "Hagrid DNE" << endl;	// prints this
}

