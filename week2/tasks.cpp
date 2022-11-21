#include<iostream>
#include<stack>
#include<string>
#include<cstring>

std::string taskOne(const std::string str){
    std::stack<char> temp;
    const size_t len = str.size();

    for(size_t i=0; i < len; i++){
        if(str[i] != '*'){
            temp.push(str[i]);
        }else{
            temp.pop();
        }
    }

    std::string result;
    while( !temp.empty() ){
        result = temp.top() + result;
        temp.pop();
    }

    return result;
}

bool taskTwo(const std::string str){
    std::stack<char> temp;
    const size_t len = str.size();

    for(size_t i=0; i<len ; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            temp.push(str[i]);
        }else if( str[i] == ')' ){
            if(temp.top() != '(' ){
                return false;
            }else{
                temp.pop();
            }
        }else if( str[i] == ']'){
            if(temp.top() != '[' ){
                return false;
            }else{
                temp.pop();
            }
        }else if(str[i] == '}'){
            if(temp.top() != '{' ){
                return false;
            }else{
                temp.pop();
            }
        }
    }
    return !str.empty();
}
int taskThree(const std::string str){
    std::stack<int> numbers;

    for (size_t i = 0; i < str.size(); i++) {
        if(isOperation(str[i])) {
            int snd = numbers.top();
            numbers.pop();

            int fst = numbers.top();
            numbers.pop();

            numbers.push(eval(fst, snd, str[i]));
        }
        else if(str[i] != ' ') {
            int number = 0;
            while(i < str.size() && isDigit(str[i])) {
                number *= 10;
                number += str[i] - '0';
                i++;
            }
            i--;
            numbers.push(number);
        }
    }
    return numbers.top();
}
int eval(const int fst, const int scd, const char sym){
    switch(sym){
    case '+':
        return fst + snd;  
    case '-':
        return fst - snd;
    case '*':
        return fst * snd;
    case '/':
        return fst / snd;
    }
}
bool isOperation(char c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}



int main(){
    //std::cout<<taskOne("aa*b*");
    //std::cout<<taskTwo("{[][()]}()");

}