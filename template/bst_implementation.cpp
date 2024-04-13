#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define Fill(a,b)  memset(a,b,sizeof(a))
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define google cout<<"Case #"<<ll<<": "<<day<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

struct node{
    int data;
    node* left,*right;
};
node* newNode(int key){
    node* temp=new node();
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
void greatersm(node* root, int& sum){
    if(root==NULL)
        return;
    greatersm(root->right,sum);
    sum+=root->data;
    root->data=sum-root->data;
    greatersm(root->left,sum);

}


int main(){
    node *root = newNode(11);
	root->left = newNode(2);
	root->right = newNode(29);
	root->left->left = newNode(1);
	root->left->right = newNode(7);
	root->right->left = newNode(15);
	root->right->right = newNode(40);
	root->right->right->left = newNode(35);

    // inorder(root);
    int sm=0;
    greatersm(root,sm);
    inorder(root);  


    return 0;
}