// Runtime: 96 ms, faster than 32.70% of C++ online submissions
// Memory Usage: 29 MB, less than 93.70% of C++ online submissions


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        int lastValidIndex;
        string ans = "";
        TreeNode *cur;
        queue<TreeNode*> q;
                
        q.push(root);
        
        while(!q.empty()){
            cur = q.front();
            q.pop();
            
            if(cur != NULL) ans += to_string(cur->val) + " ";
            else ans += "N ";
            
            if(cur != NULL) q.push(cur->left);
            if(cur != NULL) q.push(cur->right);
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {  
        string str;
        stringstream s(data);
        TreeNode *root, *cur;
        queue<TreeNode*> q;
                
        if(data.size() == 2) return NULL;
        
        getline(s, str, ' ');
                
        root = new TreeNode(stoi(str));
        
        q.push(root);
        
        while(!q.empty()){
            cur = q.front();
            q.pop();
            
            getline(s, str, ' ');
            if(str == "N") cur->left = NULL;
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                cur->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s, str, ' ');
            if(str == "N") cur->right = NULL;
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                cur->right = rightNode;
                q.push(rightNode);
            }            
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
