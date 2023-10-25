// You are using GCC
#include <iostream>
#include <cmath>
using namespace std;

const int MAX_N = 20; // Define a maximum size for the array
static int maxLoot = 0;
void soln(int hval[],int index,int n,int sum){
    if(index>n){
        return;
    }
    sum=sum+hval[index];
    maxLoot = max(maxLoot,sum);
    // cout<<sum<<" ";
    for(int i=index+2;i<=n;i++){
        soln(hval,i,n,sum);
    }
}
int maximumLoot(int hval[], int n) {
    soln(hval,0,n,0);
    return maxLoot;
}

int main() {
    int n;
    cin >> n;

    int hval[MAX_N];
    for (int i = 0; i < n; i++) {
        cin >> hval[i];
    }

    cout  <<maximumLoot(hval, n - 1);

    return 0;
}
