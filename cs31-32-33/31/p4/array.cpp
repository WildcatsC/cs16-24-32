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
    if(s == "") return "";
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
    string arr5[50] = {"", "aaaa", "aaaa", "baaa", "bbab", "c", "zxxx.?(),,"};
    string arr6[20] = {"", ""};


    assert(locateMinimum(arr1, 8) == 7);
    assert(locateMinimum(arr2, 0) == -1);
    assert(locateMinimum(arr4, 5) == 3);
    assert(locateMinimum(arr2, 3) == 2);
    assert(locateMinimum(arr5, 7) == 0);
    assert(locateMinimum(arr6, 2) == 0);

    assert(countPunctuation(arr1, 8) == 3);
    assert(countPunctuation(arr4, 5) == 3);
    assert(countPunctuation(arr4, 1) == 0);
    assert(countPunctuation(arr2, 3) == 0);
    assert(countPunctuation(arr5, 7) == 6);
    
    assert(hasReverse(arr1, 8) == true);
    assert(hasReverse(arr3, 5) == false);
    assert(hasReverse(arr3, 8) == true);
    assert(hasReverse(arr5, 1) == false);
    assert(hasReverse(arr5, 7) == true);
    assert(hasReverse(arr6, 2) == true);


    assert(highestOccurredCharacter(arr1, 8, 3) == 'e');
    assert(highestOccurredCharacter(arr1, 8, 4) == 'a');
    assert(highestOccurredCharacter(arr4, 5, 0) == 'j');
    assert(highestOccurredCharacter(arr4, 5, 2) == 'l');
    assert(highestOccurredCharacter(arr4, 5, 1) == 'a');
    assert(highestOccurredCharacter(arr5, 7, 6) == 'x');
    assert(highestOccurredCharacter(arr5, 7, 0) == '\0');

    assert(isInIncreasingOrder(arr1, 3) == false);
    assert(isInIncreasingOrder(arr4, 5) == false);
    assert(isInIncreasingOrder(arr4, 3) == true);
    assert(isInIncreasingOrder(arr5, 2) == true);
    assert(isInIncreasingOrder(arr6, 2) == false);

    assert(firstNonRepeatedCharacter(arr4, 5, 1) == '!');
    assert(firstNonRepeatedCharacter(arr4, 5, 0) == 'j');
    assert(firstNonRepeatedCharacter(arr1, 10, 1) == 'b');
    assert(firstNonRepeatedCharacter(arr1, 10, 4) == 'i');
    assert(firstNonRepeatedCharacter(arr3, 8, 6) == 'e');
    assert(firstNonRepeatedCharacter(arr5, 7, 0) == '\0'); 
    assert(firstNonRepeatedCharacter(arr5, 7, 6) == 'z');

    assert(isOnlyDigits(arr2, 3) == true);
    assert(isOnlyDigits(arr4, 5) == false);
    assert(isOnlyDigits(arr1, 10) == false);
    assert(isOnlyDigits(arr5, 7) == false);
    assert(isOnlyDigits(arr6, 2) == false);

    cout << "yes sir" << endl;
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
    if(n <= 0 || index >= n || index < 0) return '\0';

    string s = array[index];
    char ans = '\0';
    int map[150]; 
    int count = 0;
    for(size_t i = 0; i < 150; i++) 
        map[i] = 0;
    for(size_t k = 0; k < s.size(); k++){
        int idx = static_cast<int> (s[k]);
        map[idx]++;
    }
    for(size_t id = 0; id < 150; id++){
        if(map[id] > count){ 
            ans = static_cast<char> (id);
            count = map[id];
        }
    }
    return ans;
}

bool isInIncreasingOrder(const string array[], int n){
    if(n<=0) return false;

    for(size_t i = 0; i < n-1; i++){
        if(array[i] >= array[i+1])
            return false;
    }
    return true;
}

char firstNonRepeatedCharacter(const string array[], int n, int index){
    if(n <= 0 || index >= n || index < 0) return '\0'; 

    string s = array[index];
    char ans = '\0';
    int map[150]; 
    for(size_t i = 0; i < 150; i++) 
        map[i] = 0;
    for(size_t k = 0; k < s.size(); k++){
        int idx = static_cast<int> (s[k]);
        map[idx]++;
    }
    for(size_t j = 0; j < s.size(); j++){
        int idx = static_cast<int> (s[j]);
        if(map[idx] == 1){
            ans = static_cast<char> (idx);
            return ans;
        } 
    }
    return ans;
} 

bool isOnlyDigits(const string array[], int n){
    if(n <= 0) return false;

    for(size_t i = 0; i < n; i++){
        string s = array[i];
        if(s == "") return false;
        for(size_t j = 0; j < s.size(); j++){
            int ascii = static_cast<int> (s[j]);
            if(ascii < 48 || ascii > 57) 
                return false;
        }
    }
    return true; 
}