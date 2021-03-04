/**
 * @file FindKthLargest.cpp
 * @author orxx (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-04
 * 
 * @copyright Copyright (c) 2021
 * 
 * leetcode 215. 数组中的第K个最大元素
 */

class Solution1 {
public:
    // 大根堆 找3个节点中的最大值
    void maxHeapify(vector<int>& nums, int i, int heapSize)
    {
        int l = i*2+1, r = i*2+2, largest = i;
        if (l < heapSize && nums[l] > nums[largest])
        {
            largest = l;
        }
        if (r < heapSize && nums[r] > nums[largest])
        {
            largest = r;
        }      

        // 找到了新的最大值
        if (largest != i)
        {
            swap(nums[i], nums[largest]);
            // 交换了位置后largest所在的子树性质可能发生了改变，需要重新调整堆
            maxHeapify(nums, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& nums, int heapSize)
    {
        // 从后开始找到第一个非叶子节点
        for (int i = heapSize / 2; i >= 0; --i)
        {
            maxHeapify(nums, i, heapSize);
        }        
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        // 找第k大的数 那就调整k-1次(将下标为0的最大数据和末尾交换)
        for (size_t i = 0; i < k-1; i++)
        {
            swap(nums[0], nums[heapSize-1]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};


class Solution2 {
public:
    int getStandard(vector<int>& nums, int low, int high)
    {
        int pivot = nums[low];
        while(low < high)
        {
            // 从high找比pivot小的值交换位置
            while(low < high && nums[high] <= pivot)
            {
                high--;
            }
            // 可能low==high 不需要交换位置
            if(low < high)
            {
                nums[low] = nums[high];
            }

            while(low < high && nums[low] >= pivot)
            {
                low++;
            }     
            if(low < high)
            {
                nums[high] = nums[low];
            }
        }
        nums[low] = pivot;

        return low;
    }
    void quickSort(vector<int>& nums, int low, int high)
    {
        if (low < high)
        {
            int standard = getStandard(nums, low, high);
            quickSort(nums, low, standard - 1);
            quickSort(nums, standard + 1, high);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size()-1);

        return nums[k-1];
    }
};