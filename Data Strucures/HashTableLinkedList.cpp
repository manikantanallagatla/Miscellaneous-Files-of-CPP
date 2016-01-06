#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
const int tableSize = 10;
class hashNode{
	public:
		int key;
		int value;
		hashNode *next;
		hashNode(int key,int value){
			this->key = key;
			this->value = value;
			this->next = NULL;
		}
};
class hashMap{
	private:
	 	hashNode **htable;
	public:
		hashMap(){
			htable = new hashNode*[tableSize];
			for(int i = 0; i<tableSize;i++){
				htable[i] = NULL;
			}
		}
		~hashMap(){
			for(int i = 0;i<tableSize;i++){
				hashNode *temp = htable[i];
				while(temp!=NULL){
					hashNode *prev = temp;
					temp = temp->next;
					delete prev;
				}
			}
			delete[] htable;
		}
		int hashFunct(int key){
			return (key%tableSize);
		}
		void insert(int key,int value){
			int hashValue = hashFunct(key);
			hashNode *prev = NULL;
			hashNode *entry = htable[hashValue];
			if(entry == NULL){
				htable[hashValue] = new hashNode(key,value);
				return;
			}
			while(entry!=NULL){
				prev = entry;
				entry = entry->next;
			}
			if(entry == NULL){
				entry = new hashNode(key,value);
				if(prev == NULL){
					htable[hashValue] = entry;
				}
				else{
					prev->next = entry;
				}
			}
			else{
				entry->value = value;
			}
		}
		void remove(int key){
			int hashValue = hashFunct(key);
			hashNode *entry = htable[hashValue];
			hashNode *prev = NULL;
			if(entry == NULL){
				cout<<"No key found!"<<endl;
				return;
			}
			while(entry->next && (entry->key != key)){
				prev = entry;
				entry = entry->next;
			}
			if(prev!=NULL &&(entry->key == key)){
				prev->next = entry->next;
				delete entry;
			}
			if(prev==NULL &&(entry->key == key)){
				//prev->next = NULL;
				htable[hashValue] = entry->next;
			}
			cout<<"Element deleted!"<<endl;
		}
		void search(int key){
			bool flag = false;
            int hash_val = hashFunct(key);
            hashNode* entry = htable[hash_val];
            while (entry != NULL &&(flag == false))
	    {
                if (entry->key == key)
	        {
                    cout<<entry->value<<" ";
                    flag = true;
                    return;
                }
                entry = entry->next;
            }
          	 cout<<"Not found!"<<endl;
		}
		
};
int main()
{
    hashMap hash;
    int key, value;
    int choice;
    while (1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search element from the key"<<endl;
        cout<<"3.Delete element at a key"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter element to be inserted: ";
            cin>>value;
            cout<<"Enter key at which element to be inserted: ";
            cin>>key;
            hash.insert(key, value);
            break;
        case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>key;
            cout<<"Element at key "<<key<<" : ";
            hash.search(key);
            break;
        case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>key;
            hash.remove(key);
            break;
        case 4:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}
