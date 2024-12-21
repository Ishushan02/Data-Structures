/*
    450. Delete Node in a BST
    (https://leetcode.com/problems/delete-node-in-a-bst/description/)

    Method 1.
    int getMax(TreeNode* root){
        if(root == NULL){
            return -1;
        }

        while(root->right){
            root = root->right;
        }

        return root->val;
    }

    TreeNode* deleteBSTNode(TreeNode* root, int key){
        if(root == NULL){
            return NULL;
        }

        if(root->val == key){

            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }else if(root->left != NULL && root->right == NULL){
                TreeNode* leftchild = root->left;
                root->left = NULL;
                delete root;
                return leftchild;
            }else if(root->right != NULL && root->left == NULL){
                TreeNode* rightchild = root->right;
                root->right = NULL;
                delete root;
                return rightchild;
            }else{

                int maxVal = getMax(root->left);
                root->val = maxVal;

                root->left = deleteBSTNode(root->left, maxVal);

                return root;
            }

        }else{

            if(key < root->val){
                root->left = deleteBSTNode(root->left, key);
            }else{
                root->right = deleteBSTNode(root->right, key);
            }
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        TreeNode* node = deleteBSTNode(root, key);

        return node;
    }




    Method 2 (Iplace Method)
    TreeNode* deleteBSTNode(TreeNode* root, int key){

        if(root == NULL){
            return NULL;
        }

        if(root->val == key){

            // root is leaf Node with no child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }else if(root->left != NULL && root->right == NULL){ //only left child

                TreeNode* leftchild = root->left;
                delete root;
                return leftchild;
            }else if(root->left == NULL && root->right != NULL){ //only right child

                TreeNode* rightchild = root->right;
                delete root;
                return rightchild;
            }else{

                // get min of right subtree
                // minNode ka left hoga root-right
                // delete root

                TreeNode* leftmin = root->right;
                // TreeNode* rootleft = root->left;
                TreeNode* rightChild = root->right;
                
                while(leftmin->left){
                    leftmin = leftmin->left;
                }

                leftmin->left = root->left;
                delete root;
                return rightChild;


            }
        }else{

            if(key > root->val){
                root->right = deleteBSTNode(root->right, key);
            }else{
                root->left = deleteBSTNode(root->left, key);
            }
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        TreeNode* ans = deleteBSTNode(root, key);
        return ans;
    }

*/

/*
    653. Two Sum IV - Input is a BST
    (https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/)

    void preOrder(TreeNode* root, vector<int> &nodes){
        if(root == NULL){
            return ;
        }
        
        preOrder(root->left, nodes);
        nodes.push_back(root->val);
        preOrder(root->right, nodes);

    }

    bool twoPointerSum(vector<int> arr, int k){
        int start = 0;
        int n = arr.size();
        int end = n -1 ;

        while(start < end){
            int sum = arr[start] + arr[end];

            if(sum == k){
                return true;
            }
            else if(sum > k){
                end--;
            }else{
                start++;
            }
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        
        vector<int> arr;
        preOrder(root, arr);

        return twoPointerSum(arr, k);
    }
*/

/*
    1038. Binary Search Tree to Greater Sum Tree (Same as LC. 538)
    (https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/)

    void getSum(TreeNode* root, TreeNode* currNode, int &ans){

        if(root == NULL){
            return ;
        }

        if(root->val > currNode->val){
            ans += root->val;
        }
        getSum(root->left, currNode, ans);
        getSum(root->right, currNode, ans);

    }

    void storeNodes(TreeNode* root, TreeNode* rootNode, unordered_map<int, int> &ansMap){
        if(root == NULL){
            return;
        }
        int ans = root->val;
        getSum(rootNode, root, ans);
        ansMap[root->val] = ans;

        
        storeNodes(root->left, rootNode, ansMap);
        storeNodes(root->right, rootNode, ansMap);

    }

    void changeNodes(TreeNode* &root, unordered_map<int, int> &ansMap){
        if(root == NULL){
            return;
        }
        root->val = ansMap[root->val];
        
        changeNodes(root->left, ansMap);
        changeNodes(root->right, ansMap);
    }

    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        unordered_map<int, int> ansMap;
        storeNodes(root, root, ansMap);
        changeNodes(root, ansMap);
        // for(auto values:ansMap){
        //     // cout << values.first->val << " ParentNode: " << values.second->val << endl;
        //     // int sum = getSum(values.second, values.first->val, values.first->val);
        //     cout << values.first << ": " << values.second << endl;

        // }
        


        return root;

    }


    Method 2 (same question 538 and 1038) {BEST APPROACH }
    538. Convert BST to Greater Tree
    (https://leetcode.com/problems/convert-bst-to-greater-tree/description/)

    void totalSum(TreeNode* root, int &sum){
        if(root == NULL){
            return ;
        }

        totalSum(root->left, sum);
        sum += root->val;
        totalSum(root->right, sum);

    }

    void inorderTraversal(TreeNode* root, int &maxSum){
        if(root == NULL){
            return ;
        }

        inorderTraversal(root->left, maxSum);
        int temp = root->val;
        root->val = maxSum;
        maxSum = maxSum - temp ;
        inorderTraversal(root->right, maxSum);

    }
*/

/*
    230. Kth Smallest Element in a BST
    (https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)

    void inorderTraversal(TreeNode* root, vector<int>& arr){
        if(root == NULL){
            return;
        }

        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> arr;
        inorderTraversal(root, arr);

        return arr[k - 1];
    }


    // Method 2 (Same procedure without Space)

    // method 2 without extra O(n) space

    void inOrderTraversal(TreeNode* root, int &count, int &ans, int k){
        if(root == NULL){
            return ;
        }
        
        inOrderTraversal(root->left, count, ans, k);
        count = count + 1;
        if(count == k){
            ans = root->val;
            cout << ":--"<< ans << endl;
            // k = 100000;
        }
        inOrderTraversal(root->right, count, ans, k);

    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int count = 0;
        inOrderTraversal(root, count, ans, k);

        return ans;
    }
*/

/*
    235. Lowest Common Ancestor of a Binary Search Tree
    (https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)


    Method 1 // Normal Binary Tree Approach
    TreeNode* processLCA(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root == NULL){
            return NULL;
        }

        if(root->val == p->val){
            return p;
        }
        if(root->val == q->val){
            return q;
        }

        TreeNode* ans1 = processLCA(root->left, p, q);
        TreeNode* ans2 = processLCA(root->right, p, q);

        if(ans1 == NULL && ans2 == NULL){
            return NULL;
        }else if(ans1 != NULL && ans2 == NULL){
            return ans1;
        }else if(ans2 != NULL && ans1 == NULL){
            return ans2;
        }

        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return processLCA(root, p, q);
    }


    Method 2 {Use BST Property}
        TreeNode* processLCA(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root == NULL){
            return NULL;
        }

        // Node lies in left part
        if (p->val < root->val && q->val < root->val){
            TreeNode* lans = processLCA(root->left, p, q);
            if(lans != NULL){
                return lans;
            }
        
        // Node lies in right part
        }else if (p->val > root->val && q->val > root->val){
            TreeNode* rans = processLCA(root->right, p, q);
            if(rans != NULL){
                return rans;
            }
        }

        //else root is the common one
        return root;
       
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return processLCA(root, p, q);
    }
*/

/*
    108. Convert Sorted Array to Binary Search Tree
    (https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

    void createTree(int start, int end, vector<int> &nums, TreeNode* &root){

        if(end < start || start > end){
            return ;
        }

        int mid = (start + end) / 2;

        TreeNode* newNode = new TreeNode(nums[mid]);

        if(root == NULL){
            root = newNode;
        }else{
            if(nums[mid] > root->val){
                root->right = newNode;
            }else{
                root->left = newNode;
            }
        }

        // left Subtree
        createTree(start, mid - 1, nums, newNode);

        //right Subtree
        createTree(mid + 1, end, nums, newNode);


    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size() - 1;
        TreeNode* root = NULL;
        createTree(start, end, nums, root);

        return root;
    }
*/

/*
    Binary Tree to DLL
    (https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1)

    void getNodes(Node* root, vector<int> &arr){
        if(root == NULL){
            return ;
        }
        
        getNodes(root->left, arr);
        arr.push_back(root->data);
        getNodes(root->right, arr);
        
    }
    
    void createDLL(Node* &root, vector<int> &arr, int currIdx, Node* &head){
        
        if(currIdx >= arr.size()){
            return;
        }
        
        int curr = arr[currIdx];
        Node* currNode = new Node(curr);

        if(root == NULL){
            root = currNode;
            head = currNode;
        }else{
            root->right = currNode;
            currNode->left = root;
        }
        createDLL(currNode, arr, currIdx + 1, head);
        
    }
  
    Node* bToDLL(Node* root) {
        // code here
        
        Node* startNode = NULL;
        Node* head = NULL;
        vector<int> arr;
        int currIdx = 0;
        getNodes(root, arr);
        createDLL(startNode, arr, currIdx, head);
        
        return head;
    }


    Method 2 (Inplace Method: doesn't use extra space)

    void createTree(Node* root, Node* &head){
        if(root == NULL){
            return ;
        }
        
        createTree(root->right, head);
        root->right = head;
        if(head != NULL){
            head->left = root;
        }
        head = root;// update head
        
        createTree(root->left, head);
        
    }
  
    Node* bToDLL(Node* root) {
        // code here
        
        Node* ans = NULL;
        createTree(root, ans);
        return ans;
    }

*/

