#include "kruskal.hh"
#include "prima.hh"

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */


void test( int gestosc, int powtorzenia, int rozmiar ) {


    clock_t start, stop;

    long unsigned int czasGLK = 0;
    long unsigned int czasGMK = 0;

    long unsigned int czasGLP = 0;
    long unsigned int czasGMP = 0;

    /*   *   *   *   *   *   *   *   *   *   */

    //  Testy algorytmu Kruskala
    for( int i = 0; i < powtorzenia; i++ ) {
     //cout<<"powtorzenie "<<i<<endl;
        grafLista GL( rozmiar );
        grafMacierz GM( rozmiar );

        GL.wypelnij( gestosc );
        GM.wypelnij( gestosc );

        /*   *   *   *   *   */

        start = clock();

        Kruskal( GL, false );

        stop = clock();

        czasGLK += ( stop - start );

        /*   *   *   *   *   */

        start = clock();

        Kruskal( GM, false );

        stop = clock();

        czasGMK += ( stop - start );
    }

    cout << endl;
    cout << " Kruskal gestosc -> " << gestosc << " <- ok. " << endl;

    //  Testy algorytmu Prima
    for( int i = 0; i < powtorzenia; i++ ) {
    //cout<<"powtorzenie "<<i<<endl;
        grafLista GL( rozmiar );
        grafMacierz GM( rozmiar );

        GL.wypelnij( gestosc );
        GM.wypelnij( gestosc );

        /*   *   *   *   *   */

        start = clock();

        Prima( GL, false );

        stop = clock();

        czasGLP += ( stop - start );

        /*   *   *   *   *   */

        start = clock();

        Prima( GM, false );

        stop = clock();

        czasGMP += ( stop - start );
    }

    cout << endl;
    cout << " Prima gestosc -> " << gestosc << " <- ok. " << endl;

    /*   *   *   *   *   *   *   *   *   *   */

    cout << endl << endl << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << " Testy dla gęstości :: " << gestosc << " %" << endl;

    cout << endl << endl;
    cout << " Graf zaimplementowany na liście sąsiedzctwa :: " << endl;
    cout << " -> całkowity czas wykonywania algorytmu Kruskala: " << 1000000 * czasGLK / CLOCKS_PER_SEC << " us" << endl;
    cout << " -> całkowity czas wykonywania algorytmu Prima: " << 1000000 * czasGLP / CLOCKS_PER_SEC << " us" << endl;
    cout << endl;
    cout << " -> średni czas wykonywania algorytmu Kruskala: " << ( 1000000 / powtorzenia ) * czasGLK / CLOCKS_PER_SEC << " us" << endl;
    cout << " -> średni czas wykonywania algorytmu Prima: " << ( 1000000 / powtorzenia ) * czasGLP / CLOCKS_PER_SEC << " us" << endl;

    cout << endl << endl;
    cout << " Graf zaimplementowany na macierzy sąsiedzctwa :: " << endl;
    cout << " -> całkowity czas wykonywania algorytmu Kruskala: " << 1000000 * czasGMK / CLOCKS_PER_SEC << " us" << endl;
    cout << " -> całkowity czas wykonywania algorytmu Prima: " << 1000000 * czasGMP / CLOCKS_PER_SEC << " us" << endl;
    cout << endl;
    cout << " -> średni czas wykonywania algorytmu Kruskala: " << ( 1000000 / powtorzenia ) * czasGMK / CLOCKS_PER_SEC << " us" << endl;
    cout << " -> średni czas wykonywania algorytmu Prima: " << ( 1000000 / powtorzenia ) * czasGMP / CLOCKS_PER_SEC << " us" << endl;
}

int main() {

    srand( time(NULL) );

    /*   *   *   *   *   *   *   *   *   *   */

    int rozmiar = 300;

    /*   *   *   *   *   *   *   *   *   *   */

    int gestosc[4] = { 25, 50, 75, 100 };
    int powtorzenia;

    cout << " Ilość powtórzeń N : ";
    cin >> powtorzenia;

    /*   *   *   *   *   *   *   *   *   *   */

    for( int i = 0; i < 4; i++ ) {
        test( gestosc[i], powtorzenia, rozmiar );
    }

    /*   *   *   *   *   *   *   *   *   *   */

    cin.ignore();
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */