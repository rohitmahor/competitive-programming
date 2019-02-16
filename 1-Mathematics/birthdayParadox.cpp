/*
Problem Statement:
    what is the minimum number of people that should be present in a room so that there's 50% chance of two people having same birthday ?
*/

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll people = 0;
    ll num = 365;
    ll deno = 365;

    // p = probability of success
    // q = probability of failure
    long double p=0, q=1;

    while(q > 0.5){
        people++;
        q *= (long double)num/deno;

        num--;
    }

    cout <<"probability is "<<p<<" and Number of people are "<< people << endl;
    return 0;
}

