#include <iostream>
using namespace std;

typedef struct node
{
	char *code;//����
	struct node *lch,*rch; 
}Bitree;

void HuffmanCode(Node *p, const int numLeafs, string *codes) {
	// pΪ�ڵ������ָ�룬codesΪstring�����ָ�� 
	// ���ڴ洢ÿ���ڵ�Ĺ�������

	// parent��ʾ���ڵ�λ��
	int parent;

	// ÿ�ζ�һ��Ҷ�ӽڵ���б���
	// i��ʾ��ǰҶ�ӽڵ�λ��
	for (int i=0; i < numLeafs; i++) {

		// j��ʾ��ǰ�ڵ�λ�ã�i�ǲ���������ѭ���иı��
		// ʹ��j����¼�ڵ���ƶ�����
		int j = i;

		// ��ǰ�ڵ�ĸ��ڵ�λ��
		parent = p[i].parent;

		// �ӵ�ǰҶ�ӽڵ�p[i]��ʼ���ҵ����������ĸ��ڵ�
		// ѭ�����������Ǵ�ʱparentΪ0�����ﵽ���������ĸ��ڵ�
		while(parent != -1) {

			// �����ǰ�ڵ��Ǹ��ڵ������������˷�֧����Ϊ0
			if (p[parent].left == j) {
				codes[i].push_back('0');
			}

			// �����ǰ�ڵ��Ǹ��ڵ���������������Ϊ1
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
