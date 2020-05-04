//https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	int n,m;

	
	while(t--){
	    cin>>n>>m;
	    	int a[n],b[m];
	unordered_map<int,int> hm;
	
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    hm[a[i]]++;
	    
	}
	
	for(int i=0;i<m;i++){
	    cin>>b[i];
	    hm[b[i]]++;
	    
	}
	
	int count=0;
	for(auto it :hm){
	    if(it.second>0){
	        count++;
	    }
	}
	
	cout<<count<<endl;
	    
	}
	//or 
	//Simply hash every element of both arrays into an unordered set and print its size. 
	
	return 0;
}