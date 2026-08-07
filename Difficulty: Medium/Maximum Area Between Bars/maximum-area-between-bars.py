class Solution:
    def maxArea(self, height):
        j=len(height)-1
        i=0
        ans=0
        while i<j:
            width=j-i-1
            if height[i]<height[j]:
                ans=max(ans,width*height[i])
                i+=1
            elif height[j]<height[i] :
                ans=max(ans,width*height[j])
                j-=1
            else:
                ans=max(ans,width*height[i])
                i+=1
                j-=1
        return ans