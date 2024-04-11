#include <iostream>
#include <fstream>

using namespace std;

struct nod
{
    unsigned inf;
    nod* urm;
};

void adaugPrimulElement(nod* &primul, unsigned x)
{
    nod* p;
    p = new nod;
    p->inf = x;
    primul=p;
    p->urm = NULL;
}

void adaugDupaPrimulElement(nod* &prim, unsigned x)
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

unsigned palindrom(unsigned nr)
{
    unsigned inv=0;
    unsigned aux=nr;
    while(aux)
    {
        inv=inv*10+aux%10;
        aux=aux/10;
    }
    return(nr==inv);
}

int nr_div(int nr)
{
    int k=2;
    for(int i=2;i<=nr/2;i++)
        if(nr%i==0) k++;

    return k;
}

void palindromInlocuire(nod* &prim, int &k)
{
    nod* p=prim;
    k = 0;
    while(p!=NULL)
    {
        if(palindrom(p->inf))
        {
            p->inf=nr_div(p->inf);
            k++;
        }
        p=p->urm;
    }
}

int main()
{
    nod* lista;
    unsigned n;
    int K;
    ifstream f("date.txt");
    f>>n;
    adaugPrimulElement(lista, n);
    while(f>>n) adaugDupaPrimulElement(lista, n);

    afisare(lista);
    cout << endl;
    palindromInlocuire(lista, K);
    if(K) {
        cout << "Lista este: ";
        afisare(lista);
    }
    else cout << "Nu sunt elemente palindrom in lista.";
    return 0;
}
