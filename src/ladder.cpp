#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << "Error: " << msg << " (" << word1 << ", " << word2 << ")" << endl;
}

bool edit_distance_within(const string& str1, const string& str2, int d) {
    int len1 = str1.length(), len2 = str2.length();
    if(abs(len1 - len2) > d) return false;

    int i = 0, j = 0, differences = 0;
    while(i < len1 && j < len2){
        if(str1[i] != str2[j]){
            if(++differences > d) return false;
            if(len1 > len2) i++;
            else if(len1 < len2) j++;
            else{ i++; j++; }
        }
        else{
            i++; j++;
        }
    }
    return (differences + (len1 - i) + (len2 - j)) <= d;
}


