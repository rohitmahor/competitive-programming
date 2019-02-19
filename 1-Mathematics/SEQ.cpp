/*
 
    https://www.spoj.com/problems/SEQ/
 
    Sequence (ai) of natural numbers is defined as follows:
 
   ai = bi (for i <= k)
   ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)
 
where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute an for given n and output it modulo 109.
*/
 
#include<bits/stdc++.h>
#define MOD 1000000000
using namespace std;
typedef long long ll;
 
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
ll solve(vector<ll> F, vector<ll> c, ll n, ll k){
    vector<vector<ll>> T(k+1, vector<ll>(k+1));
 
    if(n <= k){
        return F[n];
    }
 
    // Step 3 - Calculate Transformation matrix
    for(int i=1;i<k;i++){
        T[i][i+1] = 1;
    }
 
    for(int i=1;i<=k;i++){
        T[k][i] = c[k-i+1];
    }
 
    // Step 4 - Determine nth term F(n)
    T = power(T, n-1);
 
    ll ans=0;
    for(int i=1;i<=k;i++){
        ans = (ans%MOD + (T[1][i]%MOD * F[i]%MOD)%MOD)%MOD;
    }
 
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
    ll t;
    cin >> t;
 
    while(t--){
        //Step 1 Determine K
        ll k;
        cin>>k;
 
        vector<ll> F(k+1,0), c(k+1,0);
 
        //Step 2 Store K terms in array F1
        for(int i=1;i<=k;i++){
            cin >> F[i];
        }
        for(int i=1;i<=k;i++){
            cin >> c[i];
        }
 
        ll n;
        cin >> n;
        cout << solve(F, c, n, k) << endl;
    }
} 