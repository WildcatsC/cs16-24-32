#include <iostream>
#include <cassert>
using namespace std;

int locateMinimum( const string array[], int n );
int countPunctuation( const string array[], int  n );
bool hasReverse( const string array[], int n );
char highestOccurredCharacter( const string array[], int n, int index );
bool isInIncreasingOrder( const string array[], int  n );
char firstNonRepeatedCharacter( const string array[], int n, int index );
bool isOnlyDigits( const string array[ ], int n );

//helper funcs:
string rev(string s){
    string ans = "";
    for(size_t k = s.size()-1; k > 0; k--){
        ans +=  s[k];
    }
    ans+=s[0];
    return ans; 
}




// MAIN  
int main(){
    cout.setf(ios::boolalpha);

    string arr1[10] = {"abc!", "abcdcdcadcc", "abc!", "aabbccddeee", "abcdingabcd", 
        "abcdxyz","cba","!cba"};
    string arr2[3] = {"12345", "54321", "1"};
    string arr3[8] = {"samwell", "jon", "margaery", "daenerys",
		"tyrion", "sansa", "llewmas", "noj"};
    string arr4[5] = {"jon", "mamabbcc!", "samwell,", "daenerys.", "tyrion"};
    string arr5[50];


    assert(locateMinimum(arr1, 8) == 7);
    assert(locateMinimum(arr2, 0) == -1);
    assert(locateMinimum(arr4, 5) == 3);
    assert(locateMinimum(arr2, 3) == 2);

    assert(countPunctuation(arr1, 8) == 3);
    assert(countPunctuation(arr4, 5) == 3);
    assert(countPunctuation(arr4, 1) == 0);
    
    assert(hasReverse(arr1, 8) == true);
    assert(hasReverse(arr3, 5) == false);
    assert(hasReverse(arr3, 8) == true);

    assert(highestOccurredCharacter(arr1, 8, 3) == 'e');
    assert(highestOccurredCharacter(arr1, 8, 4) == 'a');
    //assert(highestOccurredCharacter(arr4, 5, 0) == 'n');
    assert(highestOccurredCharacter(arr4, 5, 2) == 'l');

    assert(isInIncreasingOrder(arr1, 3) == false);
    assert(isInIncreasingOrder(arr4, 5) == false);
    assert(isInIncreasingOrder(arr4, 3) == true);

    //assert(firstNonRepeatedCharacter(arr4, 5, 1) == '!');
    //assert(firstNonRepeatedCharacter(arr4, 5, 0) == 'j');

    assert(isOnlyDigits(arr2, 3) == true);
    assert(isOnlyDigits(arr4, 5) == false);

    cout << "yes sir" << endl;


    cout << "=====" << endl;
    firstNonRepeatedCharacter(arr4, 5, 0);
    return 0;
}




// Declarations

int locateMinimum(const string array[], int n){
    if(n<=0) return -1;
    int index = 0;
    for(size_t i = 0; i < n; i++){
       if(array[i] < array[index]) index = i; 
    }
    return index;
}

int countPunctuation(const string array[], int n){
    if(n<=0) return -1;
    int count = 0;
    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < array[i].size(); j++){
            char c = array[i][j];
            if(c==',' || c=='.' || c=='-' || c==';' || c=='?' || c=='!' || c==':' || c=='"' || c=='(' || c==')')
            count++;
        }
    }
    return count;
}

bool hasReverse(const string array[], int n){
    if(n<=0) return false;
    for(size_t i = 0; i < n-1; i++){
        for(size_t j = i+1; j < n; j++){
            if(array[i] == rev(array[j]))
                return true;
        }
    }
    return false;
}

char highestOccurredCharacter(const string array[], int n, int index){
    if(n <= 0 || index >= n || index <= 0) return '\0';
    string s = array[index];
    char ans = ' ';
    int map[150]; 
    int count = 0;
    for(int i = 0; i < 150; i++) 
        map[i] = 0;
    for(size_t k = 0; k < s.size(); k++){
        int idx = static_cast<int> (s[k]);
        map[idx]++;
    }
    for(int j = 0; j < 150; j++){
        if(map[j] > count){ 
            ans = static_cast<char> (j);
            count = map[j];
        }
    }
    return ans;
}

bool isInIncreasingOrder(const string array[], int n){
    if(n<=0) return false;
    for(size_t i = 0; i < n-1; i++){
        if(array[i] > array[i+1])
            return false;
    }
    return true;
}

char firstNonRepeatedCharacter(const string array[], int n, int index){
    if(n <= 0 || index >= n || index <= 0) return '\0'; 
    char ans = ' ';
    string s = array[index];
    int map[150]; 
    for(int i = 0; i < 150; i++) 
        map[i] = 0;
    for(size_t k = 0; k < s.size(); k++){
        int idx = static_cast<int> (s[k]);
        map[idx]++;
    }
    for(size_t j = 0; j < 150; j++){
        if(map[j] == 1) 
            ans = static_cast<char> (map[j]);
    }
    return ans;
} 

bool isOnlyDigits(const string array[], int n){
    if(n <= 0) return false;
    for(size_t i = 0; i < n; i++){
        string s = array[i];
        for(size_t j = 0; j < s.size(); j++){
            int ascii = static_cast<int> (s[j]);
            if(ascii < 48 || ascii > 57) 
                return false;
        }
    }
    return true; 
}