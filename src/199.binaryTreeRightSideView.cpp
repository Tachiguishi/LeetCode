#include <solution.h>

vector<int> Solution::rightSideView(TreeNode* root){
	vector<int> res;
	if(!root) return res;

	queue<TreeNode*> layer;
	layer.push(root);
	int prevLayerNum(1);
	int curLayerNum(0);
	while(!layer.empty()){
		TreeNode* node = layer.front();
		if(node->left){
			layer.push(node->left);
			curLayerNum++;
		}
		if(node->right){
			layer.push(node->right);
			curLayerNum++;
		}
		layer.pop();
		prevLayerNum--;
		if(prevLayerNum == 0){
			res.push_back(node->val);
			prevLayerNum = curLayerNum;
			curLayerNum = 0;
		}
	}
	return res;
}

