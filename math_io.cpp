#include "math_io.hpp"

void math_io::scan(const string & s, list<token> & lt) throw(error) {
    int size = s.size();
    
    for(int i = 0; i < size; i++) {
        // Constant entera (int)
        // Constant racional
        // Constant real (double)
        // CT_E
        if (s[i] == 'e')
            lt.push_back(token(CT_E));
        // Variable
        // Percentatge
        else if (s[i] == '%')
            lt.push_back(token(VAR_PERCENTATGE));
        // Suma i signe positiu
        else if(s[i] == '+') {
            if (((s[i+1] >= '0') and (s[i+1] <= '9')) and 
                ((s[i-1] >= '0') and (s[i-1] <= '9'))) 
                lt.push_back(token(SUMA));
            else
                lt.push_back(token(SIGNE_POSITIU));
        }
        // Resta i canvi de signe
        else if (s[i] == '-') {
            if (((s[i+1] >= '0') and (s[i+1] <= '9')) and 
                ((s[i-1] >= '0') and (s[i-1] <= '9')))
                lt.push_back(token(RESTA));
            else 
                lt.push_back(token(CANVI_DE_SIGNE));
        }
        // Multiplicacio
        else if (s[i] == '*')
            lt.push_back(token(MULTIPLICACIO));
        // Divisio
        else if (s[i] == '/')
            lt.push_back(token(DIVISIO));
        // Exponenciacio
        else if (s[i] == '^')
            lt.push_back(token(EXPONENCIACIO));
        // Arrel quadrada
        else if (s[i] == 's' and s[i+1] == 'q' and s[i+2] == 'r' and s[i+3] == 't') {
            lt.push_back(token(SQRT));
            i += 3;
        }
        // Funcio exponencial
        else if (s[i] == 'e' and s[i+1] == 'x' and s[i+2] == 'p') {
            lt.push_back(token(EXP));
            i += 2;
        }
        // Logaritme
        else if (s[i] == 'l' and s[i+1] == 'o' and s[i+2] == 'g') {
            lt.push_back(token(LOG));
            i += 2;
        }
        // Operacio evalf
        else if (s[i] == 'e' and s[i+1] == 'v' and s[i+2] == 'a' and s[i+3] == 'l' and s[i+4] == 'f') {
            lt.push_back(token(EVALF));
            i += 4;
        }
        // Obrir parentesis
        else if (s[i] == '(')
            lt.push_back(token(OBRIR_PAR));
        // Tancar parentesis
        else if (s[i] == ')')
            lt.push_back(token(TANCAR_PAR));
        // Coma
        // Assignacio
        else if (s[i] == ':' and s[i+1] == '=') {
            lt.push_back(token(ASSIGNACIO));
            i++;
        }
        // Desassignacio
        else if (s[i] == 'u' and s[i+1] == 'n' and s[i+2] == 'a' and s[i+3] == 's' and s[i+4] == 's' and s[i+5] == 'i' 
                 and s[i+6] == 'g' and s[i+7] == 'n') {
            lt.push_back(token(DESASSIGNACIO));
            i += 7;
        }
        // Byebye
        else if (s[i] == 'b' and s[i+1] == 'y' and s[i+2] == 'e' and
                 s[i+3] == 'b' and s[i+4] == 'y' and s[i+5] == 'e') {
            lt.push_back(token(BYEBYE));
            i += 5;
        }

        else
            throw(ErrorLexic);
    }
}

string math_io::tostring(const list<token> & lt) {
    list<token>::iterator it;
    string s;
    for (it = lt.begin(); it != lt.end(); ++it) {
        // Constant entera (int)
        if ((*it).tipus() == CT_ENTERA) {
            string aux = int((*it).valor_enter());
            s.insert(s.end(), aux);
        }
        // Constant racional
        else if ((*it).tipus() == CT_RACIONAL) {
            
        }
        // Constant real (double)
        // CT_E
        // Variable
        // Percentatge
        // Suma i signe positiu
        // Resta i canvi de signe
        // Multiplicacio
        // Divisio
        // Exponenciacio
        // Arrel quadrada
        // Funcio exponencial
        // Logaritme
        // Operacio evalf
        // Obrir parentesis
        // Tancar parentesis
        // Coma
        // Assignacio
        // Desassignacio
        // Byebye
    }
}