#include <solution.h>
#include <stack>

BSTIterator::BSTIterator(TreeNode *root){
	while(nullptr != root){
		m_leftNodes.push(root);
		root = root->left;
	}
}

bool BSTIterator::hasNext(){
	return m_leftNodes.size() > 0;
}

int BSTIterator::next(){
	TreeNode* node = m_leftNodes.top();
	m_leftNodes.pop();
	int res = node->val;
	
	node = node->right;
	while(node != nullptr){
		m_leftNodes.push(node);
		node = node->left;
	}

	return res;
}
