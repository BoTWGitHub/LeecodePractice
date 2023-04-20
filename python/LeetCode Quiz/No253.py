from typing import List

class MinHeap:
    def __init__(self):
        self.nums = []
    
    def insert(self, val: int):
        self.nums.append(val)
        index = len(self.nums)-1
        while index > 0:
            if self.nums[(index-1)//2]>val:
                self.nums[(index-1)//2], self.nums[index] = self.nums[index], self.nums[(index-1)//2]
                index = (index-1)//2
            else:
                break
    
    def getMin(self) -> int:
        if not self.nums:
            return []
        return self.nums[0]

    def popMin(self) -> int:
        if not self.nums:
            return []
        self.nums[0], self.nums[-1] = self.nums[-1], self.nums[0]
        res = self.nums.pop()
        index = 0
        while (index*2+1)<len(self.nums):
            left, right = index*2+1, index*2+2
            swap = left
            if right<len(self.nums) and self.nums[right]<self.nums[left]:
                swap = right
            
            if self.nums[swap]<self.nums[index]:
                self.nums[index], self.nums[swap] = self.nums[swap], self.nums[index]
                index = swap
            else:
                break
        return res

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        roomCount = 0
        maxRoomCount = 0
        minStart = 1000000
        maxEnd = 0

        for start, end in intervals:
            minStart = min(minStart, start)
            maxEnd = max(maxEnd, end)

        for time in range(minStart, maxEnd+1):
            for start, end in intervals:
                if start == time:
                    roomCount+=1
                if end == time:
                    roomCount-=1
            maxRoomCount = max(maxRoomCount, roomCount)
        return maxRoomCount
    
    def minMeetingRooms2(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals)
        roomCount = 0
        maxRoomCount = 0
        heap = MinHeap()
        for start, end in intervals:
            while heap.getMin() and start>=heap.getMin():
                heap.popMin()
                roomCount-=1
            roomCount+=1
            maxRoomCount = max(maxRoomCount, roomCount)
            heap.insert(end)

        return maxRoomCount

    def minMeetingRooms3(self, intervals: List[List[int]]) -> int:
        timestamp = []
        for start, end in intervals:
            timestamp.append([start, 1])
            timestamp.append([end, -1])

        timestamp.sort()
        
        roomCount = 0
        maxRoomCount = 0
        for _, room in timestamp:
            roomCount+=room
            maxRoomCount = max(maxRoomCount, roomCount)
        return maxRoomCount

solution = Solution()
intervals = [[55720,349290],[688809,868579],[405490,841727],[145683,162453],[161225,936277],[319899,784036],[47904,139575],[58916,998828],[223305,745027],[353070,801099],[498237,899576],[545153,689213],[580153,668329],[36374,364587],[73797,257807],[389937,930931],[238654,297234],[222415,942372],[83322,317295],[53474,516376],[78109,194849],[312232,728350],[62606,892477],[289983,677972],[524923,626259],[421051,862946],[854186,876721],[398669,740947],[198520,864653],[764076,948535],[51130,226137],[273686,541633],[59923,106998],[206544,211760],[754288,843998],[850133,982427],[559760,676574],[189946,459169],[934775,952899],[195284,312052],[75317,138600],[84724,484201],[3472,970066],[182813,247978],[113082,897914],[443140,666044],[140111,928781],[322697,855303],[238006,298073],[178580,740526],[43876,97211],[76529,458293],[586411,809637],[513611,518730],[262290,391753],[169619,895289],[550535,708133],[205321,997268],[278572,445336],[172270,179282],[879628,991532],[509348,541320],[301939,470129],[21603,678763],[450526,731148],[239862,974936],[10253,255308],[213914,908486],[455324,816438],[62108,964099],[167976,798660],[219825,315546],[172611,389151],[118319,658061],[402935,823442],[593991,783234],[426150,943246],[289753,692787],[447005,816658],[327385,440307],[249162,321630],[429499,595607],[381038,475281],[583186,989552],[655808,986935],[144494,825667],[24238,483480],[122773,632790],[715548,934283],[41838,477020],[691714,983762],[132740,404906],[471526,819622],[34304,215501],[623145,768663],[373850,673373],[560514,869162],[736155,882633],[491072,985459],[238611,953699],[164538,615999],[252995,535799],[475528,482423],[4941,673059],[196736,421327],[681519,849447],[81674,95942],[741860,904793],[504991,649586],[344002,772544],[87001,853983],[231865,812943],[198253,713577],[181318,481445],[677759,884948],[844883,903007],[8059,248529],[843579,921791],[94492,853040],[419339,421774],[316916,905120],[297521,309109],[583854,600414],[377707,608513],[406966,485538],[294892,792676],[580154,723401],[225277,534109],[417813,959630],[182133,292049],[64994,842555],[51116,314039],[509615,872446],[115887,510640],[256739,523185],[445024,672722],[274078,898657],[591988,707638],[891114,908492],[493026,914060],[312207,475083],[556210,841875],[264146,622094],[82996,521419],[492091,699531],[87732,986277],[89747,721583],[90224,915337],[634391,941405],[428041,460798]]
#intervals = [[0,30],[5,10],[15,20],[3,22],[6,10],[31,35]]
print(solution.minMeetingRooms3(intervals))