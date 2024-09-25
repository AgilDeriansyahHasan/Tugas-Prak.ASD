#include <iostream>
using namespace std;

class btreenode{
	int *kunci, t, n ;
	bool leaf;
	btreenode **c;
	
	public:
	btreenode(int tt, bool _leaf);
	void sisiptdkpenuh(int k);
	void splitanak(int i, btreenode *y);
	void traverse();
	btreenode *search(int k);
	friend class btree;
};

class btree{
	int t;
	btreenode *root;
	
	public :
	btree (int tt)
	{root=NULL;t=tt;}
	void traverse()
	{if (root != NULL) root -> traverse();}
		
	btreenode* search(int k)
	{return (root == NULL)?NULL :  root -> search(k);}
	void sisip(int k);
};
	
btreenode::btreenode(int t1, bool leaf1){
	t = t1;
	leaf = leaf1;
	kunci = new int[2*t-1];
	c = new btreenode *[2*t];
	n=0;
}

void btreenode::traverse(){
	int i;
	for (i=0;i<n;i++){
		if(leaf==false)
			c[i]->traverse();
		cout<<" " <<kunci[i];
	}
	if(leaf==false)
		c[i]->traverse();
}

btreenode *btreenode::search(int k){
	int i=0;
	while(i<n && k>kunci[i])
		i++;
	if(kunci[i]==k)
		return this;
	if(leaf == true)
		return NULL;
	return c[i]->search(k);
}

void btree::sisip(int k){
	if(root == NULL){
		root = new btreenode(t,true);
		root->kunci[0]=k;
		root->n=1;
	}
	else{
		if(root->n==2*t-1){
			btreenode *s =new btreenode(t,false);
			s->c[0]=root;
			s->splitanak(0,root);
			int i = 0;
			if(s->kunci[0]<k);
				i++;
				s->c[i]->sisiptdkpenuh(k);
				root=s;
		}
		else
			root->sisiptdkpenuh(k);
	}
}

void btreenode::sisiptdkpenuh(int k){
	int i= n-1;
	if(leaf == true){
		while(i>=0 && kunci[i]>k){
			kunci[i+1]=kunci[i];
			i--;
		}
		kunci[i+1]=k;
		n=n+1;
	}
	else{
		while(i>=0&&kunci[i]>k)
			i--;
		if(c[i+1]->n==2*t-1){
			splitanak(i+1, c[i+1]);
			if(kunci[i+1]<k)
				i++;
		}
		c[i+1]->sisiptdkpenuh(k);
}}

void btreenode::splitanak(int i, btreenode *y){
	btreenode *z = new btreenode(y->t,y->leaf);
	z->n=t-1;
	for(int j=0;j<t-1;j++)
		z->kunci[j]=y->kunci[j+t];
	if(y->leaf==false){
		for(int j=0;j<t;j++)
			z->c[j]=y->c[j+t];
	}
	y->n=t-1;
	for(int j=n;j>=i+1;j--)
		c[j+1]=c[j];
		c[i+1]=z;
	for(int j=n-1;j>=i;j--)
		kunci[j+1]=kunci[j];
		kunci[i]=y->kunci[t-1];
		n=n+1;
}

int main(){
	btree t(5);
	t.sisip(40);
	t.sisip(49);
	t.sisip(7);
	t.sisip(89);
	t.sisip(20);
	t.sisip(66);
	t.sisip(71);
	t.sisip(75);
	t.sisip(31);
	t.sisip(56);
	t.sisip(81);
	cout<<"		Pohon Dengan Menggunakan B-Tree		"<<endl;
	cout<<"----------------	m=5	--------------------"<<endl;
	cout<<"-----------------------------------------"<<endl;
	t.traverse();
	cout<<endl;
	int k =7;
	(t.search(k) != NULL)?cout<<"Kunci yang dicari "<< k << "= Ditemukan" : cout<<"Kunciyang dicari "<<k<<"= Tidak Ditemukan";
	cout<<endl;
	cout<<endl;
	k=15;
	(t.search(k) != NULL)?cout<<"Kunci yang dicari "<< k << "= Ditemukan" : cout<<"Kunciyang dicari "<<k<<"= Tidak Ditemukan";
	return 0;
}
	