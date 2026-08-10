class Solution:
    def maxWater(self, arr):
        n=len(arr)
        lmax=0
        rmax=0
        left=0
        right=n-1
        ans=0
        for i in range(n):
            lmax=max(lmax,arr[left])
            rmax=max(rmax,arr[right])
            if lmax<rmax:
                ans+=lmax-arr[left]
                left+=1
            else:
                ans+=rmax-arr[right]
                right-=1
        return ans
        