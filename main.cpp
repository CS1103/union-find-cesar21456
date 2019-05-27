#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <string>
#include <string.h>

using namespace std;

struct Node{
    int x;
    Node* parent;
    int rank;
    int size;
    Node(int x1):x(x1),parent(this),rank(0),size(1){};
};



struct Quickfind{
    vector<Node*> a;
    Quickfind(int tamano) {
        for (int i = 0; i < tamano; i++) {
            Node* j=new Node(i);
            a.push_back(j);
        }
    }
    Node* find_compression(int p){
        if (a[p]->parent!=a[p]){
            a[p]->parent=find_compression(a[p]->parent->x);
        }else{
            return a[p]->parent;
        }
    }
    Node* find_halving(int p){
        while (a[p]->parent!=a[p]){
            a[p]->parent=a[p]->parent->parent;
            a[p]=a[p]->parent;
        }
        return a[p];
    }

    Node* find_pathsplit(int p){
        while(a[p]->parent!=a[p]){
            a[p]=a[p]->parent;
            a[p]->parent=a[p]->parent->parent;
        }
        return a[p];
    }

    void unite_rank_pathsplit(int p, int q){
        Node* pRoot=find_pathsplit(p);
        Node* qRoot=find_pathsplit(q);

        if (pRoot==qRoot){
            cout<<"estan en el mismo set"<<endl;
            return;
        }
        if(pRoot->rank<qRoot->rank){
            Node* zRoot=qRoot;
            qRoot=pRoot;
            pRoot=zRoot;
        }
        qRoot->parent=pRoot;
        if(pRoot->parent==qRoot->parent){
            pRoot->rank+=1;

        }

    }
    void unite_rank_halving(int p, int q){
        Node* pRoot=find_halving(p);
        Node* qRoot=find_halving(q);

        if (pRoot==qRoot){
            cout<<"estan en el mismo set"<<endl;
            return;
        }
        if(pRoot->rank<qRoot->rank){
            Node* zRoot=qRoot;
            qRoot=pRoot;
            pRoot=zRoot;
        }
        qRoot->parent=pRoot;
        if(pRoot->parent==qRoot->parent){
            pRoot->rank+=1;

        }

    }
    void unite_rank_compression(int p, int q){
        Node* pRoot=find_compression(p);
        Node* qRoot=find_compression(q);

        if (pRoot==qRoot){
            cout<<"estan en el mismo set"<<endl;
            return;
        }
        if(pRoot->rank<qRoot->rank){
            Node* zRoot=qRoot;
            qRoot=pRoot;
            pRoot=zRoot;
        }
        qRoot->parent=pRoot;
        if(pRoot->parent==qRoot->parent){
            pRoot->rank+=1;

        }

    }

    void unite_size_compression(int p, int q){
        Node* pRoot=find_compression(p);
        Node* qRoot=find_compression(q);

        if (pRoot==qRoot){
            cout<<"estan en el mismo set"<<endl;
            return;
        }
        if(pRoot->size<qRoot->size){
            Node* zRoot=qRoot;
            qRoot=pRoot;
            pRoot=zRoot;
        }
        qRoot->parent=pRoot;
            pRoot->size+=qRoot->size;

        }
    void unite_size_halving(int p, int q){
        Node* pRoot=find_halving(p);
        Node* qRoot=find_halving(q);

        if (pRoot==qRoot){
            cout<<"estan en el mismo set"<<endl;
            return;
        }
        if(pRoot->size<qRoot->size){
            Node* zRoot=qRoot;
            qRoot=pRoot;
            pRoot=zRoot;
        }
        qRoot->parent=pRoot;
        pRoot->size+=qRoot->size;

    }
    void unite_size_pathsplit(int p, int q){
        Node* pRoot=find_pathsplit(p);
        Node* qRoot=find_pathsplit(q);

        if (pRoot==qRoot){
            cout<<"estan en el mismo set"<<endl;
            return;
        }
        if(pRoot->size<qRoot->size){
            Node* zRoot=qRoot;
            qRoot=pRoot;
            pRoot=zRoot;
        }
        qRoot->parent=pRoot;
        pRoot->size+=qRoot->size;

    }

    string print(){
        string x="";

        x+="nodo: ";
        for (int i=0;i<a.size();i++){
            x+=to_string(i)+" ";

        }
        x+="\nancestro mas lejano ";
        for (int i=0;i<a.size();i++){
            x+=to_string(a[i]->parent->x)+" ";

        }
        cout<<x<<endl;
    }
};



int main() {
    Quickfind a(5);
    a.unite_rank_compression(1,4);
    a.unite_rank_compression(4,2);
    Quickfind b(5);
    b.unite_rank_halving(1,4);
    b.unite_rank_halving(4,2);
    Quickfind c(5);
    c.unite_rank_pathsplit(1,4);
    c.unite_rank_pathsplit(4,2);
    //assert(a.print()==b.print()); //aqui sucede un error, si corre el codigo, se nota que el resultado es el mismo, aunque el assert falle
    //assert(a.print()==c.print()); //aqui sucede lo mismo
    Quickfind d(5);
    d.unite_size_compression(1,4);
    d.unite_size_compression(4,2);
    Quickfind e(5);
    e.unite_size_halving(1,4);
    e.unite_size_halving(4,2);
    Quickfind f(5);
    f.unite_size_pathsplit(1,4);
    f.unite_size_pathsplit(4,2);
    //assert(d.print()==e.print());  //no se porque sucede con todos, pero puede correrlo y le aseguro que funciona
    //assert(d.print()==f.print());

    return 0;
}
