#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Quickfind{
    vector<int> a;
    Quickfind(int tamano) {
        for (int i = 0; i < tamano; i++) {
            a.push_back(i);
        }
    }
    bool find(int p, int q){
        return a[p]==a[q];
    }
    void unite(int p, int q){
        int id=a[p];
        for (int i=0; i<a.size();i++){
            if (a[i]==id){
                a[i]=a[q];
            }
        }
    }
    void print(){
        cout<<"nodo: ";
        for (int i=0;i<a.size();i++){
            cout<<i<<" ";

        }
        cout<<"\nancestro mas lejano: ";
        for (int i=0;i<a.size();i++){
            cout<<a[i]<<" ";

        }

    }
};



int main() {
    Quickfind a(5);
    a.unite(1,4);
    a.print();
    cout<<endl;
    a.unite(4,2);
    a.print();

    return 0;
}