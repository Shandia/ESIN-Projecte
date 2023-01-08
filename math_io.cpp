#include "math_io.hpp"

void math_io::scan(const string & s, list<token> & lt) throw(error) {
    int size = s.size();
    
    for(int i = 0; i < size; i++) {
        if(s[i] == '+') {
            if (s[i+1] == ) lt.push_back(token(SUMA));
        }
        else if (s[i] == '-') {
            lt.push_back(token(RESTA));
        }
        else if (s[i] == '*')
            lt.push_back(token(MULTIPLICACIO));
        else if (s[i] == '/')
            lt.push_back(token(DIVISIO));
    }
}