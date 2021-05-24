//小根堆

//思路：
//---------------------------迭代----------------------------
//1. 先找child中小的那个
//2. child和parent进行比较，若a[child] < a[parent]，进行swap。否则break
//3. parent = child, child = 2 * child + 1;
//---------> 进入迭代。		迭代条件，child < size


//以该节点为父节点，进行向下调整
void AdjustDown(int* a, int size, int root)		//需要知道：数组的大小； 你所要进行向下调整的根节点的下标
{
	//从上到下进行调整
	int parent = root;
	
	while(parent * 2 + 1 < size)//迭代结束条件，没有左孩子就结束
	{
		int child = 2 * parent + 1;
		if(child + 1 < size && a[child] > a[child + 1])//找出左右孩子中较小的那个
		{
			++child;
		}
		
		if(a[parent] < a[child])
		{
			break;	//迭代结束条件，父节点比子节点小结束(小根堆)
		}
		else
		{
			swap(a[parent], a[child]);//否则swap两者
		}
		parent = child;
		//child = 2 * parent + 1;
	}
}

//思路：
//---------------------------迭代----------------------------
//1. 以child为子节点， parent = (child - 1) / 2
//2. child和parent进行比较，若a[child] < a[parent]，进行swap。否则break
//3. child = parent
//---------> 进入迭代。		迭代条件，child > 0

//以该节点为子节点进行向上调整
void AdjustUp(int* a, int child)	//只需要知道： child结点的下标即可。 与该数组的大小无关
{
	while(child > 0)
	{
		int parent = (child - 1) / 2;
		
		if(a[child] < a[parent])
		{
			swap(a[child], a[parent]);
		}
		else
		{
			break;
		}
		child = parent;
	}
}