def heapsort(nums: list[int]):
    def sinking(index: int, last):
        while index*2+1<last:
            swap = index*2+1
            if index*2+2<last and nums[index*2+2]>nums[swap]:
                swap+=1
            if nums[swap]>nums[index]:
                nums[swap], nums[index] = nums[index], nums[swap]
                index = swap
            else:
                break

    #heapify the nums
    for i in range(len(nums)-1, -1, -1):
        sinking(i, len(nums))

    #swap max to the last
    length = len(nums)-1
    while length>1:
        nums[0], nums[length] = nums[length], nums[0]
        length-=1
        #sink the top element
        sinking(0, length)
            

def main():
    nums = [7, 3, 2, 5, 6, 4, 9, 8, 1]
    print(nums)

    heapsort(nums)
    print(nums)

if __name__=='__main__':
    main()
