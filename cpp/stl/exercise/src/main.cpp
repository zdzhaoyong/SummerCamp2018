#include "mylist.h"
#include <list>
#include <iostream>
#include <string>
#include <assert.h>
#include <sstream>

using std::string;
using std::cout;
using std::endl;

template <typename listype>
string teststring()
{
    listype stringlist;
    assert(stringlist.empty());

    int N=10;
    for(int i=0;i<N;i++)
    {
        stringlist.push_back(std::to_string(i));
        stringlist.push_front(std::to_string(-i));
    }

    assert(stringlist.size()==2*N);
    assert(stringlist.front()==std::to_string(1-N));
    assert(stringlist.back()==std::to_string(N-1));

    for(auto it=stringlist.begin();it!=stringlist.end();it++)
    {
        cout<<*it<<endl;
        if(*it=="0")
        {
            it=stringlist.erase(it);
            it=stringlist.insert(it,"summercamp");
        }
    }

    stringlist.remove("1");

    std::stringstream sst;
    for(string var:stringlist) {
        sst<<var<<endl;
    };
    stringlist.clear();
    assert(stringlist.empty());
    return sst.str();
}

int main(int argc,char** argv)
{
    if(teststring<summercamp::list<string> >()==teststring<std::list<string> >())
        cout<<"PASSED";
    else cout<<"FAILED";

    return 0;
}
