#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
 
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#endif
 
// #include <iostream>
using namespace std;
#define lol 1000000007
#define fol 1000000000
#define all(c) c.begin(), c.end()
#define vi vector<ll>
#define vvi vector<vi>
#define fi first
#define se second
#define pb push_back
typedef long long ll;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
 
// #define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
 
ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
ll expo(ll n, ll k, ll mod)
{
  if (k == 0)
    return 1 % mod;
  ll u = expo(n, k / 2, mod);
  u = (u * u) % mod;
  if (k % 2 != 0)
    u = (u * n) % mod;
  return u;
}
 
ll msqrt(ll n)
{
  if (n < 0)
    return -1;
  ll L = 0, R = 5000000001;
  while (L < R)
  {
    ll mid = (L + R) / 2;
    if (mid * mid >= n)
      R = mid;
    else
      L = mid + 1;
  }
  return L;
}
 
ll factorial(ll n)
{
 
  return (n == 1 || n == 0) ? 1 : ll(n) * factorial(n - 1);
} 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int f=1;
    // cin >> f;
    while (f--) {
        ll n,m;
        cin>>n>>m;
        vi a(n);
        for(ll i=0; i<n; i++){
            cin>>a[i];
        }
        long ans = 1;
 
        // Array to store the index of numbers from 1 to N
        vector<long> indices(n + 1);
 
        // Store the index of all elements of arr[]
        for (int i = 0; i < n; i++) {
            indices[a[i]] = i;
        }
 
        // If num occurs after (num + 1), increment ans by 1
        for (int num = 1; num < n; num++) {
            if (indices[num + 1] < indices[num])
                ans++;
        }
        // cout<<ans<<endl;
        
 
        for(ll i=0; i<m; i++){
            ll x,y;
            cin>>x>>y;
            x--, y--;
            // cout<<"x:"<<x<<" y:"<<y<<endl;
            if(a[x]==a[y]-1){
                if(x<y){
                    ans++;
                    // cout<<"A"<<ans<<endl;
                }
                else{
                    ans--;
                    // cout<<"B"<<ans<<endl;
                }
            }
            if(a[x]==a[y]+1){
                if(x<y){
                    ans--;
                    // cout<<"C"<<ans<<endl;
                }
                else{
                    ans++;
                    // cout<<"D"<<ans<<endl;
                }
            }
            if(indices[a[x]-1] < x && indices[a[x]-1] > y){
                ans++;
                // cout<<"a"<<ans<<endl;
            }   
            if(indices[a[x]-1] > x && indices[a[x]-1] < y){
                ans--;
                // cout<<"b"<<ans<<endl;
            }
            if(indices[a[x]+1] < x && indices[a[x]+1] > y){
                ans--;
                // cout<<"c"<<ans<<endl;
            }
            if(indices[a[x]+1] > x && indices[a[x]+1] < y){
                ans++;
                // cout<<"d"<<ans<<endl;
            }
            if(indices[a[y]-1] < y && indices[a[y]-1] > x){
                ans++;
                // cout<<"e"<<ans<<endl;
            }
            if(indices[a[y]-1] > y && indices[a[y]-1] < x){
                ans--;
                // cout<<"f"<<ans<<endl;
            }
            if(indices[a[y]+1] < y && indices[a[y]+1] > x){
                ans--;
                // cout<<"g"<<ans<<endl;
            }
            if(indices[a[y]+1] > y && indices[a[y]+1] < x){
                ans++;
                // cout<<"h"<<ans<<endl;
            }
            
            indices[a[x]] = y;
            indices[a[y]] = x;
            ll temp=a[x];
            a[x]=a[y];
            a[y]=temp;
            // for(int i=0; i<n; i++){
            //     cout<<a[i]<<" ";
            // } 
            // cout<<" "; 
            cout<<ans<<endl; 
        }
        
    }
 
  return 0;
}