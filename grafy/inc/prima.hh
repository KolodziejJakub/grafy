#ifndef PRIMA_HH
#define PRIMA_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <vector>

#include "grafMacierz.hh"
#include "grafLista.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

bool wZbiorzeMST( int v, int w, bool * wMST );

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Prima( grafMacierz data, bool rysoj );
void Prima( grafLista data, bool rysoj );

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif