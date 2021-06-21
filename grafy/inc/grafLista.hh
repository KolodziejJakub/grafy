#ifndef GRAFLISTA_HH
#define GRAFLISTA_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include "ogolny.hh"

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

struct Lista {

    int punkt;
    int waga;

    Lista *nastepny;
};

void push( Lista * & poczatek, int punkt, int waga );
void popf( Lista * & poczatek );
void pout( Lista * & poczatek );

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

class grafLista : public Graf {

    protected:

        Lista **lista;

    public:

        //  cykl zycia
        grafLista( int V );
        grafLista();
        ~grafLista();

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