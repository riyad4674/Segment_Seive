#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<ll> vll;
void segment_seive(ll l,ll r,vll& prime)
{
    int arr[r-l+1];
    for(ll i = 0; i< (r-l+1); i++)
       arr[i] = 1;
    for(ll i = 0; i<prime.size(); i++)
    {
        ll g = (l/prime[i])*prime[i];
        if(g<l)
          g +=prime[i];
        for(int j = g;j<=r; j+=prime[i])
        {
           
            arr[j-l] = 0;
        }
    }
    for(ll i = 0; i<(r-l+1); i++)
     {
        if(arr[i]== 1)
        cout<<l+i<<" ";
     }
     cout<<endl;
}
void seive(vll& prime ,ll n)
{

    vector<bool> vec(n+1);
    for (ll i = 0; i <= n; i++)
        vec[i] = true;

    vec[0] = false;
    vec[1] = false;

    for (ll i = 4; i <= n; i += 2)
        vec[i] = false;

    prime.push_back(2);

    for (ll i = 3; i <= n; i += 2)
    {
        if (vec[i] == true)
        {
            prime.push_back(i);

            if (i * i <= 100)
            {

                for (int j = i * i; j <= 100; j += i * 2)
                    vec[j] = false;
            }
        }
    }
    
   
}
 int main()
 {
    ll t, l, r;
    cin>>t;
    while(t)
    {
         cin>>l>>r;
    vll prime;
    ll x = sqrt(r);
    seive(prime,x);
    segment_seive(l,r,prime);    
    }
    return 0;
 }   

