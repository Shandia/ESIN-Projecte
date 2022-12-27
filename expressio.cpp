#include "expressio.hpp"
// En la documentació d’aquesta classe no serà necessari que indiqueu el cost dels mètodes.

// Metodes privats
node* expressio::insert(node *n, token t) {
    if (n == nullptr) 
        return new node(t);
    else {
        if (t < n->info)
            n->f_esq = insert(n->f_esq, t);
        else if (t > n->info)
            n->f_dret = insert(n->f_dret, t);
        else
            n->info = t;

        return n;
    }
}

bool expressio::sintaxis_correcte (const list<token> &l) {
    list<token>::iterator it;
    int parentesis = 0;
    for (it = l.begin(); it != l.end(); it++) {
        // Evaluacio parentesis
        if (*it.tipus() == OBRIR_PAR) {
            // SUMA, RESTA, MULTIPLICACIO, DIVISIO, EXPONENCIACIO, CANVI_DE_SIGNE, SIGNE_POSITIU
            if ((*(it+1).tipus()) >= SUMA and (*(it+1).tipus()) <= SIGNE_POSITIU)
            parentesis++;
        }
        else if (*it.tipus() == TANCAR_PAR) {
            parentesis--;
            if (parentesis < 0) return false;
        }

        // Evaluacio suma, resta, mutiplicacio, divisio
        else if ((*(it+1).tipus() >= SUMA) and (*(it+1).tipus() <= DIVISIO)) {
            if (*it == NULLTOK or )
        }
    }
    // Evaluacio parentesis (si es diferent que 0, vol dir que no tots els parentesis oberts s'han tancat, o a l'inreves)
    if (parentesis != 0) return false;
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

expressio::expressio(const list<token> &l) throw(error) {
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