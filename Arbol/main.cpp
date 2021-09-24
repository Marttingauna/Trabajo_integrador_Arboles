#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct TreeNode
{
    int num;
    TreeNode* izquierda;
    TreeNode* derecha;
    TreeNode(int x) : num(x),izquierda(nullptr),derecha(nullptr){}
};

// Recorrido en orden no recursivo
void inOrder(TreeNode* root){

    TreeNode* node = root;
    stack<TreeNode*> s;
    vector<int> vec;
    while(node || !s.empty()){
        while(node){
            s.push(node);
            node = node->izquierda;
        }
        if(!s.empty()){
            node = s.top();
            s.pop();
            vec.push_back(node->num);
            node = node->derecha;
        }
    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
}



int main(){

    // Construye un árbol binario
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    a->izquierda = b;
    a->derecha= c;
    b->izquierda= d;
    b->derecha= e;
    cout << "Mostrando Arbol.. ";
    cout << "\nInorder es: ";
    inOrder(a);
    cout<<endl;

}

