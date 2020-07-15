#include <iostream>
#include <cassert>
using namespace std;

int ctoi(char c){
    int r = (int)c - 48;
    if(r >= 0 && r <= 9) return r;
    return -1;
}

bool isWellFormedGroceryOrderString(string grocerystring){

    int total = 0;
    int pickup = 0; 
    int delivery = 0;
    string s = "";

    for(size_t k=0; k<grocerystring.size(); k++){
         s += tolower(grocerystring[k]);
    }
    
    for(size_t k=0; k<s.size(); k++){
        // cout << "current sk: " << s[k] << endl;
        if(!(s[k]=='p' || s[k]=='d' || s[k]=='s' || s[k]== 'i') && ctoi(s[k]) == -1){
            return false;
        }

        if(s[k]=='p' || s[k]=='d' || s[k]=='s' || s[k]== 'i'){
            // cout << "reached here before pd" << endl;
            if(k == 0) return false;  // cannot be letter only 
            if(k>=1 && ctoi(s[k-1])==-1) return false; // has to follow a digit
            if(k>=2 && ctoi(s[k-2])==-1 && ctoi(s[k-1])==0) return false; // cannot be 0
            if(k>=3 && ctoi(s[k-2])!=-1  && ctoi(s[k-3])!=-1) return false; // # cannot exceed 99 with k-2 and k-3 are both digits
            

            // cases of pickup or delivery 
            if(s[k]=='p'){
                pickup += ctoi(s[k-1]);
                // cout << "reached pickup" << endl;  
                if(k>=2 && ctoi(s[k-2])==0) return false;  // cannot begin with 0
                if(k>=2 && ctoi(s[k-2])!=-1) pickup += ctoi(s[k-2])*10;
            }
            else if(s[k]=='d'){
                delivery += ctoi(s[k-1]);  
                // cout << "reached deliv" << endl;
                if(k>=2 && ctoi(s[k-2])==0) return false;   // cannot begin with 0
                if(k>=2 && ctoi(s[k-2])!=-1) delivery += ctoi(s[k-2])*10;
            }
            
            // general cases (including pickup and delivery)
            total += ctoi(s[k-1]);
            // cout << "reached total" << endl;
            if(k>=2 && ctoi(s[k-2])==0) return false;
            if(k>=2 && ctoi(s[k-2])!=-1) total += ctoi(s[k-2])*10;
        }
        
    }
    // cout << "reach end" << endl;
    if(total!=0 && total < 100 && pickup < 21 && delivery < 11) return true;
    return false;

}

int pickupCount(string grocerystring){
    if(isWellFormedGroceryOrderString(grocerystring)==false) return -1;

    int pickup = 0;
    string s = "";

    for(size_t k=0; k<=grocerystring.size(); k++){
         s += tolower(grocerystring[k]);
    }

    for(size_t k=0; k<=s.size(); k++){
        if(s[k]=='p'){
            pickup += ctoi(s[k-1]); 
            if(k>=2 && ctoi(s[k-2])!=-1) pickup += ctoi(s[k-2])*10;
        }
    }

    return pickup; 
}

int deliveryCount(string grocerystring){
    if(isWellFormedGroceryOrderString(grocerystring)==false) return -1;

    int delivery = 0;
    string s = "";

    for(size_t k=0; k<=grocerystring.size(); k++){
         s += tolower(grocerystring[k]);
    }

    for(size_t k=0; k<=s.size(); k++){
        if(s[k]=='d'){
            delivery += ctoi(s[k-1]); 
            if(k>=2 && ctoi(s[k-2])!=-1) delivery += ctoi(s[k-2])*10;
        }
    }
    
    return delivery; 
}

int shipCount(string grocerystring){
    if(isWellFormedGroceryOrderString(grocerystring)==false) return -1;

    int ship = 0;
    string s = "";

    for(size_t k=0; k<=grocerystring.size(); k++){
         s += tolower(grocerystring[k]);
    }

    for(size_t k=0; k<=s.size(); k++){
        if(s[k]=='s'){
            ship += ctoi(s[k-1]); 
            if(k>=2 && ctoi(s[k-2])!=-1) ship += ctoi(s[k-2])*10;
        }
    }
    
    return ship; 
}

