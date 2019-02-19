#include<bits/stdc++.h>
using namespace std;
#define rev_iter(i,n,m) for(int i=n;i >= m;i--)
#define iter(i,m,n) for(int i=m;i<n;i++)
#define pb push_back
#define ll long long
#define ull unsigned long long int
#define ff first
#define ss second
#define MAX 100001
#define MOD 1000000007

vector<ll> primeFactor[1001];

void factorization(){
    for(int i=2;i<1001;i++){
        if(primeFactor[i].size() == 0){
            for(int j=i;j<1001;j+=i){
                ll temp = j;
                ll product = 1;
                while(temp%i == 0){
                    temp /= i;
                    product *= i;
                }
                primeFactor[j].push_back(product);
            }
        }
    }
}

ll pow(ll a, ll n){
     if(n == 0){
        return 1;
    }

    ll x = pow(a, n/2)%MOD;

    if(n&1){
        return ((x%MOD * x%MOD)%MOD * a%MOD)%MOD;
    }
    return (x%MOD * x%MOD)%MOD;
}

ll solve(ll n, ll m, ll l, ll r){
    vector<ll> negation(2,0), temp(2,0);

    for(ll i=2;i<=r;i++){
        negation.push_back(0);
        temp.push_back(0);
        if(primeFactor[i].size() <= 1){
            negation[i] = pow(m-m/i,n);
            temp[i] = negation[i];
        }
        else{
            ll numBit = primeFactor[i].size();
            ll times = 0;
            temp[i] = 0;

            for(ll mask=1;mask<(1<<numBit);mask++){
                ll currMask = mask;
                ll count=0;
                ll p=1;
                ll pos = 0;
                while(currMask > 0){
                    if(currMask&1){
                        count++;
                        p *= primeFactor[i][pos];
                    }
                    pos++;
                    currMask = currMask >> 1;
                }

                if(count&1){
                    times += m/p;
                }
                else{
                    times -= m/p;
                }
            }

            times = m - times;

            for(ll mask=1;mask<(1<<numBit);mask++){
                ll currMask = mask;
                ll count=0;
                ll p=1;
                ll pos = 0;
                while(currMask > 0){
                    if(currMask&1){
                        count++;
                        p *= primeFactor[i][pos];
                    }
                    pos++;
                    currMask = currMask >> 1;
                }

                if(count&1){
                    if(p == i){
                        negation[i] = (negation[i] + pow(times, n))%MOD;
                        temp[i] = pow(times, n);
                    }
                    else{
                        negation[i] = (negation[i] + temp[p])%MOD;
                    }
                }
                else{
                    if(p == i){
                        negation[i] =  (negation[i] - pow(times, n) + MOD)%MOD;
                        temp[i] = pow(times, n);
                    }
                    else{
                        negation[i] = (negation[i] - temp[p] + MOD)%MOD;
                    }
                }
            }
        }
    }

    ll ans=0;
    ll all = pow(m,n);
    for(ll i=l;i<=r;i++){
        // cout << negation[i] << " ";
        ans += (all - negation[i] + MOD)%MOD;
    }

    return ans%MOD;

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    factorization();

    ll t;
    cin >> t;

    while(t--){
        ll n, m, l, r;
        cin >> n >> m >> l >> r;

        cout << solve(n, m, l, r) << endl;
    }
}
