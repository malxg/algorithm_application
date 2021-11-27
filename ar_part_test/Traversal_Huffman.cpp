#include <iostream>
using namespace std;

typedef struct node
{
	char *code;//编码
	struct node *lch,*rch; 
}Bitree;

void HuffmanCode(Node *p, const int numLeafs, string *codes) {
	// p为节点数组的指针，codes为string数组的指针 
	// 用于存储每个节点的哈夫曼码

	// parent表示父节点位置
	int parent;

	// 每次对一个叶子节点进行编码
	// i表示当前叶子节点位置
	for (int i=0; i < numLeafs; i++) {

		// j表示当前节点位置，i是不能在下面循环中改变的
		// 使用j来记录节点的移动过程
		int j = i;

		// 当前节点的父节点位置
		parent = p[i].parent;

		// 从当前叶子节点p[i]开始，找到哈夫曼树的根节点
		// 循环结束条件是此时parent为0，即达到哈夫曼树的根节点
		while(parent != -1) {

			// 如果当前节点是父节点的左子树，则此分支编码为0
			if (p[parent].left == j) {
				codes[i].push_back('0');
			}

			// 如果当前节点是父节点的右子树，则编码为1
			else {
				codes[i].push_back('1');
			}
   
			j = parent;
			parent = p[j].parent;
		}
		cout << codes[i] << endl;
	}
}

int main()
{
	return 0;
}
