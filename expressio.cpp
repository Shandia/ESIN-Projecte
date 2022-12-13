#include "expressio.hpp"

/* Constructora d'una expressió formada per un sol token: un operand. Si
     s'utiliza el valor del token per defecte es construeix la que
     anomenem "expressió buida". Si el tipus del token no és el del token
     per defecte (NULLTOK), ni el d'una CT_ENTERA, CT_RACIONAL, CT_REAL,
     CT_E, VARIABLE o VAR_PERCENTAtGE es produeix un error sintàctic. */
expressio(const token t = token()) throw(error) {
    if ((t.c_actual >= 0 and t.c_actual <= 3) or t.c_actual == 5)
    _arrel = t;

}