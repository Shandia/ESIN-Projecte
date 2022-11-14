#include "racional.hpp"

// Constructora. Construeix un racional en la seva versió simplificada.
// Es produeix un error si el denominador és 0.
explicit racional::racional(int n = 0, int d = 1) throw(error)
{
    /* Cost: */
    /* Pre: */
    /* Post: */
    if (d == 0)
        throw(DenominadorZero);
    else
    {
        this->numerator = n < 0 ? -n : n;
        this->denominator = d < 0 ? -d : d;
        reduce();
    }
}

// Constructora per còpia
racional::racional(const racional &r) throw(error)
    : _p{r._p},
      _q{r._q},
{
    /* Cost:
     * Pre:
     * Post:
     */
    if (this->_q == 0)
        throw(DenominadorZero);
    reduce();
}

// Constructora per assignació
racional &racional::operator=(const racional &r) throw(error)
    : _p{r._p},
         _q{r._q}
{
    /* Cost:
     * Pre:
     * Post:
     */
    if (_q == 0)
        throw(DenominadorZero);
    reduce();
    return *this;
}

// Destructor
racional::~racional() throw()
{
    /* No es fa res ja que no utilizem memòria dinàmica */
}

// Consultores. La part_entera d'un racional pot ser
// positiva o negativa. El residu SEMPRE és un racional positiu.
int racional::num() const throw()
{
    /* Cost:
     * Pre:
     * Post:
     */
    return this->_p;
}

int racional::denom() const throw()
{
    /* Cost:
     * Pre:
     * Post:
     */
    return this->_q;
}

int racional::part_entera() const throw()
{
    /* Cost:
     * Pre:
     * Post:
     */
    return (this->_p / this->_q);
}

racional racional::residu() const throw()
{
    /* Cost:
     * Pre:
     * Post:
     */
    // 0,5 -> 1/2, hem de retornar en forma racional
    // return num%den;
}

/* Sobrecàrrega d'operadors aritmètics. Retorna un racional en la seva
   versió simplificada amb el resultat de l'operació. Es produeix un
   error al dividir dos racionals si el segon és 0.*/
racional racional::operator+(const racional &r) const throw(error)
{
    /* Cost:
     * Pre:
     * Post:
     */
    return racional{*this} += r;
}

racional racional::operator-(const racional &r) const throw(error)
{
    /* Cost:
     * Pre:
     * Post:
     */
    racional result(*this);

    result -= r;
    result.reduce();

    return result;
}

racional racional::operator*(const racional &r) const throw(error)
{
    /* Cost:
     * Pre:
     * Post:
     */
    racional result(*this);

    result *= r;
    result.reduce();

    return result;
}

racional racional::operator/(const racional &r) const throw(error)
{
    /* Cost:
     * Pre:
     * Post:
     */
    racional result(*this);
    result /= r;
    result.reduce();

    return result;
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
    return _p == r._p && _q == r._q;
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

    int denom = gcd(_p, _q);
    _p /= denom;
    _q /= denom;
    * /
}

// Gestió d'errors.
static const int DenominadorZero = 21;