#include <bits/stdc++.h>
using namespace std;

string s,encodedString="",decodedString="";
map<char,int>freq;
map<char,string>codes;

class HuffmanNode{
public:
    char data;
    int freq;
    HuffmanNode* left,*right;

    HuffmanNode(char ch,int freq){
        data=ch;
        this->freq=freq;
        left=right=NULL;
    }
};

struct cmp{
    bool operator()(HuffmanNode* a,HuffmanNode* b){
        return a->freq < b->freq;
    }
};

priority_queue<HuffmanNode*,vector<HuffmanNode*>,cmp>pq;

void dfs_to_encode(HuffmanNode* root,string str){
    if(root==NULL){
        return;
    }

    if(root->data!='#'){
        codes[root->data]=str;
    }

    dfs_to_encode(root->left,str+"0");
    dfs_to_encode(root->right,str+"1");
}

void make_tree(){
    for(auto x:freq){
        HuffmanNode* n=new HuffmanNode(x.first,x.second);
        pq.push(n);
    }

    HuffmanNode* left_node,*right_node,*new_node;

    while(pq.size()>1){
        left_node=pq.top();
        pq.pop();
        right_node=pq.top();
        pq.pop();
        new_node=new HuffmanNode('#',left_node->freq+right_node->freq);
        new_node->left=left_node;
        new_node->right=right_node;
        pq.push(new_node);
    }
}


void calculate_frequency_of_each_character(){
    for(char x:s)freq[x]++;
}


void Encode(){
    for(char ch:s){
        encodedString+=codes[ch];
    }
    cout<<"Encoded String: "<<encodedString<<'\n';
}

void Decode(HuffmanNode* root){
    HuffmanNode* curr=root;

    for(char x:encodedString){
        if(x=='0'){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
        if(curr->left==NULL and curr->right==NULL){
            decodedString+=curr->data;
            curr=root;
        }
    }

    cout<<"Decode String: "<<decodedString<<'\n';
}

int main(){
    cout<<"Enter a string to encode: ";
    cin>>s;

    calculate_frequency_of_each_character();

    make_tree();

    dfs_to_encode(pq.top(),"");

    cout<<"Frequency of each character: \n";
    for(auto x:freq){
        cout<<x.first<<' '<<x.second<<'\n';
    }

    Encode();
    Decode(pq.top());

    return 0;
}
