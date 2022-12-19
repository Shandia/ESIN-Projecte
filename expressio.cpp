#include "expressio.hpp"

// Metodes privats
node* expressio::insert(node *n, token t) {
    if (n == nullptr) 
        return new node(t);
    
}

// Metodes publics
expressio::expressio(const token t = token()) throw(error) {
    if (t.c_actual >= NULLTOK and t.c_actual <= VAR_PERCENTATGE) {
        _arrel = new node;
        _arrel->info = t;
        _arrel->f_esq = nullptr;
        _arrel->f_dret = nullptr;
    }
    else throw(ErrorSintactic);
}

expressio::expressio(const list<token> & l) throw(error) {
    if (l.empty()) throw (ErrorSintactic);
    list<token>::iterator it;
    for (it = l.begin(); it != l.end(); it++) {
        _arrel = insert ( _arrel , *it);
    }
}

expressio::expressio(const expressio & e) throw(error) {
    
}

expressio::expressio & operator=(const expressio & e) throw(error) {

}

expressio::~expressio() throw(error) {

}

operator bool() const throw() {

}

bool expressio::operator==(const expressio & e) const throw() {

}

bool expressio::operator!=(const expressio & e) const throw() {

}

void expressio::vars(list<string> & l) const throw(error) {

}

void expressio::apply_substitution(const string & v, const expressio & e) throw(error) {

}

void expressio::simplify_one_step() throw(error) {

}

void expressio::simplify() throw(error) {

}

void expressio::list_of_tokens(list<token> & lt) throw(error) {
    
}