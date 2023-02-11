#include<bits/stdc++.h>
#define fo(i, strt, end) for(i=strt;strt<end?i<end:i>end;strt<end?i+=1:i-=1)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define lli long long int
#define pb push_back;
#define el "\n"
#define ending return 0; 
lli MAX=10e10;
lli MIN= 0;
bool ck=false;
lli i,j;
lli M = 10e9+7;
using namespace std;
void blacklist(bool ck[], lli up, lli low,lli n){
    lli x=0;
    for(x=low;x<=up;x++){
        ck[x]=true;
    }
}


void search(string word1,string s,bool ck[]){
    string word2;
    lli n =s.length(),cnt=1,k=i,l=0,up,low;
    while(k<n){
        word2.clear();
        fo(l,k,n){
            k++;
            if (ck[l]==true)
            break;
            else{
            word2+=s[l];
            }
        }
       // cout<<word2<<" "<<"TEST"<<" "<<k<<" "<<l<<el;
        if (word1==word2){
        up = k;
        low =k - word2.length()-1;
        blacklist(ck,up,low,n); 
        cnt++;
        }
    }
    if (word1!="\0")
    cout<<word1<<" "<<cnt<<el;
}

void word(string s,lli n,bool ck[]){
    string word1;
    //lli i,j;
    fo(i,0,n)
    ck[i]=false;
    fo(i,0,n){
        if (s[i]==' ' || s[i]=='.'){
        ck[i]=true;
        }
    }
    i=0;
    lli k =0;
    while(i<n){
        word1.clear();
        fo(j,i,n){
            i++;
            if (ck[j]==true)
            break;
            else{
            word1+=s[j];
            ck[j]=true;}
        }
       search(word1,s,ck);
    }

}


int main (){
    string s,word1,word2;
    getline(cin,s);
    lli n=s.length();
    bool ck[n];
    word(s,n,ck);
    
}
