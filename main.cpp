//
//  main.cpp
//  First arg
//
//  Created by Mingmanas Sivaraksa on 2/1/2567 BE.
//

#include <iostream>
using namespace std;
#include <iomanip>
#include "sorting.h"

int main(int argc, char * argv[]) {
    int i,N=argc-1;
    int *a=new int[N];
    for(i=1;i<argc;i++){
        
        a[i-1]=atoi(argv[i]);
    
         
    }
    bubbleSort(a,N);
    delete []a;
    return 0;
}
