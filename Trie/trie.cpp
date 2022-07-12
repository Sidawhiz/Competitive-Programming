#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct trie{
    int cnt ; // cnt stores if a word ends here , acts as a $ sign
    trie* link[26];

    trie(){
        for(int i = 0; i<26 ; i++){
            link[i] = NULL;
        }
        cnt = 0;
    }
};

trie *root = new trie(); // initialise root as it's not just a pointer now , it's an array

void insert(string s){
    trie *curr = root;

    for(auto c : s){
        if(curr->link[c-'a']==NULL){
            curr->link[c-'a'] = new trie();
        }
        curr = curr->link[c-'a'];
    }
    curr->cnt++;
}

int search(string s){
    trie *curr = root;
    if(curr==NULL){

        return 0;
    }
    for(auto c : s){
        if(curr->link[c-'a']==NULL){
            return 0;
        }
        curr = curr->link[c-'a'];
    }
    if(curr->cnt!=0){
        return 1;
    }
    return 0;
}




int main(){

    
    int t;
    cin >> t;
    for(int i = 0; i<t ; i++){
        string s;
        cin >> s;
        insert(s);
    }
    
    int q;
    cin >> q;
    for(int i = 0; i<q; i++){
        string s;
        cin >> s;
        cout << search(s) << endl;
    }


    return 0;

}
  // } Driver Code Ends
