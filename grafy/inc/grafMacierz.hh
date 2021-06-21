#ifndef GRAFMACIERZ_HH
#define GRAFMACIERZ_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include "ogolny.hh"

#define PUSTY  -1

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

class grafMacierz : public Graf {

    protected:

        int **macierz;

    public:

        //  cykl zycia
        grafMacierz( int V );
        grafMacierz();
        ~grafMacierz();

        //  obsluga
        void dodajKrawedz( int v, int w, int o );
        void usunKrawedz( int v, int w );
        void wezWszystkieKrawedzie(  Krawedz * tablica  );

        bool saSasiednie( int v, int w );
        Krawedz wezKrawedz( int v, int w );

        inline int wezE() { return this->E; }
        inline int wezV() { return this->V; }

        //  zarzadzanie
        void wypelnij( int gestosc );
        void rysuj();
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif