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
