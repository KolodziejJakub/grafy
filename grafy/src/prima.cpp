#include "prima.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

bool wZbiorzeMST( int v, int w, bool * wMST ) {

    if( v == w ) { return false; }

    if( wMST[v] && wMST[w] ) { return false; }

    if( !wMST[v] && !wMST[w] ) { return false; }

    return true;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Prima( grafLista data, bool rysuj ) {

    bool * wMST;

    int ilosc=data.wezV();
    wMST = new bool [ data.wezV() ];
    for( int i = 0; i < ilosc; i++ ) {
        wMST[i] = false;
    }

    wMST[0] = true; //ustawienie poczatkowej krawedzi jako odwiedzonej (w MST)

    int indeks = 0; //poczatkowe ustawienie indeksu i wagi na 0
    int waga = 0;

    /*   *   *   *   *   *   *   *   *   *   */

    while( indeks < ilosc - 1 ) { //krawedzie V-1 (poniewaz poczatkowa juz jest odwiedzona)

        int min = INF; 
        int v = -1;
        int w = -1;

        for( int i = 0; i < ilosc; i++ ) {
            for( int j = 0; j < ilosc; j++ ) {
                
                if( !data.saSasiednie( i, j ) ) { continue; } //jezeli nie sa sasiednie - przeszukuj dalej

                if( data.wezKrawedz( i, j ).o < min ) { //jezeli waga krawedzi jest mniejsza od minimalnej
                // ustaw odpowiedznio min, v,w

                    if( wZbiorzeMST( i, j, wMST )) {

                        min = data.wezKrawedz( i, j ).o;
                        v = i;
                        w = j;
                    }
                }
            }
        }

        if( v != -1 && w != -1 ) { //jezeli krawedz zostala zmieniona, ustaw jako odwiedzona, zmien indeks i wage

            indeks++;
            waga += min;

            wMST[v] = true;
            wMST[w] = true;

            if( rysuj ) {
                cout << v << " -> " << w << " | [ " << min << " ]"<< endl;
            }
        }
    }

    if( rysuj ) {
        cout << "MST waga = " << waga << endl;
    }

    /*   *   *   *   *   *   *   *   *   *   */
    
    // delete [] wMST;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Prima( grafMacierz data, bool rysuj ) {

    bool * wMST;

    wMST = new bool [ data.wezV() ];
    for( int i = 0; i < data.wezV(); i++ ) {
        wMST[i] = false;
    }

    wMST[0] = true;

    int indeks = 0;
    int waga = 0;

    /*   *   *   *   *   *   *   *   *   *   */

    while( indeks < data.wezV() - 1 ) {

        int min = INF;
        int v = -1;
        int w = -1;

        for( int i = 0; i < data.wezV(); i++ ) {
            for( int j = 0; j < data.wezV(); j++ ) {
                
                if( !data.saSasiednie( i, j ) ) { continue; }

                if( data.wezKrawedz( i, j ).o < min ) {

                    if( wZbiorzeMST( i, j, wMST )) {

                        min = data.wezKrawedz( i, j ).o;
                        v = i;
                        w = j;
                    }
                }
            }
        }

        if( v != -1 && w != -1 ) {

            indeks++;
            waga += min;

            wMST[v] = true;
            wMST[w] = true;

            if( rysuj ) {
                cout << v << " -> " << w << " | [ " << min << " ]"<< endl;
            }
        }
    }

    if( rysuj ) {
        cout << "MST waga = " << waga << endl;
    }

    /*   *   *   *   *   *   *   *   *   *   */
    
    // delete [] wMST;
}