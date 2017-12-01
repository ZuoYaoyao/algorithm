#include<stdio.h>

int is_prime[8000001];

void isprime(int n){ //till n
    for (int i = 2; i <= n; ++i) {
        is_prime[i] = 1;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j +=i) {
                is_prime[j] = 0;
            }
    }
}
}

int main(){
    int n;
    int minus;
    int res1=0;
    int res2=0;
    scanf("%d",&n);
    isprime(n);
    for(int i=2;i<n;i++){
        if(is_prime[i]==1){
            minus=n-i;
            if(is_prime[minus]==1&&minus==i)res1++;
            if(is_prime[minus]==1&&minus!=i)res2++;
        }
    }

    printf("%d\n",res1+res2/2);
}