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
        ll n;
        cin>>n;
        set<ll> st;
        vi comp(2*n);
        
        for(int i=0; i<2*n; i+=2){
            cin>>comp[i]>>comp[i+1];
            st.insert(comp[i]);
        }
        sort(all(comp));
        
        int overlaps=0, max_overlaps=1;
        for(int i=0; i<2*n; i++){
            // cout<<overlaps<<" "<<comp[i]<<endl;
            st.find(comp[i])!=st.end() ? overlaps++ : overlaps--;    
            max_overlaps = max(max_overlaps, overlaps);            
        }
        cout<<max_overlaps<<endl;
    }
 
  return 0;
}
