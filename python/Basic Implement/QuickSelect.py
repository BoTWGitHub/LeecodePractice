import random

def quickSelect(nums: list[int], k: int) -> int:
    def partition(left, right, pivot):
        p = nums[pivot]
        nums[right], nums[pivot] = nums[pivot], nums[right]
        index = left
        for i in range(left, right):
            if nums[i]<p:
                nums[i], nums[index] = nums[index], nums[i]
                index+=1
        nums[index], nums[right] = nums[right], nums[index]
        return index

    def select(left, right, k):
        if left==right:
            return nums[left]
        
        i = partition(left, right, random.randint(left, right))
        if i==k:
            return nums[i]
        elif i>k:
            return select(left, i-1, k)
        else:
            return select(i+1, right, k)
    
    return select(0, len(nums)-1, len(nums)-k)

def main():
    nums = [5,2,7,9,3,4,1,8]
    k = 6
    print(quickSelect(nums, k))
    print(sorted(nums)[-k])

if __name__=='__main__':
    main()
