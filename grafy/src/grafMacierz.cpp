#include "grafMacierz.hh"

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

grafMacierz::grafMacierz( int V ) {

    this->E = 0;
    this->V = V;

    //  inicjalizacja macierzy
    this->macierz = new int * [V];
    for( int i = 0; i < V; i++ ) {
        this->macierz[i] = new int [V];
    }

    for( int i = 0; i < V; i++ ) {
        for( int j = 0; j < V; j++ ) {
            this->macierz[i][j] = PUSTY;
        }
    }
}

grafMacierz::~grafMacierz() {
    
   //  for( int i = 0; i < V; i++ ) {
    //    delete [] this->macierz[i];
   // }

   // delete [] this->macierz;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void grafMacierz::dodajKrawedz( int v, int w, int o ) {

    if( !this->saSasiednie( v, w ) ) {

        this->macierz[v][w] = o;
        this->macierz[w][v] = o;

        this->E++;
    }
}

void grafMacierz::usunKrawedz( int v, int w ) {

    if( this->saSasiednie( v, w ) ) {

        this->macierz[v][w] = PUSTY;
        this->macierz[w][v] = PUSTY;

        this->E--;
    }
}

void grafMacierz::wezWszystkieKrawedzie( Krawedz * tablica ) {

    int iterator = 0;

    for( int i = 0; i < this->V; i++ ) {
        for( int j = i; j > -1; j-- ) {

            if( this->macierz[i][j] != PUSTY ) {
                tablica[iterator++] = this->wezKrawedz( i, j );
            }
        }
    }
}

bool grafMacierz::saSasiednie( int v, int w ) {

    if( this->macierz[v][w] != PUSTY ) { return true; }
    if( this->macierz[w][v] != PUSTY ) { return true; }

    return false;
}

Krawedz grafMacierz::wezKrawedz( int v, int w ) {

    if( !this->saSasiednie( v, w ) ) {
        throw runtime_error( " Dostep do niezainicjalizowany jest niedzowolony! " );
    }

    if( this->macierz[v][w] != PUSTY ) return { v, w, this->macierz[v][w] };
    if( this->macierz[w][v] != PUSTY ) return { w, v, this->macierz[v][w] };

    throw runtime_error( " Krawedz nie zostala odnaleziona! " );
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void grafMacierz::rysuj() {

    for( int i = 0; i < this->V; i++ ) {
        for( int j = 0; j < this->V; j++ ) {

            if( this->macierz[i][j] != PUSTY ) {
                cout << " ( " << i << " -> " << j << " | [ " << this->macierz[i][j] << " ] ) ";
            }
        }

        cout << endl;
    }
}

void grafMacierz::wypelnij( int gestosc ) {

    for( int i = 0; i < this->V; i++ ) {
        for( int j = 0; j < this->V; j++ ) {
            this->usunKrawedz( i, j );
        }
    }
    
    for( int i = 0; i < this->V; i++ ) {
        for( int j = i; j < this->V; j++ ) {

            if( j == i ) { continue; }  //  zapobiega powstaniu petli

            if( losoj<int>( 1, 100 ) <= ( 100 - gestosc ) ) { continue; }

            this->dodajKrawedz( i, j, losoj<int>( 1, this->V ));
        }
    }
}