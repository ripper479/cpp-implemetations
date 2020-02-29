#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void buildTree(vector<ll> arr,vector<ll> &st,ll i,ll j,ll index)
{
    if(i==j)
    {
        st[index]=arr[i];
        return;
    }
    ll mid=(i+j)/2;
    buildTree(arr,st,i,mid,2*index+1);
    buildTree(arr,st,mid+1,j,2*index+2);
    st[index]=st[2*index+1]+st[2*index+2];
}
ll getSum(vector<ll> &st,ll i,ll j,ll x,ll y,ll index)
{
    if(x<=i and j<=y)
    {
        return st[index];
    }
    else if(j<x or y<i)
    {
        return 0;
    }
    else
    {
        ll mid=(i+j)/2;
        return getSum(st,i,mid,x,y,2*index+1)+getSum(st,mid+1,j,x,y,2*index+2);
    }
}
void updateTree(vector<ll> &st,ll i,ll j,ll x,ll val,ll index)
{
    if(x<i or x>j)  return;
    st[index]+=val;
    if(i!=j)
    {
        ll mid=(i+j)/2;
        updateTree(st,i,mid,x,val,2*index+1);
        updateTree(st,mid+1,j,x,val,2*index+2);
    }
}
int main() 
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll h=ceil(log2(n));   
    vector<ll> st(int(pow(2,h+1))-1,0);
    buildTree(arr,st,0,n-1,0);
    updateTree(st,0,n-1,2,-3,0);
    cout<<getSum(st,0,n-1,0,3,0);
    return 0;
}