#define MAX 10
#include <iostream>
//#include <algorithm>
using namespace std;
class HashTable{
    private:
        int *ht;
    public:
        HashTable(){
            ht=(int *)calloc(MAX,sizeof(int));
        }
        int hashKey(int val){
            int key=val%10;
            return key;
        }
        void insert(int key){
            int m=hashKey(key);
            ht[m]=key;
        }
        void printTable(){
            cout<<"The HAST TABLE is ....\n";
            for(int i=0;i<10;i++){
                cout<< "[ "<< i <<" : "<< ht[i] <<" ]"<<endl;
            }
        }
        void search(int key)
        {
            int index=hashKey(key);
            if(key==ht[index])
                cout<<"Element found at index = "<<index;
            else
                cout<<"Element Not Found :( \n";
        }
        void Remove(int key){
            int index=hashKey(key);
            if(key==ht[index])
                ht[index]=0;
            else
                cout<<"Element Not Found in table :( \n";
        }
};

int main(){
    HashTable obj;
    int a[7]={2,3,4,59,86,1,0};
    for(int i=0;i<7;i++){
        obj.insert(a[i]);
    }
    obj.printTable();
    cout<<"Enter an elememt to search : ";
    int x;
    cin >> x;
    obj.search(x);
    cout<<"\nEnter an elememt to Remove : ";
    int y;
    cin >> y;
    obj.Remove(y);
    obj.printTable();
}
