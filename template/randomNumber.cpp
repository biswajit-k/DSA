#include<iostream>
#include<time.h>

using namespace std;
int main()
{
    double m;
    time_t k;
    m=time(&k);
    srand(m);

    cout<<k<<endl;
    cout<<RAND_MAX<<endl;
    cout<<rand()<<endl<<rand();

    return 0;
}
