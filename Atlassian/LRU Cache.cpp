class LRUCache {
public:
    class node{
        public:
            int key;
            int value;
            node *next;
            node *prev;
            node (int key,int val){
                this->key = key;
                this->value= val;
            }

    };
    node  *head = new node(-1,-1);
    node *tail = new node (-1,-1);
    int size;
    unordered_map<int,node*>mp;
    LRUCache(int capacity) {
        this->size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node *newnode){
        node *temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void delnode(node *root){
        node *temp1=root->prev;
        node *temp2=root->next;
        temp1->next=temp2;
        temp2->prev=temp1;
        root->next=nullptr;
        root->prev=nullptr;
        delete(root);
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node *d=mp[key];
            int val=d->value;
            mp.erase(key);
            delnode(d);
            addnode(new node(key,val));
            mp[key]=head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node *d=mp[key];
            mp.erase(key);
            delnode(d);
        }
        if(size==mp.size()){
            mp.erase(tail->prev->key);
            delnode(tail->prev);
        }
        node *newnode=new node(key,value);
        addnode(newnode);
        mp[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */