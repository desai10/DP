/*
Max wants to buy a new skateboard. He has calculated the amount of money that is needed to buy a new skateboard. He left a calculator on the floor and went to ask some money from his parents. Meanwhile his little brother Yusuf came and started to press the keys randomly. Unfortunately Max has forgotten the number which he had calculated. The only thing he knows is that the number is divisible by 4.

You are given a string s consisting of digits (the number on the display of the calculator after Yusuf randomly pressed the keys). Your task is to find the number of substrings which are divisible by 4. A substring can start with a zero.

A substring of a string is a nonempty sequence of consecutive characters.

For example if string s is 124 then we have four substrings that are divisible by 4: 12, 4, 24 and 124. For the string 04 the answer is three: 0, 4, 04.

As input/output can reach huge size it is recommended to use fast input/output methods: for example, prefer to use gets/scanf/printf instead of getline/cin/cout in C++, prefer to use BufferedReader/PrintWriter instead of Scanner/System.out in Java.

Input
The only line contains string s (1 ≤ |s| ≤ 3·105). The string s contains only digits from 0 to 9.

Output
Print integer a — the number of substrings of the string s that are divisible by 4.

Note that the answer can be huge, so you should use 64-bit integer type to store it. In C++ you can use the long long integer type and in Java you can use long integer type.
*/


#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<list>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<sstream>
#include<stack>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

#define pb push_back
#define mp make_pair

#define S second
#define F first

#define all(c) (c).begin(), (c).end()

ll gcd(ll a, ll b)
{
   if (b==0) return a;
   return gcd(b,a%b);
}

ll abs1(ll a)
{
	if(a<0)
	return -1*a;
	else return a;
}

ll power(ll base, ll n, ll M)
{
    if(n==0)
    return 1;
    if(n==1)
    return base;
    ll halfn=power(base,n/2,M);
    if(n%2==0)
    return ( halfn * halfn ) % M;
    else
    return ( ( ( halfn * halfn ) % M ) * base ) % M;
}

ll findMMI(ll n,ll M)
{
    return power(n,M-2,M);
}

ll max2(ll a, ll b)
{
	if(a>b)
	return a;
	else return b;
}

ll max3(ll a, ll b, ll c)
{
	max2(max2(a, b), c);
}

ll min2(ll a, ll b)
{
	if(a<b)
	return a;
	else return b;
}

ll min3(ll a, ll b, ll c)
{
	return min2(min2(a, b), c);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	ll fin=0;
	int l2=0;
	if((int)(s[0]-'0')%4==0)
	fin++;
	for(int i=1;i<s.length();i++)
	{
		if((10*((int)(s[i-1]-'0'))+(int)(s[i]-'0'))%4==0)
		fin+=i;
		if((int)(s[i]-'0')%4==0)
		fin++;
	}
	cout<<fin;
	return 0;
}
