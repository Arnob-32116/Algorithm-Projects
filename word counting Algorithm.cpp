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

//A function that surpresses / blocks a matched word from being used again.
//Like He(1) is a boy.He(2) is a student. Here He(1) is used first and matched with He(2).
//Later He(2) will also try to match itself with the rest of the string.
//This function blocks that.

void blacklist(bool ck[], lli up, lli low,lli n){
    lli x=0;
    for(x=low;x<=up;x++){
        ck[x]=true;
    }
}

//This function Matches two words and counts the number of times it matched with another word and stores in a vector.

void search(string word1,string s,bool ck[],vector<pair<string,lli>> &v){
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
        if (word1==word2){
        up = k;
        low =k - word2.length()-1;
        blacklist(ck,up,low,n); 
        cnt++;
        }
    }
    if (word1!="\0"){
    v.push_back(make_pair(word1,cnt));}
}

//This function splits individual words from a string.

void word(string s,lli n,bool ck[],vector<pair<string,lli>> &v){
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
       search(word1,s,ck,v);
    }

}

//Driver Code.
int main (){
    string s,word1,word2;
    vector<pair<string,lli>> v;
    getline(cin,s);
    lli n=s.length();
    bool ck[n];
    word(s,n,ck,v);
    sort(v.begin(),v.end());   //This sorts the words in an alphabetical worder.
    
    for(auto p:v)
    cout<<p.first<<" "<<p.second<<el;
    
}
