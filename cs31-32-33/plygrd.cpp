#include <iostream>
#include <string>
#include <cassert>
#include "Zipper.cpp"

using namespace std;

// class Exam{
// 	public: 
// 		int t;
// 		int b;
// 		int bar( const int& a, int b, int * c ) const{
// 			cout << "const" << endl;
// 			return 0;
// 	}
// };

// int foo( int a, int b, int c, int d=12, int e=20 ){
// 	return 0;
// }
int  foo( double d, int i, string s );
int  foo( string s="CS 31", char grade='A' );
int  foo( string first="Howard", string last );

// void f( double d, int i, string s );
// void f( string s="CS 31", char grade='A' );
// void f( int i, string first="Howard", string last="Stahl" );

// void dnaComplement(string dnasequence, char result[ ], int & sizeOfResult ); 

// void foo( int array[ ] , int size ){
// 	array[0] = 100;
// 	cout << array[0] << endl;
// }

class LightBulb
   {
    public:
      LightBulb( int wattage = 20, bool isOn = false );

       void turnOn( );
       void turnOff( );
       bool isTurnedOn( );

    private:
      bool m_isOn;
      int  m_wattage;
   };

 

    LightBulb::LightBulb( int wattage,  bool isOn )
    {
          m_wattage = wattage;
          m_isOn = isOn;
    } 

    void LightBulb::turnOn( )
    {
          m_isOn = true;
		  cout << "light is on" << endl;
    }

    void LightBulb::turnOff( )
    {
         m_isOn = false;
		 cout << "light is off" << endl;
    }

    bool LightBulb::isTurnedOn( )
    {
        return( m_isOn );
    }

class Refrigerator
     {
          public:
              Refrigerator(string make, string model, int watts);

              void openDoor( );
              void closeDoor( );
              string getMake() const;
              string getModel() const;             

          private:

              LightBulb m_Bulb;
              string  m_Make;
              string  m_Model;

          };

Refrigerator::Refrigerator(string make, string model, int watts){
	m_Make = make;
	m_Model = model;
	LightBulb b(watts, false);
	m_Bulb = b;
}

void Refrigerator::openDoor(){
	m_Bulb.turnOn();
}

void Refrigerator::closeDoor(){
	m_Bulb.turnOff();
}

string Refrigerator::getMake() const{
	return m_Make;
}

string Refrigerator::getModel() const{
	return m_Model;
}








// MAIN 
int main(int argc, const char * argv[]) {
	cout.setf(ios::boolalpha);
// Refrigerator R("Toyota", "Camry", 25);
// cout << R.getMake() << endl;
// cout << R.getModel() << endl;
// R.openDoor();
// R.closeDoor();


// std::string dna1 = "agtc";
// char array1[ 100 ];
// int sizeOfArray1 = 100;

// dnaComplement( dna1, array1, sizeOfArray1 );

// assert( sizeOfArray1 == 4 );

// assert( array1[ 0 ] == 't' );
// assert( array1[ 1 ] == 'c' );
// assert( array1[ 2 ] == 'a');
// assert( array1[ 3 ] == 'g' );

// std::string dna2 = "TCagAGtc";
// char other[ 100 ];
// int sizeOfOther = 100;

// dnaComplement( dna2, other, sizeOfOther );

// assert( sizeOfOther == 8 );

// assert( other[ 0 ] == 'A' );
// assert( other[ 1 ] == 'G' );
// assert( other[ 2 ] == 't' );
// assert( other[ 3 ] == 'c' );
// assert( other[ 4 ] == 'T' );
// assert( other[ 5 ] == 'C' );
// assert( other[ 6 ] == 'a' );
// assert( other[ 7 ] == 'g' );

// Zipper z( 100, 100 );
// cout << z.getHeight( ) << "x" <<
//      z.getWidth( ) <<
//      " zipper" << endl;

cout << "passed" << endl;
}

// void dnaComplement(string dnasequence, char result[ ], int & sizeOfResult ){
// 	for(size_t i = 0; i < dnasequence.size(); i++){
// 		if(dnasequence[i] == 'C')
// 			result[i] = 'G';
// 		if(dnasequence[i] == 'G')
// 			result[i] = 'C';
// 		if(dnasequence[i] == 'A')
// 			result[i] = 'T';
// 		if(dnasequence[i] == 'T')
// 			result[i] = 'A';
// 		if(dnasequence[i] == 'c')
// 			result[i] = 'g';
// 		if(dnasequence[i] == 'g')
// 			result[i] = 'c';
// 		if(dnasequence[i] == 'a')
// 			result[i] = 't';
// 		if(dnasequence[i] == 't')
// 			result[i] = 'a';
// 		sizeOfResult = i+1;
// 	}
// }

// void f( double d, int i, string s ){
// 	cout << "f1" << endl;
// }

// void f( string s, char grade){
// 	cout << "f2" << endl;
// }

// void f( int i, string first, string last ){
// // 	cout << "f3" << endl;
// }
