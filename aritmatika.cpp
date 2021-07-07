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



#include <iostream> //no 2
#include <ctype.h>
#include <stack>
using namespace std;
long unsigned int i;

bool isOp(char x){
	if(x=='+'||x=='-'||x=='*'||x=='/'||x=='%')
		return true;
	return false;
}

int precedence(char x){
	if(x=='+'||x=='-') return 1;
	if(x=='*'||x=='/'||x=='%') return 2;
	return 0;
}
string convert(string y){
	stack<char> data;
	string postfix="";
	
	for(i=0; i<y.length(); i++){
		if(isdigit(y[i])){
			while(i<y.length() && isdigit(y[i])){
				postfix += y[i];
				i++;
			}
			i--;
			postfix += " ";
		}
		else if(y[i] == '(')
			data.push(y[i]);
		else if(y[i] == ')'){
			while(!data.empty() && data.top() != '('){
				postfix += data.top();
				postfix += " ";
				data.pop();
			}
			data.pop();
		} else {
			if(y[i] == '-'){
				if(i==0){
					if(isdigit(y[i+1])){
						postfix += y[i];
						i++;
						while(i<y.length() && isdigit(y[i])){
							postfix += y[i];
							i++;
						}
						i--;
						postfix += " ";
					}
					else{
						postfix += "-1 ";
						data.push('*');
					}
				} else {
					while(!data.empty() && precedence(data.top()) >= precedence(y[i]) && !isOp(y[i-1])){
						postfix += data.top();
						postfix += " ";
						data.pop();
					}
					if((isdigit(y[i+1]) || y[i+1]=='(') && (isdigit(y[i-1]) || y[i-1]==')'))
						data.push(y[i]);
					else {
						postfix += "-1 ";
						data.push('*');
					}
				}
			} else {
				while(!data.empty() && precedence(data.top()) >= precedence(y[i])){
					postfix += data.top();
					postfix += " ";
					data.pop();
				}
				data.push(y[i]);
			}
		}
	}
	while(!data.empty()){
		postfix += data.top();
		postfix += " ";
		data.pop();
	}
	return postfix;
}

int main(){
	string z; getline(cin,z);
	string new_z="";
	for(i=0;i<z.length();i++){
		if(z[i]==' '){
			continue;
		
		}
		else{
			new_z+=z[i];	
		}		
	}
	cout <<"Print : ";
	cout << convert(new_z);
	
	return 0;
}
