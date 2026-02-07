#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Roman{
    public:
        char roman;
        int value;
};
class Solution {
public:
    static int romanToInt(string s) {
        int a = 0;
        vector<Roman> numerals;
        numerals = InitialiseList(numerals);
        int lastvalue = 1001;

        for(int i = 0; i < s.length(); i++){
            for(int r = 0; r < numerals.size(); r++){
                if(s[i] == numerals[r].roman){
                    if(numerals[r].value > lastvalue){
                        a-=lastvalue;
                        a+= numerals[r].value - lastvalue;
                        lastvalue = numerals[r].value;
                    }
                    else{
                        a+=numerals[r].value;
                        lastvalue = numerals[r].value;
                    }
                    
                }
            }
        }
        return a;
    }

    static vector<Roman> InitialiseList(vector<Roman> l){
        Roman r;
        r.roman = 'I';
        r.value = 1;
        l.push_back(r);
        r.roman = 'V';
        r.value =  5;
        l.push_back(r);
        r.roman = 'X';
        r.value =  10;
        l.push_back(r);
        r.roman = 'L';
        r.value =  50;
        l.push_back(r);
        r.roman = 'C';
        r.value =  100;
        l.push_back(r);
        r.roman = 'D';
        r.value =  500;
        l.push_back(r);
        r.roman = 'M';
        r.value =  1000;
        l.push_back(r);
        return l;
    }
};

// For a console App:

//class Interface{
//public:
//    static string x;
//    static void Start(){
//        cout << "ROMAN NUMERAL CALCULATOR\n\nInput roman numerals (case sensitive)";
//        cin >> x;
//        cout << to_string(Solution::romanToInt(x)) << "\n\n Press any to close program, type 'r' to retry.";
//        cin >> x;
//        if(x == "r"){
//            Start();
//        }
//
//    }
//};