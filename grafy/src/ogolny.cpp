#include "ogolny.hh"

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Krawedz::operator = ( Krawedz dane ) {
    this->v = dane.v;
    this->w = dane.w;
    this->o = dane.o;
}

bool Krawedz::operator > ( Krawedz dane ) { if( this->o > dane.o ) { return true; } else { return false; } }

bool Krawedz::operator < ( Krawedz dane ) { if( this->o > dane.o ) { return true; } else { return false; } }

bool Krawedz::operator == ( Krawedz dane ) { if( this->o > dane.o ) { return true; } else { return false; } }

bool Krawedz::operator >= ( Krawedz dane ) { if( this->o > dane.o ) { return true; } else { return false; } }

bool Krawedz::operator <= ( Krawedz dane ) { if( this->o > dane.o ) { return true; } else { return false; } }

istream & operator >> ( istream & str, Krawedz & dane ) {
    str >> dane.v >> dane.w >> dane.o;
    return str;
}

ostream & operator << ( ostream & str, Krawedz & dane ) {
    str << " ( " << dane.v << " -> " << dane.w << " | [ " << dane.o << " ] ) ";
    return str;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */