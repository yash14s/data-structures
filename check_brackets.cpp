#include <iostream>
#include <stack>
#include <string>
using namespace std;

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
	int pos = -1;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket b(next,position+1);
            opening_brackets_stack.push(b);
            
        }

        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.empty())
            {
            	pos = position+1;
            	break;
			}
			
			Bracket b = opening_brackets_stack.top();
			opening_brackets_stack.pop();
			if(b.Matchc(next)==false)
			{
				pos = position+1;
				break;
			}
        }
    }

    if(opening_brackets_stack.empty()==true && pos==-1)
    cout<<"Success";
    
    else if(pos>-1)
    cout<<pos;
	
	else
	{
		while(opening_brackets_stack.size()>1)
		opening_brackets_stack.pop();
		
		pos = opening_brackets_stack.top().position;
		cout<<pos; 
	}

    return 0;
}
