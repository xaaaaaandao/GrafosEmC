#ifndef MST_H
#define MST_H

#define MAX 3276

#include "lista.h"


No *retornaNo(Lista*, int);
No *extrairMenor(Lista*, Lista*);
bool existeNo(Lista*, int);
Lista *MST_Kruskal(Lista*);
void MST_Prim();


#endif /* MST_H */
