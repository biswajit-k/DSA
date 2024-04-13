//#include <bits\stdc++.h>
#include <iostream>

using namespace std;         //Perform binary search by bsearch using comparator to get index of a element

int comp(const void* a,const void* b){
    int* x=(int*)a;
    int* y=(int*)b;
    if(*x>*y){return -1;}
    else if(*y>*x){return 1;}// multiple adding mere bhaut same haat hai jo ek bari me sab kar rahe hai ha ha ha
    else{return 0;}
}

int main(){
   int n;
    cin>>n;// multiple adding mere bhaut same haat hai jo ek bari me sab kar rahe hai ha ha ha
    int a[n];
    for(int i=0;i<n;i++)// multiple adding mere bhaut same haat hai jo ek bari me sab kar rahe hai ha ha ha
    {
        cin>>a[i];
    }
    // int*k=&a[1];
    // sort(k--,a+n,comp);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<a[i]<<' ';
    // }
    int x=3;
    int *p=(int*)(bsearch(&x,a,n,sizeof(int),comp));
    cout<<*p;
    return 0;
}

