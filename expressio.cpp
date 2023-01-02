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

node* expressio::copy_tree(node *n) {
    /* Pre: cert */
    /* Post: si n és NULL, el resultat és NULL; sinó,
   el resultat apunta al primer node d'un arbre binari
   de nodes que són còpia de l'arbre apuntat per n */
    node* m;
    if (n == NULL) m = NULL;
    else {
        m = new node;
        try {
            m->info = n->info;
            m->f_esq = copy_tree(n->f_esq);
            m->f_dret = copy_tree(n->f_dret);
        } catch(...) {
            delete m;
            throw;
        }
    }
    return m;
}

node* expressio::delete_tree(node* n) {
    /* Pre: cert */
    /* Post: no fa res si m és NULL, sinó allibera
    espai dels nodes de l'arbre binari apuntat per m */
    if (n != nullptr) {
        delete_tree(n->f_esq);
        delete_tree(n->f_dret);
        delete n;
    }
}

bool expressio::equal_tree(node* n, node* m) {
    bool equal(true);
    if (n != nullptr) {
        if (n->info != m->info) 
            equal = false;
        else
            equal = equal_tree(n->f_esq, m->f_esq) and equal_tree(n->f_dret, m->f_dret);
    }
    return equal;
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

void expressio::variables(list<string> & l, node* n) {
    if (n != nullptr) {
        if ((n->info).c_actual == VARIABLE)
            l.push_back(n->info);
        variables(l, n->f_esq);
        variables(l, n->f_dret);
    }
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
    _arrel = copy_tree(e._arrel);
}

expressio::expressio & operator=(const expressio & e) throw(error) {
    if (this != e) {
        node* aux;
        aux = copy_tree(e._arrel);
        delete_tree(_arrel);
        _arrel = aux;
    }
    return (*this);
}

expressio::~expressio() throw(error) {
    delete_tree(_arrel);
}

operator bool() const throw() {

}

bool expressio::operator==(const expressio & e) const throw() {
    return equal_tree(_arrel, e._arrel);
}

bool expressio::operator!=(const expressio & e) const throw() {
    return !(*this == e);
}

void expressio::vars(list<string> & l) const throw(error) {
    variables(l, _arrel);
}

void expressio::apply_substitution(const string & v, const expressio & e) throw(error) {

}

void expressio::simplify_one_step() throw(error) {

}

void expressio::simplify() throw(error) {

}

void expressio::list_of_tokens(list<token> & lt) throw(error) {
    
}