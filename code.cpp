#include <bits/stdc++.h>
#define ulli unsigned long long int
#define uli unsigned long int
#define ui unsigned int
#define pb push_back
using namespace std;                                   //used concept of map to check whether the given frequency of a charcter
                                                       //is less than and equal to its frequency in the array. If conditions are
                                                       //true,than print it.Also maintain the boolean flag to exit the condtion at
                                                       //right time. Maintain set for preventing multiple print of same word.
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;
	
	for(int ii=1;ii<=t;ii++)
	{
	    int n;
	    cin>>n;
	    
	    vector <string> v(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>v[i];
	    }
	    sort(v.begin(),v.end());   //need to print in chronological manner.
	    map <char,int> m,m1;
	    
	    int a,b;
	    cin>>a>>b;
	    
	    for(int i=0;i<a*b;i++)
	    {
	        char ch;
	        cin>>ch;
	        m[ch]++;
	    }
	    
	    bool flag=false;
	    set <string> st;
	    for(int i=0;i<n;i++)
	    {
	        string s=v[i];
	        map <char,int> temp;
	        for(int j=0;j<s.length();j++)
	        {
	            temp[s[j]]++;
	        }
	        bool tt=true;
	        for(map <char,int> :: iterator it=temp.begin();it!=temp.end();it++) //checking condition
	        {
	            map <char,int> :: iterator it1;
	            for(it1=m.begin();it1!=m.end();it1++)
	            {
	                if(it->first==it1->first)
	                {
	                    if(it->second>it1->second)
	                    {
	                        tt=false;
	                        break;
	                    }
	                    
	                    break;
	                }
	            }
	            if(it!=temp.end() && it1==m.end())
	            {
	                tt=false;
	                break;
	            }
	            if(tt==false)
	                break;
	            
	        }
	        
	        if(tt==true)
	            {
	                st.insert(v[i]);
	                flag=true;
	            }
	    }
	    
	    if(flag==false)
	        cout<<-1;
	   else
	    {
	        for(auto kkk:st)
	            cout<<kkk<<" ";
	    }
	    
	    cout<<"\n";
	}
	return 0;
}
