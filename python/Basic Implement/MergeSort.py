def mergeSort(nums: list[int]) -> list[int]: #top-down
    if len(nums)<=1:
        return nums
    mid = len(nums)//2
    left = mergeSort(nums[:mid])
    right = mergeSort(nums[mid:])
    p1, p2 = 0, 0
    temp = []
    while p1<len(left) and p2<len(right):
        if left[p1]<=right[p2]:
            temp.append(left[p1])
            p1+=1
        else:
            temp.append(right[p2])
            p2+=1
    return temp+right[p2:]+left[p1:]

def main():
    nums = [8,5,1,3,4,6,2,7]
    nums = mergeSort(nums)
    print(nums)

if __name__=='__main__':
    main()
