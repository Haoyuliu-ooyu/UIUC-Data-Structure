/* Your code here! */
#include "dsets.h"

using namespace std;


void DisjointSets::addelements	(	int 	num	)	{
    for (int i = 0; i < num; i++) {
        _elems.push_back(-1);
    }
}


int DisjointSets::find	(	int 	elem	)	{
    if (_elems[elem] < 0) {
        return elem;
    }
    int tr = find(_elems[elem]);
    return tr;
}


void DisjointSets::setunion	(int a, int	b) {
    while (_elems[a] >= 0) {
        a =_elems[a];
    }
    while (_elems[b] >= 0) {
        b = _elems[b];
    }
    int size = _elems[a] + _elems[b];
    if (_elems[a] <= _elems[b]) {
        _elems[b] = a;
        _elems[a] = size;
    } else {
        _elems[a] = b;
        _elems[b] = size;
    }
}		


int DisjointSets::size(int elem) {
    while (_elems[elem] >= 0) {
        elem = _elems[elem];
    }
    return _elems[elem]*(-1);
}

