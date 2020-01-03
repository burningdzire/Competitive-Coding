#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template <typename T>
class BTNode{
	public:
		T data;
		BTNode* left;
		BTNode* right;
};

BTNode<int>* CreateTree(){
	int data;
	cout<<"Enter root data\n";
	cin>>data;
	if(data==-1){
		return  NULL;
	}else{
		BTNode<int>* newnode=new BTNode<int>;
		newnode->data=data;
		cout<<"Enter left child of "<<data<<"\n";
		newnode->left=CreateTree();
		cout<<"Enter right child of "<<data<<"\n";
		newnode->right=CreateTree();
		return newnode;
	}
}

bool PrintAncestor(BTNode<int>* root,int data){
	if(root==NULL){
		return false;
	}
	if(root->data==data){
		return true;
	}
	if(PrintAncestor(root->left,data)|| PrintAncestor(root->right,data)){
		cout<<root->data<<" ";
		return true;
	}
	return false;
	
}

int main(){
	BTNode<int>* root=CreateTree();
	cout<<PrintAncestor(root,7);
}