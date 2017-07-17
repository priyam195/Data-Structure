#include <iostream>
#include <map>
using namespace std;
struct node{
    char c;
map<char,node*> mp;
int count;

};

node* newnode(char y){

node  *temp=new node;
temp->c=y;
temp->count=0;
return temp;


}
void inserti(string s,node *start){

for(int i=0;i<s.length();i++){


if(start->mp.find(s[i])!=start->mp.end())
{
    start=start->mp[s[i]];
    start->count++;

}

else{
node *ex=newnode(s[i]);
ex->count++;
start->mp.insert(pair<char,node*>(s[i],ex));
//cout<<start->c<<" g";
start=ex;}
      }
}

int findcount(string s,node *start){

for(int i=0;i<s.length();i++){
  if(start->mp.find(s[i])!=start->mp.end())
{  //cout<<start->c<" ll";
      if(i==s.length()-1)
        return start->mp[s[i]]->count;

        start=start->mp[s[i]];


}
 else
       
            return 0;
}
    return 0;
}
int main(){
    int i,t;
    string s,f;
node *root=new node;
root->count=0;
root->c='*';

cin>>t;
while(t--){

 cin>>s>>f;
 if(s=="add")
inserti(f,root);
else if(s=="find")
    cout<<findcount(f,root)<<endl;



    }





return 0;}
