/*Anggota Kelompok
1. Muhammad Fachru Syahputra (2017051087)
2. Riyo Pratama Juliyansa (2017051075)
3. M. Thoriq Al Fajri (2057051002)
*/

#include <cmath> //NO 1
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string input; 
    getline(cin,input);
    vector<char> data;
    long unsigned int i;
    
    for(i=0; i<input.length(); i++){
        if(input[i] == ' ')
            continue;
        else if(isdigit(input[i])){ 
            while(i<input.length() && isdigit(input[i])){
                data.push_back(input[i]);
                i++;
            }
            i--;
        }
        else if(input[i] == '-'){
            data.push_back(input[i]);
            if(i==0){
                if(isdigit(input[i+1])){
                    i++;
                    while(i<input.length() && isdigit(input[i])){
                        data.push_back(input[i]);
                        i++;
                    }
                    i--;
                } else {
                    data.push_back('1');
                    data.push_back(' ');
                    data.push_back('*');
                }
            } else {
                if(!isdigit(input[i-1]) && input[i+1] != ' '){
                    data.push_back('1');
                    data.push_back(' ');
                    data.push_back('*');
                } 
            }
        } else
            data.push_back(input[i]);
        data.push_back(' ');
    }
    cout << "Print : ";
    for(auto j:data)
        cout << j; 
    return 0;
}
