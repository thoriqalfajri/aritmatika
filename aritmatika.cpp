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



#include <iostream> // no 3
#include <stack>
#include <ctype.h>
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
double applyOp(double num1, double num2, char op){
    switch(op){
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        }
    return 0;
}
void calculate(string input){
	stack<double> data;
	stack<char>operasi;
	
	for(i=0; i<input.length(); i++){
		if(isdigit(input[i])){
			int value=0;
			while(i<input.length() && isdigit(input[i])){
				value = (value*10) + (input[i] - '0');
				i++;
			}
			i--;
			data.push(value);
		}
		else if(input[i] == '(')
			operasi.push(input[i]);
		else if(input[i] == ')'){
			while(!operasi.empty() && operasi.top() != '('){
				if(operasi.top() == '%'){
					int value2 = data.top(); data.pop();
                    int value1 = data.top(); data.pop();
                    operasi.pop();
                    data.push(value1%value2);
				} else {
					double value2 = data.top(); data.pop();
                    double value1 = data.top(); data.pop();
                    char op = operasi.top(); operasi.pop();
                    data.push(applyOp(value1, value2, op));
				}
			}
			if(!operasi.empty())
				operasi.pop();
		} else {
			if(input[i] == '-'){
				if(i==0){
					if(isdigit(input[i+1])){
						i++;
						int value=0;
						while(i<input.length() && isdigit(input[i])){
							value = (value*10) + (input[i] - '0');
							i++;
						}
						i--;
						data.push(value*-1);
					} else {
						data.push(-1);
						operasi.push('*');
					}
				} else {
					while(!operasi.empty() && precedence(operasi.top()) >= precedence(input[i]) && !isOp(input[i-1])){
						if(operasi.top() == '%'){
							int value2 = data.top(); data.pop();
		                    int value1 = data.top(); data.pop();
		                    operasi.pop();
		                    data.push(value1%value2);
						} else {
							double value2 = data.top(); data.pop();
		                    double value1 = data.top(); data.pop();
		                    char op = operasi.top(); operasi.pop();
		                    data.push(applyOp(value1, value2, op));
						}
					}
					if((isdigit(input[i+1]) || input[i+1]=='(') && (isdigit(input[i-1]) || input[i-1]==')'))
						operasi.push(input[i]);
					else{
						data.push(-1);
						operasi.push('*');
					}
				} 
			} else {
				while(!operasi.empty() && precedence(operasi.top()) >= precedence(input[i])){
					if(operasi.top() == '%'){
						int value2 = data.top(); data.pop();
		                int value1 = data.top(); data.pop();
		                operasi.pop();
		                data.push(value1%value2);
					} else {
						double value2 = data.top(); data.pop();
		                double value1 = data.top(); data.pop();
		                char op = operasi.top(); operasi.pop();
		                data.push(applyOp(value1, value2, op));
					}
				}
				operasi.push(input[i]);
			}
		}
	}
	while(!operasi.empty()){
		if(operasi.top() == '%'){
			int value2 = data.top(); data.pop();
		    int value1 = data.top(); data.pop();
		    operasi.pop();
		    data.push(value1%value2);
		} else {
			double value2 = data.top(); data.pop();
		    double value1 = data.top(); data.pop();
		    char op = operasi.top(); operasi.pop();
		    data.push(applyOp(value1, value2, op));
		}
	}
	cout << data.top() << endl;
}

int main(){
	string ekspresi; getline(cin,ekspresi);
	string new_ekspresi="";
	for(i=0;i<ekspresi.length();i++){
		if(ekspresi[i]==' ')
			continue;
		else
			new_ekspresi+=ekspresi[i];
	}
	calculate(new_ekspresi);
	
	return 0;
}
