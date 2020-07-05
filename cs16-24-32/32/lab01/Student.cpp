#include "Student.h"
#include <sstream>

Student::Student(int perm, 
		 std::string lastName, 
		 std::string firstAndMiddleNames) {
  // THIS EMPTY CONSTRUCTOR IS A STUB
  // DELETE THESE COMMENTS AND REPLACE WITH APPROPRIATE CODE
  // REMEMBER: PURPOSE OF A CONSTRUCTOR IS TO INITIALIZE 
  // ALL DATA MEMBERS WITH REASONABLE VALUES  
}

int Student::getPerm() const { 
  return -999;
}

std::string Student::getLastName() const { 
  return "stub";
}

std::string Student::getFirstAndMiddleNames() const { 
  return "stub";
}

std::string Student::getFullName() const { 
  return "stub";
}

std::string Student::toString() const { 
  return "stub";
  /*
  // e.g. [12345,Smith,Malory Logan]
  std::ostringstream oss;
  
  oss << "[" 
      << this->getPerm() << ","
      << this->getLastName() << ","
      << this->getFirstAndMiddleNames() << "]";
  return oss.str();
  */

} 

