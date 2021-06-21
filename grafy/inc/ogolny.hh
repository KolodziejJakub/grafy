#ifndef OGOLNY_HH
#define OGOLNY_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>
#include <ctime>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#define INF 0x7FFFFFFF

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

struct Krawedz {
    
    int v;  //  pierwszy wierzcholek
    int w;  //  drugi wierzholek
    int o;  //  waga krawedzi

    /*   *   *   *   *   *   *   *   *   *   */

    void operator = ( Krawedz );
    bool operator > ( Krawedz );
    bool operator < ( Krawedz );

    bool operator == ( Krawedz );
    bool operator >= ( Krawedz );
    bool operator <= ( Krawedz );
};

istream & operator >> ( istream &, Krawedz & );
ostream & operator << ( ostream &, Krawedz & );

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

class Graf {

    protected:

        int E;
        int V;

    public:

        //  cykl zycia
        Graf( int V ) { this->V = V; }
        Graf() {}
        ~Graf() {}

        /*
            = 0; na koncu funkci oznacza, iz jest ona 100% wirtualna
        */

        //  obsluga
        virtual void dodajKrawedz( int v, int w, int o ) = 0;
        virtual void usunKrawedz( int v, int w ) = 0;

        virtual void wezWszystkieKrawedzie( Krawedz * tablica ) = 0;
        virtual bool saSasiednie( int v, int w ) = 0;
        virtual Krawedz wezKrawedz( int v, int w ) = 0;

        inline int wezE() { return this->E; }
        inline int wezV() { return this->V; }

        //  zarzadzanie
        virtual void wypelnij( int gestosc ) = 0;
        virtual void rysuj() = 0;
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
int losoj( int min, int max ) {
    T tmp = ( rand() % ( max - min ) ) + min ;
    return tmp;
}

template <typename T>
void kopiec( T *arr, int *args ) {

    int n = args[0];
    int i = args[1];

    int high = i;
    int l = 2*i + 1;
    int r = 2*i + 2;


    if(( l < n ) && ( arr[l] > arr[high] )) {
        high = l;
    }

    if(( r < n ) && ( arr[r] > arr[high] )) {
        high = r;
    }

    if( high != i ) {

        int new_args[] = { n, high };

        swap( arr[i], arr[high] );
        kopiec( arr, new_args );
    }
}

template <typename T>
void sortowanieKopiec( T *arr, int n ) {

    for( int i = n / 2 - 1; i >= 0; i-- ) {
        int new_args[] = { n, i };
        kopiec( arr, new_args );
    }

    for( int i = n - 1; i >= 0; i-- ) {

        int new_args[] = { i, 0 };

        swap( arr[0], arr[i] );
        kopiec( arr, new_args );
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif