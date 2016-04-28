#include <stdio.h>
#include <stdlib.h>

void TreeSelectSort(int* mData, int Count)  // mData�洢���Ԫ��ֵ(Ҳ�ǱȽϵĹؼ��ֵ�ֵ), CountΪ��
{                               
	int TreeLong = Count * 2;		//����С
	int MinValue = -10000;		// �����в����ܴﵽ����
	int tree[1024];				// �˴������ʼ�����εĴ�С��Ĭ��Ϊ
	int baseSize;				/* ��Count��2���ݴ�ʱ��baseSize��Count����Count����ʱ��baseSize
								�Ǵ���n����С��2���ݴΣ����ǹ�����������������²�Ĵ�С��*/
	int i;
	int n = Count;
	int max;						// ���ֵ
	int maxIndex;					// ��������±�
	int treeSize;					// �����������ﵽ�Ĵ�С
	baseSize = 1;
	while (baseSize < n)
		baseSize *= 2;
	treeSize = baseSize * 2 - 1; // �������������н���������Ҷ�����ı���һ
	for (i = 0; i < n; i++)// ������ĺ��沿�ֿ�ʼ���
		tree[treeSize-i] = mData[i];
	// ��MinValue���treeֱ��һ����baseSize��
	for (; i < baseSize; i++)
		tree[treeSize-i] = MinValue;
	for (i=treeSize; i>1; i-=2) // ����һ����
		//��mData[i]��mData[i+1]Ϊ�ӽ������ĸ���mData[i]��mData[i+1]�еĽϴ���
		tree[i / 2] = (tree[i] > tree[i - 1] ? tree[i] : tree[i - 1]);
	n -= 1;
	/* ��ʱ��n��ʾ��ǰtree[1]Ӧ�ŵ�mData�е�λ�ã����ϰ�����Ϊ���ֵ�Ľ�����ߡ�
	   ֱ��n��ֵΪ-1����ʱ������Ҫ����Ľ�㶼�Ѿ���ѡ����*/
	while (n != -1)
	{
		max = tree[1];
		mData[n--] = max;
		maxIndex = treeSize;
		/* ��Ҷ�����ҵ����ֵ��Ӧ���±�*/
		while (tree[maxIndex] != max)
			maxIndex--;
		tree[maxIndex] = MinValue;
		// ����Ҷ���ϵĽ�㵽����·������
		while(maxIndex > 1) // ����㻹�и����ʱ
		{
			if (maxIndex % 2 == 0) //���ֵΪ���ֵ�Ľ�������ӽ��
			{// ���ӽ���нϴ�ֵ���游���
				tree[maxIndex / 2] = 
						(tree[maxIndex] > tree[maxIndex + 1] ? tree[maxIndex] : tree[maxIndex + 1]);
			}
			else // ����������ӽ��
			{
				tree[maxIndex / 2] = 
						(tree[maxIndex] > tree[maxIndex - 1] ? tree[maxIndex] : tree[maxIndex - 1]);
			}
			maxIndex /= 2; // �����������
		}
	}
}


void main()
{
	int i, a[10]={23,45,4,67,1,90,86,12,100,200};
	TreeSelectSort(a, 10);
    
	for(i=0;i<10;i++)
		printf("%d  ",a[i]);

}