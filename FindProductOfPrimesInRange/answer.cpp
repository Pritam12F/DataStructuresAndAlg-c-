//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    #define ll long long
    long long primeProduct(long long l, long long r){
        ll mod=1e9+7;
        
        //Creating a prime sieve
        vector<bool> primes(sqrt(r)+1, true);
        primes[0] = primes[1] = false;
        for(ll i=2; i*i<primes.size(); ++i){
            if(primes[i]){
                ll j=i*i;
                while(j<primes.size()){
                    if(primes[j]){
                        primes[j]=false;
                    }
                    j+=i;
                }
            }
        }
        
        //Creating a prime only array
        vector<ll> primesOnly;
        for(ll i=0; i<primes.size(); ++i){
            if(primes[i]){
                primesOnly.push_back(i);
            }
        }
        
        //Clearing not needed array
        primes.clear();
        
        //Marking the non prime numbers with false
        vector<bool> segSieve(r-l+1, true);
        for(auto el : primesOnly){
            ll firstMultiple;
            if(l % el == 0){
                firstMultiple=l;
            }
            else{
                firstMultiple=(l/el)*el+el;
            }
            if(el*el > firstMultiple) firstMultiple=el*el;
            for(ll j=firstMultiple; j<=r; j+=el){
                if(segSieve[j-l]){
                    segSieve[j-l]=false;
                }
            }
        }
        
        //Clearing not needed array
        primesOnly.clear();
        
        ll result=1;
        
        //Finding the product of all the prime numbers
        for(ll i=0; i<segSieve.size(); ++i){
            if(segSieve[i]){
                result=(result%mod)*(i+l)%mod;
            }
        }
        
        //Clearing not needed array
        segSieve.clear();
        
        return result%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}
// } Driver Code Ends