int inpersonCount(string grocerystring){
    if(isWellFormedGroceryOrderString(grocerystring)==false) return -1;

    int inperson = 0;
    string s = "";

    for(size_t k=0; k<=grocerystring.size(); k++){
         s += tolower(grocerystring[k]);
    }

    for(size_t k=0; k<=s.size(); k++){
        if(s[k]=='i'){
            inperson += ctoi(s[k-1]); 
            if(k>=2 && ctoi(s[k-2])!=-1) inperson += ctoi(s[k-2])*10;
        }
    }
    
    return inperson; 
}




int main(){
    // string s;
    // getline(cin, s);
    // cout << "string: " << s << endl;
    // cout << "is well: " << isWellFormedGroceryOrderString(s) << endl;
    // cout << "p: " << pickupCount(s) << endl;
    // cout << "d: " << deliveryCount(s) << endl;
    // cout << "s: " << shipCount(s) << endl;
    // cout << "i: " << inpersonCount(s) << endl;

    int tick = 0;

    string l[100] = {"1d100s","2d20j","19d20s2p2p2p2p2p2p2p", "2p2p2pp2p2p2p", "p3", "3p3l", "-1i", " 9p", "si", 
    "11d", "10d20d", "10d20p30i40s","k","+","1","99i0p", "1.5p10i", "2.0p1.0i", "1.0s", "1s1.0s", 
    "1s11s11s1s11s1s1s1s1s1s11ss", "happyDays10",
    "000001p", "+1p", "1p1d   XYZ", "50i50i50s", "10p10p10p1d1s1i", "5d5d5d1p1s1i", "1d1s1p1i "};
    
    
    for(size_t k=0; k<100; k++){
        if(isWellFormedGroceryOrderString(l[k]) == 1) tick += 1;
    }
    // cout << "tick = " << tick << endl;

    	assert( isWellFormedGroceryOrderString("") == false );
	    assert( isWellFormedGroceryOrderString("    ") == false );
        assert( shipCount( "    " ) == -1 );
        assert( deliveryCount( "      " ) == -1 );
        assert( inpersonCount( "      " ) == -1 );
        assert( pickupCount( "       " ) == -1 );
        assert( isWellFormedGroceryOrderString( "1s1d1i1p1S1D1I1P" ) == true );
        assert( shipCount( "1s1d1i1p1S1D1I1P" ) == 2 );
        assert( deliveryCount( "1s1d1i1p1S1D1I1P" ) == 2 );
        assert( inpersonCount( "1s1d1i1p1S1D1I1P" ) == 2 );
        assert( pickupCount( "1s1d1i1p1S1D1I1P" ) == 2 );
        assert( shipCount("1s1s1s1s1s1s1s1s1s1s9s") == 19);
        assert( shipCount("20s90s") == -1);
        assert( deliveryCount("20d30s") == -1);
        assert( deliveryCount("3d4d1d10d20s") == -1);
        assert( deliveryCount("3d2d1d1d1d50s") == 8);
        assert( pickupCount("3d2d1d0d") == -1);
        assert( pickupCount("1d2d19p1p2d2d2d") == 20);
        assert( pickupCount("1.5p2p3p") == -1);
        assert( shipCount("1d2d1p3p4p") == 0);
        assert( shipCount("10D20P3S") == 3);
        assert( shipCount("1p1d1s1i") == 1);
        assert( pickupCount("5d5p") == 5);
        assert( pickupCount("1D1P4d4p") == 5);
        assert( inpersonCount("20i3i3i3i03i") == -1);
        assert( inpersonCount("2i3i4i5i1i") == 15);
        assert( tick == 0);
	    
	    cerr << "All tests succeeded" << endl;


    return 0;
}

