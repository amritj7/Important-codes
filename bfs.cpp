#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define int long long
void addEdge(int x, int y,vector<int> *adj)
{
	adj[x].push_back(y);
	
}
void BFS(int start,int v, vector <int> *adj)
{
	bool a[v+1];
	for(int i=0;i<=v;i++)
		a[i]= false;
		
	vector <int> temp;
	temp.push_back(start);
	a[start]=true;
	
	while(temp.size()==0)
	{
		int v = temp.front();
		cout<<v<<" ";
		temp.erase(temp.begin());
		
		vector <int>:: iterator i;
		for(i=adj[v].begin();i!=adj[v].end();i++){
			if(a[*i]==false)
			{
				a[*i]=true;
				temp.push_back(*i);
			}
		}
		
	}
	
}

signed main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int T ;
  // 	cin>>T;
    T = 1 ;
    while ( T-- )
    {
    	int v;
    	cin>>v;
   	    vector <int> adj[v]; 
	 //   addEdge()
   	  	 
	    addEdge(0, 1, adj); 
    	addEdge(0, 2, adj); 
    	addEdge(1, 2, adj); 
    	addEdge(2, 0, adj); 
    	addEdge(2, 3, adj); 
    	addEdge(3, 3, adj); 
  
    	cout << "Following is Breadth First Traversal "
        	 << "(starting from vertex 2) \n"; 
    	BFS(2, v, adj); 
	}
    return 0 ;
}
