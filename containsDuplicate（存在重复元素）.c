/*
给定一个整数数组，判断是否存在重复元素。

如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

 

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*/
/*
    该算法先进行排序。采用快速排序，但是对于降序排列的数组会耗费大量时间，于是采用前中后三处选取关键字，进行快速排序。
*/

bool containsDuplicate(int* nums, int numsSize)
{
    int i;
    quick_sort(nums,numsSize);

    for(i=0;i<numsSize-1;i++)
    {
        if(nums[i] == nums[i+1])
        return true;
    }
    return false;
}
void quick_sort(int a[],int longth)
{
	int key,left=0,right=longth-1;
	if(longth == 0||longth ==1)
		return;
	key = mid(&a[left],&a[right],&a[longth/2]);

	while(left != right)
	{
		while(a[right]>=key&&left!=right)
			right--;
		a[left] = a[right];
		while(a[left]<key&&left!=right)
			left++;
		a[right] = a[left];

	}
	a[left] = key;

	quick_sort(a,left);
	quick_sort(a+right+1,longth-right-1);
	return;
}

int mid(int*a,int*b,int*c)
{

	int temp;
    if(*a > *b)
    {
        if(*b > *c)
        {
			temp = *a;
			*a = *b;
			*b = temp;
			return *a;
		}

        if(*a > *c)
        {
			temp = *a;
			*a = *c;
			*c =temp;
			return *a;
		}
        else
        return *a;
    }
    else
    {
        if(*b < *c)
        {
			temp = *a;
			*a = *b;
			*b = temp;
			return *a;
		}
        else
        {
            if(*a > *c)
            return *a;
            else
            {
				temp = *a;
				*a = *c;
				*c = temp;
				return *a;
			}
        }
    }
}

/*
执行结果：
通过
显示详情
执行用时：
104 ms
, 在所有 C 提交中击败了
13.49%
的用户
内存消耗：
10.8 MB
, 在所有 C 提交中击败了
43.65%
的用户
通过测试用例：
69 / 69
*/