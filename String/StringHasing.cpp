#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll b = 53; // 31 for lowercase only and 53 for both upper and lower
ll mod = 1e9 + 9; // Has to be prime and coprime with base
const int N = 1e5 + 10;

ll p[N];
ll e(int x)
{
	if (p[x]) return p[x];
	if (x <= 0) return 1LL;
	else return p[x] = (e(x - 1) * b) % mod;
}

ll hashp[N];
// Generates a hash prefix sum of a string
void hash_string(const string& str)
{
	for (int i = 0; i < (int)str.size(); i++)
	{
		hashp[i + 1] = ((hashp[i] * b) % mod + str[i]) % mod;
	}
}

ll get_hash(int l, int r)
{
	ll v = hashp[r + 1];
	v = (v - (hashp[l] * e(r - l + 1)) % mod) % mod;
	return v < 0 ? v + mod : v;
}

int main()
{
	string s;
	cin>>s;
	hash_string(s);
	while (true)
	{
		int va, vb;
		cin>>va>>vb;
		cout<<"Hash of string ["<<va<<", "<<vb<<"] ("
			<<s.substr(va, vb - va + 1)
			<<") = "<<get_hash(va, vb)<<endl;
	}
}
