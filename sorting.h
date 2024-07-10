void display(double [],int );
void swap(double &,double &);
void bubblesorting(double a[],int N);

void display(double a[],int N){
        int i;
       for(i=0;i<N;i++)
           cout<<a[i]<<" ";
       cout<<endl;
    
}

void swap(double & x,double &y){
        double temp=y;
        y=x;
        x=temp;
}
void bubbleSort(double a[], int N) {
    int moveCount = 0;
    bool swapped;
    for (int i = 0; i < N - 1; i++) {
        swapped = false;
        for (int j = 0; j < N - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                moveCount++;
                swapped = true;
            }
        }
        // If no two elements were swapped in the inner loop, then the array is sorted
        if (!swapped) {
            break;
        }
    }
}