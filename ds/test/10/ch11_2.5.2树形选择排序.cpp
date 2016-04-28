#include <stdio.h>
#include <stdlib.h>

void TreeSelectSort(int* mData, int Count)  // mData存储结点元素值(也是比较的关键字的值), Count为表长
{                               
	int TreeLong = Count * 2;		//树大小
	int MinValue = -10000;		// 整数中不可能达到的数
	int tree[1024];				// 此处放入初始化树形的大小，默认为
	int baseSize;				/* 当Count是2的幂次时，baseSize是Count；当Count不是时，baseSize
								是大于n的最小的2的幂次；就是构造成满二叉树的最下层的大小。*/
	int i;
	int n = Count;
	int max;						// 最大值
	int maxIndex;					// 最大数的下标
	int treeSize;					// 最终这棵树会达到的大小
	baseSize = 1;
	while (baseSize < n)
		baseSize *= 2;
	treeSize = baseSize * 2 - 1; // 满二叉树的所有结点个数等于叶子数的倍减一
	for (i = 0; i < n; i++)// 从数组的后面部分开始填充
		tree[treeSize-i] = mData[i];
	// 用MinValue填充tree直到一共有baseSize个
	for (; i < baseSize; i++)
		tree[treeSize-i] = MinValue;
	for (i=treeSize; i>1; i-=2) // 构造一棵树
		//以mData[i]和mData[i+1]为子结点的数的根是mData[i]和mData[i+1]中的较大者
		tree[i / 2] = (tree[i] > tree[i - 1] ? tree[i] : tree[i - 1]);
	n -= 1;
	/* 此时的n表示当前tree[1]应放到mData中的位置，不断把树中为最大值的结点移走。
	   直到n的值为-1，此时，所有要排序的结点都已经被选走了*/
	while (n != -1)
	{
		max = tree[1];
		mData[n--] = max;
		maxIndex = treeSize;
		/* 在叶子上找到最大值对应的下标*/
		while (tree[maxIndex] != max)
			maxIndex--;
		tree[maxIndex] = MinValue;
		// 沿着叶子上的结点到根的路径更新
		while(maxIndex > 1) // 当结点还有父结点时
		{
			if (maxIndex % 2 == 0) //如果值为最大值的结点是左子结点
			{// 用子结点中较大值代替父结点
				tree[maxIndex / 2] = 
						(tree[maxIndex] > tree[maxIndex + 1] ? tree[maxIndex] : tree[maxIndex + 1]);
			}
			else // 如果不是左子结点
			{
				tree[maxIndex / 2] = 
						(tree[maxIndex] > tree[maxIndex - 1] ? tree[maxIndex] : tree[maxIndex - 1]);
			}
			maxIndex /= 2; // 继续处理父结点
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