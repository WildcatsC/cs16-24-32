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

    string arr[10] = {"abc!", "abc", "abc!", "abcd.", "abcding..", "abcdxyz","cba","!cba"};
    assert(locateMinimum(arr, 8) == 7);
    assert(countPunctuation(arr, 8) == 6);
    assert(hasReverse(arr, 8) == true);
    
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
    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < n; j++){
            if(array[i] == rev(array[j]))
                return true;
        }
    }
    return false;
}

char highestOccurredCharacter(const string array[], int n, int index){
    if(n <= 0 || index >= n || index <= 0) return '\0';
    string s = array[index];
    char c = s[0];
    for(size_t i = 0; i < s.size(); i++){
        for(size_t j = 0;)
    }
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

} 

bool isOnlyDigits(const string array[], int n, int index){
    if(n <= 0 || index >= n || index <= 0) return false;
    string s = array[index];
    int 
}