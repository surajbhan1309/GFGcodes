class Solution:
    def canallocate(self,arr,mid,k):
        students=1
        pages=0
        for x in arr:
            if x+pages<=mid:
                pages+=x
            else:
                students+=1;
                pages=x
        return (students<=k)
        
    def findPages(self, arr, k):
        n=len(arr)
        low=max(arr)
        high=sum(arr)
        if k>n :return -1
        while low<=high:
            mid=low+(high-low)//2
            if self.canallocate(arr,mid,k):
                high=mid-1
            else:
                low=mid+1
        
        return low