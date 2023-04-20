import random
def quickSort(nums: list[int], left, right):
    if (right-left)<1:
        return
    pivot = random.randint(left, right)
    index = left
    nums[pivot], nums[right] = nums[right], nums[pivot]
    for i in range(left, right):
        if nums[i]<nums[right]:
            nums[i], nums[index] = nums[index], nums[i]
            index+=1
    nums[index], nums[right] = nums[right], nums[index]
    quickSort(nums, left, index-1)
    quickSort(nums, index+1, right)

def main():
    nums = [8,5,1,3,4,6,2,7]
    quickSort(nums, 0, len(nums)-1)
    print(nums)

if __name__=='__main__':
    main()
