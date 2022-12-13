#include "expressio.hpp"

expressio(const token t = token()) throw(error) {
    if (t.c_actual >= NULLTOK and t.c_actual <= VAR_PERCENTATGE) {
        _arrel = new node;
        _arrel->info = t;
        _arrel->f_esq = nullptr;
        _arrel->f_dret = nullptr;
    }
    else throw(ErrorSintactic);
}

expressio(const list<token> & l) throw(error) {

}

expressio(const expressio & e) throw(error) {

}

expressio & operator=(const expressio & e) throw(error) {

}

~expressio() throw(error) {

}

operator bool() const throw() {

}

bool operator==(const expressio & e) const throw() {

}

bool operator!=(const expressio & e) const throw() {

}

void vars(list<string> & l) const throw(error) {

}

void apply_substitution(const string & v, const expressio & e) throw(error) {

}

void simplify_one_step() throw(error) {

}

void simplify() throw(error) {

}

void list_of_tokens(list<token> & lt) throw(error) {
    
}