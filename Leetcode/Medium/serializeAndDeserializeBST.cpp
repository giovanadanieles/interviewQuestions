/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// Ref: https://www.youtube.com/watch?v=sw4mNP23-v0

// Space: 27 MB, less than 61.56% of C++ online submissions
//  Time: 53 ms, faster than 45.86% of C++ online submissions
class Codec {
public:
    void preOrder(TreeNode *root, string &serialized){
        if(root == NULL) return;
        
        serialized += to_string(root->val) + ",";
        
        preOrder(root->left, serialized);
        preOrder(root->right, serialized);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized;
        
        preOrder(root, serialized);
        if(!serialized.empty()) serialized.pop_back();
        
        return serialized;
    }
    
    vector<int> strToVec(string data){
        string aux = "";
        vector<int> values;
        
        for(unsigned int i = 0; i < data.size(); i++){
            if(data[i] != ',') aux += data[i];
            if(data[i] == ',' || i + 1 == data.size()) 
                values.push_back(stoi(aux)), aux = "";
        }
        
        return values;
    }
    
    TreeNode* recovery(vector<int> &values, int &index, int lowerBound, int upperBound){
        if(index >= values.size()) return NULL;
        else if(lowerBound > values[index] || upperBound < values[index]) return NULL;
        
        TreeNode *cur = new TreeNode(values[index]);
        index++;
        
        cur->left = recovery(values, index, lowerBound, cur->val);
        cur->right = recovery(values, index, cur->val, upperBound);
        
        return cur;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        int index = 0;
        vector<int> values = strToVec(data);
        
        return recovery(values, index, INT_MIN, INT_MAX);
    }
};



// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
