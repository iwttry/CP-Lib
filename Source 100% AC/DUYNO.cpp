#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while (cin>>s) {
		if (s[0] == s[s.length()-1])
		cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";	
	}
}
