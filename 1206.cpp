#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {} // 預設建構子
    Node(int value) : val(value), next(nullptr) {}
};

int main(){
    Node* head[6];
    for (int i = 0; i < 6; ++i)
        head[i] = new Node(i);
    Node *ptr,*newnode;
    int data[14][2]={{1,2},{1,5},{2,1},{2,3},{2,4},{3,2},{3,4},{3,5},{4,2},{4,3},{4,5},{5,1},{5,3},{5,4}};
    for(int i=1;i<6;i++){
        head[i]->val=i;

        cout <<"頂點"<<i<<"=>";
        ptr=&(*head[i]);
        for(int j=0;j<14;j++){
            if(data[j][0]==i){
                newnode = new Node;
                newnode->val=data[j][1];

                while(ptr!=NULL)
                    ptr=ptr->next;
                ptr=newnode;
                cout<<"["<<newnode->val<<"]";
            }
        }
        cout<<endl;
    }
}