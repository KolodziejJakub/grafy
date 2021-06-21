#ifndef KRUSKAL_HH
#define KRUSKAL_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <vector>

#include "grafMacierz.hh"
#include "grafLista.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

class UnikalnyZbior {

    private:

        int n;      //  rozmiar
        int * p;
        int * r;

    /*   *   *   *   *   *   *   *   *   *   */

    public:

        UnikalnyZbior( int n );

        void scal( int x, int y );
        int znajdz( int v );
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Kruskal( grafMacierz data, bool rysuj );
void Kruskal( grafLista data, bool rysuj );

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif