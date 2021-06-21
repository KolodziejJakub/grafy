#include "grafLista.hh"

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void push( Lista * & poczatek, int punkt, int waga ) {

    Lista * lista = new Lista;

    lista->punkt = punkt;
    lista->waga = waga;
    lista->nastepny = poczatek;
    poczatek = lista;
}

void popf( Lista * & poczatek ) {

    Lista * lista;
    lista = poczatek;

    poczatek = lista->nastepny;
    delete lista;
}

void pout( Lista * & poczatek ) {

    Lista * lista;
    lista = poczatek;

    while( lista ) {
        cout << (( lista == poczatek ) ? " :: " : " => ") << "( " << lista->punkt << " [ " << lista->waga << " ] )";
        lista = lista->nastepny;
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

grafLista::grafLista( int V ) {

    this->E = 0;
    this->V = V;

    //  inicjacja listy
    this->lista = new Lista * [V];

    for( int i = 0; i < V; i++ ) {
        this->lista[i] = NULL;
    }
}

grafLista::~grafLista() {
    
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void grafLista::dodajKrawedz( int v, int w, int o ) {

    if( !this->saSasiednie( v, w ) ) {

        push( this->lista[v], w, o );
        push( this->lista[w], v, o );

        this->E++;
    }
}

void grafLista::usunKrawedz( int v, int w ) {

    if( this->saSasiednie( v, w ) ) {
        
        Lista * poczatek;
        Lista * lista;
        Lista * poprzedni;

        /*   *   *   *   *   */

        lista = this->lista[v];
        poczatek = this->lista[v];

        while( lista ) {
            
            if( lista->punkt == w ) {
                //  lista do usuniecia

                if( lista == poczatek ) {    //  lista poczatek

                    poczatek = lista->nastepny;

                } else {    //  wnetrze listy

                    if( lista->nastepny != NULL ) {  //  lista wnetrze
                        poprzedni->nastepny = lista->nastepny;
                    }

                    if( lista->nastepny == NULL ) {  //  lista ogon
                        poprzedni->nastepny = NULL;
                    }
                }

                break;
            }

            poprzedni = lista;
            lista = lista->nastepny;
        }

        /*   *   *   *   *   */
        
        lista = this->lista[w];
        poczatek = this->lista[w];

        while( lista ) {
            
            if( lista->punkt == v ) {
                //  lista do usuniecia

                if( lista == poczatek ) {    //  lista poczatek

                    poczatek = lista->nastepny;

                } else {    //  wnetrze listy

                    if( lista->nastepny != NULL ) {  //  lista wnetrze
                        poprzedni->nastepny = lista->nastepny;
                    }

                    if( lista->nastepny == NULL ) {  //  lista ogon
                        poprzedni->nastepny = NULL;
                    }
                }

                break;
            }

            poprzedni = lista;
            lista = lista->nastepny;
        }

        /*   *   *   *   *   */

        this->E--;
    }
}

void grafLista::wezWszystkieKrawedzie( Krawedz * tablica ) {

    int iterator = 0;

    for( int i = 0; i < this->V; i++ ) {
        for( int j = i; j > -1; j-- ) {
            
            if( this->saSasiednie( i, j ) ) {
                tablica[iterator++] = this->wezKrawedz( i, j );
            }
        }
    }
}

bool grafLista::saSasiednie( int v, int w ) {

    Lista *lista;

    lista = this->lista[v];
    while( lista ) {

        if( lista->punkt == w ) { return true; }
        lista = lista->nastepny;
    }

    lista = this->lista[w];
    while( lista ) {

        if( lista->punkt == v ) { return true; }
        lista = lista->nastepny;
    }

    return false;
}

Krawedz grafLista::wezKrawedz( int v, int w ) {

    if( !this->saSasiednie( v, w ) ) {
        throw runtime_error( " Dostep do niezainicjalizowany jest niedzowolony! " );
    }

    /*   *   *   *   *   */

    Lista * lista;
    int waga;

    /*   *   *   *   *   */

    lista = this->lista[v];
    while( lista ) {

        if( lista->punkt == w ) {

            waga = lista->waga;
            return { v, w, waga };
        }

        lista = lista->nastepny;
    }

    /*   *   *   *   *   */

    lista = this->lista[w];
    while( lista ) {

        if( lista->punkt == v ) {

            waga = lista->waga;
            return { w, v, waga };
        }

        lista = lista->nastepny;
    }

    /*   *   *   *   *   */

    throw runtime_error( " Krawedz nie zostala odnaleziona! " );
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void grafLista::rysuj() {
    
    for( int i = 0; i < this->V; i++ ) {

        cout << i;
        pout( this->lista[i] );
        cout << endl;
    }
}

void grafLista::wypelnij( int gestosc ) {

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