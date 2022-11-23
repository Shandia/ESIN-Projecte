#include "racional.hpp"

explicit racional::racional(int n = 0, int d = 1) throw(error)
{
    /* Cost: */
    if (d == 0)
        throw(DenominadorZero);
    else
    {
        _p = d < 0 ? -n: n;
        _q = d < 0 ? -d : d;
        reduce();
    }
}

racional::racional(const racional &r) throw(error)
    : _p{r._p},
      _q{r._q},
{
    /* Cost: */
    if (_q == 0)
        throw(DenominadorZero);
    reduce();
}

racional &racional::operator=(const racional &r) throw(error)
{
    /* Cost: */
    racional aux(r);
    return aux;
}

racional::~racional() throw() {}

// Consultores. La part_entera d'un racional pot ser
// positiva o negativa. El residu SEMPRE és un racional positiu.
int racional::num() const throw()
{
    /* Cost: */
    return _p;
}

int racional::denom() const throw()
{
    /* Cost: */
    return _q;
}

int racional::part_entera() const throw()
{
    /* Cost: */
    // Si la part entera és negativa, se li ha de restar 1 unitat per tenir sempre el residu positiu
    return _p < 0 ? ((_p/_q)-1) : (_p/_q);
}

racional racional::residu() const throw()
{
    /* Cost: */
    // 0,5 -> 1/2, hem de retornar en forma racional
    // return num%den;
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
racional racional::operator+(const racional &r) const throw(error)
{
    /* Cost:
     * Pre:
     * Post:
     * (apliquem el metode papallona)
     */
    _p = (_p*r._q) + (_q*r_p);
    _q = _q*r._q;
    reduce();
    return *this;
}

racional racional::operator-(const racional &r) const throw(error)
{
    /* Cost:
     * Pre:
     * Post:
     * (apliquem el metode papallona)
     */
    _p = (_p*r._q) - (_q*r._p);
    _q = _q * r._q;
    reduce();
    return *this;
}

racional racional::operator*(const racional &r) const throw(error)
{
    /* Cost:
     * Pre:
     * Post:
     */
    _p *= r._p;
    _q *= r._q;
    reduce();
    return *this;
}

racional racional::operator/(const racional &r) const throw(error)
{
    /* Cost:
     * Pre:
     * Post:
     */
    _p *= r._q;
    _q *= r._p;
    reduce();
    return *this; 
}

/* Sobrecàrrega de operadors de comparació. Retornen cert, si i només si
   el racional sobre el que s'aplica el mètode és igual (==), diferent
   (!=), menor (<), menor o igual (<=), major (>) o major o igual(>=)
   que el racional r.*/
bool racional::operator==(const racional &r) const throw()
{
    /* Cost:
     * Pre:
     * Post:
     */
    return this->_p == r._p && this->_q == r._q;
}

bool racional::operator!=(const racional &r) const throw()
{
    /* Cost:
     * Pre:
     * Post:
     */
    return !(*this == r);
}

bool racional::operator<(const racional &r) const throw()
{
    /* Cost:
     * Pre:
     * Post:
     */
    bool result;
    if (!(*this > r) && !(*this == r))
        result = true;
    else
        result = false;

    return result;
}

bool racional::operator<=(const racional &r) const throw()
{
    /* Cost:
     * Pre:
     * Post:
     */
    if (!(this > r))
        result = true;
    else
        result = false;

    return result;
}

bool racional::operator>(const racional &r) const throw()
{
    /* Cost:
     * Pre:
     * Post:
     */
    bool result;
    if ((this->_p / this->_q) > (r._p / r._q))
        result = true;
    else
        result = false;

    return result;
}

bool racional::operator>=(const racional &r) const throw()
{
    /* Cost:
     * Pre:
     * Post:
     */
    bool result;

    if (!(*this < r))
        result = true;
    else
        result = false;
}

int racional::gcd(int p, int q)
{
    // Euclid's Algorithm
    if (q == 0)
    {
        return p;
    }
    return gcd(q, p % q);
}

void racional::reduce()
{
    /* Cost:
     * Pre:
     * Post:
     */
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