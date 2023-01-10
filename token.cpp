#include "token.hpp"

// Cost: Operacions amb costos constants: O(1)
token::token(codi cod) throw(error) {
    if (cod == CT_ENTERA or cod == CT_RACIONAL or cod == CT_REAL or cod == VARIABLE)
        throw (ConstructoraInadequada);
    c_actual = cod;
}

token::token(int n) throw(error) {
    // tractament error
    c_actual = CT_ENTERA;
    tkn.tkn_i = n;
}

token::token(const racional & r) throw(error) {
    // tractament error
    c_actual = CT_RACIONAL;
    tkn.tkn_r = r;
}

token::token(double x) throw(error) {
    // tractament error
    c_actual = CT_REAL;
    tkn.tkn_d = x;
}

/*
    Cost: Operacions amb costos constants
          Pel recorregut de tots els caracters de la variable, si tots els caracters son correctes, 
          tindrem un cost lineal.
          Per tant, com a màxim el cost sera lineal i dependra de la mida(n) de la variable: O(n) = n
*/
token::token(const string & var_name) throw(error) {
    // la variable no pot ser una paraula reservada
    if (var_name == "unassign" or var_name == "e" or var_name == "sqrt" 
        or var_name == "log" or var_name == "exp" or var_name == "evalf")
        throw (IdentificadorIncorrecte);
    unsigned int var_size = sizeof(var_name);
    // la variable no pot contenir cap caracter fora de les lletres majuscules, minuscules o el caracter subratllat
    for (unsigned int i = 0; i < var_size; i++) {
        if (var_name[i] < 65 or (var_name[i] > 90 and var_name[i] < 95)
            or var_name[i] == 96 or var_name[i] > 122)
            throw (IdentificadorIncorrecte);
    }
    c_actual = VARIABLE;
    tkn.tkn_s = var_name;
}

token::token(const token & t) throw(error) {
    // tractament error
    c_actual = t.c_actual;
    if ((c_actual >= CT_ENTERA and c_actual <= CT_REAL) or c_actual == VARIABLE)
        tkn = t.tkn;
}

token &token::operator=(const token & t) throw(error) {
    // tractament error
    token tk(t);
    return tk;
}

token::~token() throw() {}

// Cost: Operacions amb costos constants: O(1)
codi token::tipus() const throw() {
    return c_actual;
}

// Cost: Operacions amb costos constants: O(1)
int token::valor_enter() const throw(error) {
    if (c_actual == CT_ENTERA) {
        return tkn.tkn_i;
    }
    else throw(ConsultoraInadequada);
}

// Cost: Operacions amb costos constants: O(1)
racional token::valor_racional() const throw(error) {
    if (c_actual == CT_RACIONAL) {
        return tkn.tkn_r;
    }
    else throw(ConsultoraInadequada);
}

// Cost: Operacions amb costos constants: O(1)
double token::valor_real() const throw(error) {
    if (c_actual == CT_REAL) {
        return tkn.tkn_d;
    }
    else throw(ConsultoraInadequada);
}

// Cost: Operacions amb costos constants: O(1)
string token::identificador_variable() const throw(error) {
    if (c_actual == VARIABLE) {
        return tkn.tkn_s;
    }
    else throw(ConsultoraInadequada);
}

// Cost: Operacions amb costos constants: O(1)
bool token::operator==(const token & t) const throw() {
    if (c_actual != t.c_actual) return false;

    // CT_ENTERA
    if (c_actual == CT_ENTERA) return tkn.tkn_i == t.tkn.tkn_i;

    // CT_RACIONAL
    if (c_actual == CT_RACIONAL) return tkn.tkn_r == t.tkn.tkn_r;

    // CT_REAL
    if (c_actual == CT_REAL) return tkn.tkn_d == t.tkn.tkn_d;

    // VARIABLE
    if (c_actual == VARIABLE) return tkn.tkn_s == t.tkn.tkn_s;

    return false;
}

// Cost: Operacions amb costos constants: O(1)
bool token::operator!=(const token & t) const throw() {
    return !(*this == t);
}

// Cost: Operacions amb costos constants: O(1)
bool token::operator>(const token & t) const throw(error) {
    if (t.c_actual < 7 or t.c_actual > 13) 
        throw (PrecedenciaEntreNoOperadors);
    if (c_actual < 7 or t.c_actual > 13)
        throw (PrecedenciaEntreNoOperadors);
    return (c_actual > t.c_actual);
}

// Cost: Operacions amb costos constants: O(1)
bool token::operator<(const token & t) const throw(error) {
    if (t.c_actual < 7 or t.c_actual > 13) 
        throw (PrecedenciaEntreNoOperadors);
    if (c_actual < 7 or t.c_actual > 13)
        throw (PrecedenciaEntreNoOperadors);
    return (c_actual < t.c_actual);
}