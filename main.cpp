#include <iostream>
#include <fstream>

using namespace std;

struct nod
{
    int inf;
    nod* urm;
};

void adaugPrimulElement(nod* &primul, int x)
{
    nod* p;
    p = new nod;
    p->inf = x;
    primul=p;
    p->urm = NULL;
}

void adaugDupaPrimulElement(nod* &prim, int x)
{
    nod* p;
    p = new nod;
    p->inf=x;
    if(prim) {
        p->urm=prim;
        prim=p;
    }
    else {
        p->urm=NULL;
        prim=p;
    }
}

void afisare(nod* &prim)
{
    nod* q;
    for(q=prim;q!=NULL;q=q->urm)
        cout << q->inf << " ";
}

int main()
{
    nod* lista;
    int n, t;
    ifstream f("date.txt");
    f>>n;
    adaugPrimulElement(lista, n);
    while(f>>n) adaugDupaPrimulElement(lista, n);

    afisare(lista);
    return 0;
}
