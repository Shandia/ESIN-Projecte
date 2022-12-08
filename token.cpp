#include "token.hpp"

explicit token::token(codi cod = NULLTOK) throw(error) {

}

explicit token::token(int n) throw(error) {
    // fer error
    c_actual = CT_ENTERA;
    tkn.tkn_i = n;
}

explicit token::token(const racional & r) throw(error) {
    // fer error
    c_actual = CT_RACIONAL;
    tkn.tkn_r = r;
}

explicit token::token(double x) throw(error) {
    // fer error
    c_actual = CT_REAL;
    tkn.tkn_d = x;
}

explicit token::token(const string & var_name) throw(error) {
    if (var_name == "unassign" or var_name == "e" or var_name == "sqrt" 
        or var_name == "log" or var_name == "exp" or var_name == "evalf")
        throw (IdentificadorIncorrecte);
    unsigned int var_size = sizeof(var_name);
    for (int i = 0; i < var_size; i++) {
        if (var_name[i] < 65 or (var_name[i] > 90 and var_name[i] < 95)
            or var_name[i] == 96 or var_name[i] > 122)
            throw (IdentificadorIncorrecte);
        
    }
}