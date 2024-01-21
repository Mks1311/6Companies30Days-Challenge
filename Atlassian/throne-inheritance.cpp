class ThroneInheritance {
private:
    struct tree{
        string name;
        vector<tree*>childrens;
    };
public:
    tree *root;
    unordered_map<string,tree*>mp;
    ThroneInheritance(string kingName) {
        root=new tree();
        root->name=kingName;
        mp[kingName]=root;
    }
    
    void birth(string parentName, string childName) {
        tree* child=new tree();
        child->name=childName;
        mp[parentName]->childrens.push_back(child);
        mp[childName]=child;
    }
    
    void death(string name) {
        mp[name]=nullptr;
    }
    void get(tree *root,vector<string>&ans){
        if(mp[root->name]!=nullptr) ans.push_back(root->name);
        for(int i=0;i<root->childrens.size();i++){
            get(root->childrens[i],ans);
        }
        return;
    }
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        get(root,ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */