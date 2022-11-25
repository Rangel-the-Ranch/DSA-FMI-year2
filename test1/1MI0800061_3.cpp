#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;
void removeFirstLetter(string& word){
    const size_t size = word.size();
    string result;
    for(size_t i=1; i<size; i++){
        result += word[i];
    }
    word = result;
}

bool readInQueue(queue<char>& que , string word){
    //Взимам параметъра с копие защото ще го модифицирам в функцията
    stack<char> remaining;
    bool isTrue = false;
    while ( !que.empty() ){
        if(word.empty()){
            while(!que.empty()){
                remaining.push(que.front());
                que.pop();
            }
            isTrue = true;
            break;
        }
        if( que.front() == word[0] ){
            que.pop();
            removeFirstLetter(word);
            //cout<<"z";
        }else{
            remaining.push(que.front());
            que.pop();
        }
        
    }
    while( !remaining.empty() ){
        que.push( remaining.top() );
        remaining.pop();
    }
    return isTrue;
}


int main(){

    string A = "oAr";
    queue<char> q;
    q.push('w');
    q.push('o');
    q.push('a');
    q.push('r');
    q.push('d');
    cout<<readInQueue(q,A)<<" ";
    //std::cout<<q.size();
}