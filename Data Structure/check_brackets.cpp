#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    bool unfinished = 0;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next,position));
        }

        if (next == ')' || next == ']' || next == '}') {
            bool answer;
            if(!opening_brackets_stack.empty()){
                answer = opening_brackets_stack.top().Matchc(next);
            }else{
                std::cout<<position+1;
                unfinished = 1;
                break;
            }
           
            if(answer == 0){
                std::cout<<position+1;
                unfinished = 1;
                break;
            }else{
                opening_brackets_stack.pop();
            }
        }
    }

    if(opening_brackets_stack.empty() && unfinished == 0){
        std::cout << "Success";
    }else if(!opening_brackets_stack.empty() && unfinished == 0){
        std::cout << opening_brackets_stack.top().position+1;
    }
    std::cout<<"\n";
    // Printing answer, write your code here

    return 0;
}
