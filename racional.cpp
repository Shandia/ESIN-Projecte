#include "racional.hpp"

/* 
    Cost: Operacions amb costos constants més cost de la funció reduce 
    Per tant, O(1) + O(n*log n) = O(n*log n)
*/
explicit racional::racional(int n = 0, int d = 1) throw(error)
{
    if (d == 0)
        throw(DenominadorZero);
    else
    {
        _p = d < 0 ? -n: n;
        _q = d < 0 ? -d : d;
        reduce();
    }
}

/* 
    Cost: Operacions amb costos constants més cost de la funció reduce 
    Per tant, O(1) + O(n*log n) = O(n*log n)
*/
racional::racional(const racional &r) throw(error)
    : _p{r._p},
      _q{r._q},
{
    if (_q == 0)
        throw(DenominadorZero);
    reduce();
}

// Cost: Operacions amb costos constant: O(1)
racional &racional::operator=(const racional &r) throw(error)
{
    racional aux(r);
    return aux;
}

racional::~racional() throw() {}

// Consultores. La part_entera d'un racional pot ser
// positiva o negativa. El residu SEMPRE és un racional positiu.
// Cost: Operacions amb costos constant: O(1)
int racional::num() const throw()
{
    return _p;
}

// Cost: Operacions amb costos constant: O(1)
int racional::denom() const throw()
{
    return _q;
}

// Cost: Operacions amb costos constant: O(1)
int racional::part_entera() const throw()
{
    // Si la part entera és negativa, se li ha de restar 1 unitat per tenir sempre el residu positiu
    return _p < 0 ? ((_p/_q)-1) : (_p/_q);
}

/*
    Operacions amb costos constants més el cost de la funció part_entera
    Per tant, O(1) + O(1) = O(1)
*/
racional racional::residu() const throw()
{
    int aux = part_entera();
    aux *= _q;
    if (aux < 0) {
        aux += 2;
        aux *= -1;
        aux = -1*_p - aux;
    }
    else aux = _p - aux;

    return (aux, _q);
}

/* Sobrecàrrega d'operadors aritmètics. Retorna un racional en la seva
   versió simplificada amb el resultat de l'operació. Es produeix un
   error al dividir dos racionals si el segon és 0.*/
/* 
    Cost: Operacions amb costos constants més el cost de la funció reduce
    Per tant, O(1) + O(n*log n) = O(n*log n)
*/ 
racional racional::operator+(const racional &r) const throw(error)
{
    // (apliquem el metode papallona)
    _p = (_p*r._q) + (_q*r_p);
    _q = _q*r._q;
    reduce();
    return *this;
}

/* 
    Cost: Operacions amb costos constants més el cost de la funció reduce
    Per tant, O(1) + O(n*log n) = O(n*log n)
*/ 
racional racional::operator-(const racional &r) const throw(error)
{
    // (apliquem el metode papallona)
    _p = (_p*r._q) - (_q*r._p);
    _q = _q * r._q;
    reduce();
    return *this;
}

/* 
    Cost: Operacions amb costos constants més el cost de la funció reduce
    Per tant, O(1) + O(n*log n) = O(n*log n)
*/ 
racional racional::operator*(const racional &r) const throw(error)
{
    _p *= r._p;
    _q *= r._q;
    reduce();
    return *this;
}

/* 
    Cost: Operacions amb costos constants més el cost de la funció reduce
    Per tant, O(1) + O(n*log n) = O(n*log n)
*/ 
racional racional::operator/(const racional &r) const throw(error)
{
    _p *= r._q;
    _q *= r._p;
    reduce();
    return *this; 
}

/* Sobrecàrrega de operadors de comparació. Retornen cert, si i només si
   el racional sobre el que s'aplica el mètode és igual (==), diferent
   (!=), menor (<), menor o igual (<=), major (>) o major o igual(>=)
   que el racional r.*/
// Cost: Operacions amb costos constant: O(1)
bool racional::operator==(const racional &r) const throw()
{
    return this->_p == r._p && this->_q == r._q;
}

// Cost: Operacions amb costos constant: O(1)
bool racional::operator!=(const racional &r) const throw()
{
    return !(*this == r);
}

// Cost: Operacions amb costos constant: O(1)
bool racional::operator<(const racional &r) const throw()
{
    bool result;
    if (!(*this > r) && !(*this == r))
        result = true;
    else
        result = false;

    return result;
}

// Cost: Operacions amb costos constant: O(1)
bool racional::operator<=(const racional &r) const throw()
{
    if (!(this > r))
        result = true;
    else
        result = false;

    return result;
}

// Cost: Operacions amb costos constant: O(1)
bool racional::operator>(const racional &r) const throw()
{
    bool result;
    if ((this->_p / this->_q) > (r._p / r._q))
        result = true;
    else
        result = false;

    return result;
}

// Cost: Operacions amb costos constant: O(1)
bool racional::operator>=(const racional &r) const throw()
{
    bool result;

    if (!(*this < r))
        result = true;
    else
        result = false;
}

/* 
    Cost: Decreixement geomètric. 
    Per cas directe, T(1) = O(0).
    Per la recurrència, T(n) = 1*T(n/2)+n per n >= 1
    Per tant, T(n) = O(n*log n)
*/
int racional::gcd(int p, int q)
{
    // Algoritme d'Euclides
    if (q == 0) 
        return p;
    
    return gcd(q, p % q);
}

/* 
    Cost: Operacions amb costos constants + cost de la funció gcd
    Per tant, O(1)+O(n*log n) = O(n*log n)
*/
void racional::reduce()
{ 
    if (this->_q < 0)
    {
        this->_p *= -1;
        this->_q *= -1;
    }

    int denom = gcd(this->_p, this->_q);
    this->_p /= denom;
    this->_q /= denom;
}

// Gestió d'errors.
static const int DenominadorZero = 21;