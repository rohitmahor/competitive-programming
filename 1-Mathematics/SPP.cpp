/*
https://www.spoj.com/problems/SPP/
Sequence (ai) of natural numbers is defined as follows:

    ai = bi (for i <= k)
    ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute am + am+1 + am+2 + ... + an for given m <= n and output it modulo a given positive integer p.
*/
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;

ull MOD;
 
// Matrix Multiplication O(k^3)
vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> ans(A.size(), vector<ll>(B[0].size()));
 
    for(ll i=0;i<ans.size();i++){
        for(ll j=0;j<ans[0].size();j++){
            ans[i][j] = 0;
            for(ll k=0;k<B[0].size();k++){
                ans[i][j] = (ans[i][j]%MOD + (A[i][k]*B[k][j])%MOD)%MOD;
            }
        }
    }
 
    return ans;
}
 
// Power using sqauring method O(logn)
vector<vector<ll>> power(vector<vector<ll>> T, ll n){
    if(n == 1){
        return T;
    }   
	
	vector<vector<ll>> x = power(T, n/2);
    if(n%2 == 0){
        return mul(x,x);
    }
    else{
        return mul(T,mul(x,x));
    }
}
 
// O(k^3*log(n))
ll solve(vector<ll> F, vector<ll> c, ll m, ll n, ll k){
    vector<vector<ll>> T1(k+2, vector<ll>(k+2)), T2(k+2, vector<ll>(k+2));
 
    if(n <= k){
        return F[n];
    }
 
    for(int i=1;i<k;i++){
        T1[i][i+1] = 1;
        T2[i][i+1] = 1;
    }
 
    for(int i=1;i<=k;i++){
        T1[k][i] = c[k-i+1];
        T2[k][i] = c[k-i+1];
    }

    T1[k+1][1] = T1[k+1][k+1]=1;
    T2[k+1][1] = T2[k+1][k+1]=1;

    T1 = power(T1, m-1);
    T2 = power(T2, n);

    
    ll ans1=0, ans2=0;
    for(int i=1;i<=k+1;i++){
        ans1 = (ans1%MOD + (T1[k+1][i]%MOD * F[i]%MOD)%MOD)%MOD;
    }
    for(int i=1;i<=k+1;i++){
        ans2 = (ans2%MOD + (T2[k+1][i]%MOD * F[i]%MOD)%MOD)%MOD;
    }
 
    return (ans2 - ans1 + MOD)%MOD;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
    ll t;
    cin >> t;
 
    while(t--){
        ll k;
        cin>>k;
 
        vector<ll> F(k+1,0), c(k+1,0);
 
        for(int i=1;i<=k;i++){
            cin >> F[i];
        }
        for(int i=1;i<=k;i++){
            cin >> c[i];
        }
 
        ll m, n;
        cin >> m >> n >> MOD;
        cout << solve(F, c, m, n, k) << endl;
    }
} 