/*
    109. Convert Sorted List to Binary Search Tree
    (https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/)

    Method 1 -> same as above 108
    void createTree(int start, int end, vector<int> &nums, TreeNode* &root){

        if(end < start || start > end){
            return ;
        }

        int mid = (start + end) / 2;

        TreeNode* newNode = new TreeNode(nums[mid]);

        if(root == NULL){
            root = newNode;
        }else{
            if(nums[mid] > root->val){
                root->right = newNode;
            }else{
                root->left = newNode;
            }
        }

        // left Subtree
        createTree(start, mid - 1, nums, newNode);

        //right Subtree
        createTree(mid + 1, end, nums, newNode);


    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;

        ListNode* temp = head;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        int start = 0;
        int end = nums.size() - 1;
        TreeNode* root = NULL;
        createTree(start, end, nums, root);

        return root;
    }


    Method 2 : Intution is same as that of above (Do this again)

    int getLength(ListNode* head){
        int n = 0;
        while(head){
            n += 1;
            head = head->next;
        }
        return n;
    }

    TreeNode* createTree(ListNode* &head, int n){ 
        if(head == NULL || n <= 0){
            return NULL;
        }

        TreeNode* leftSubtree = createTree(head, n/2);

        TreeNode* root = new TreeNode(head->val);
        root->left = leftSubtree;
        head = head->next;
        TreeNode* rightSubtree = createTree(head, n - n/2 -1); // -1 beacuse root node is also excluded
        root->right = rightSubtree;

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // the procedure will be same as of 108
        // divide in between and get  root Node

        int n = getLength(head);

        TreeNode* root = createTree(head, n);

        return root;

    }

*/


/*
    98. Validate Binary Search Tree
    (https://leetcode.com/problems/validate-binary-search-tree/)

    Method 1. (Best Way is Range Method )
    bool isbst(TreeNode* root, long lowRange, long highRange){
        if(root == NULL){
            return true;
        }

        // cout << root->val << ": " << lowRange <<" <-> " << highRange << endl;
        if(!((lowRange < root->val) && (root->val < highRange))){
            return false;
        }

        bool lans = isbst(root->left, lowRange, root->val);
        bool rans = isbst(root->right, root->val, highRange);

        return lans && rans;
    }

    bool isValidBST(TreeNode* root) {
        
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        
        return isbst(root, LONG_MIN, LONG_MAX);
    }


    Method 2. (Bad Method) // but correct solution
    void getInorder(TreeNode* root, vector<int> &arr){
        if(root == NULL){
            return ;
        }
        getInorder(root->left, arr);
        arr.push_back(root->val);
        getInorder(root->right, arr);

    }

    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        getInorder(root, arr);

        int start = 0;
        int next = 1;

        while(next < arr.size()){
            if(arr[start] >= arr[next]){
                cout << arr[start] << " " << arr[next] << endl;
                return false;
            }
            start += 1;
            next += 1;
        }
        return true;
    }

*/


/*

    1373. Maximum Sum BST in Binary Tree (Interview Question,/ coding wise global MaxSum )
    (https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/)


    struct Info{
        bool isbst = true;
        int sum = 0;
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
    };
    int Maxsum = 0 ;
    Info traverse(TreeNode* root){
        if (root == NULL){
            Info temp;
            temp.isbst = true;
            temp.sum = 0;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            return temp;
        }

        Info leftAns = traverse(root->left);
        Info rightAns = traverse(root->right);


        Info currNode;
        //is bst
        if(root->val > leftAns.maxVal && root->val < rightAns.minVal && leftAns.isbst && rightAns.isbst){
            currNode.isbst = true;
            currNode.sum = root->val + leftAns.sum + rightAns.sum;
            Maxsum = max(Maxsum, currNode.sum);
            currNode.minVal = min(root->val, min(leftAns.minVal, rightAns.minVal));
            currNode.maxVal = max(root->val, max(leftAns.maxVal, rightAns.maxVal));
            return currNode;
        }
        
        currNode.isbst = false;
        currNode.sum = max(leftAns.sum, max(Maxsum, rightAns.sum));
        currNode.minVal = min(root->val, min(leftAns.minVal, rightAns.minVal));
        currNode.maxVal = max(root->val, max(leftAns.maxVal, rightAns.maxVal));
        return currNode;

        // you can also return {false, 0, 0, 0} in else case
    }

    int maxSumBST(TreeNode* root) {
        
        int ans = 0;
        Info temp = traverse(root);
        // cout << temp.isbst << " " <<temp.sum  << " "<<temp.minVal  << " " <<temp.maxVal << endl;
        return Maxsum;
    }
*/

/*
    783. Minimum Distance Between BST Nodes
    (https://leetcode.com/problems/minimum-distance-between-bst-nodes/)


    void traverseInorder(TreeNode* root, vector<int> &arr){


        if(root == NULL){
            return ;
        }
        traverseInorder(root->left, arr);
        arr.push_back(root->val);
        traverseInorder(root->right, arr);
    }



    int minDiffInBST(TreeNode* root) {
        vector<int> arr;
        traverseInorder(root, arr);

        int i = 0;
        int j = i + 1;
        int ans = INT_MAX;
        while(j < arr.size()){
            ans = min(ans, arr[j] - arr[i]);
            i += 1;
            j += 1;
        }
        return ans;
    }
*/