class EmoticonsDiv2:
    dp=[[0 for x in range(1003)] for x in range(1003)]
    def compute(self,clipboard,message,cnt,n):
        if(message>n):
            return 44444444444444        
        if(message==n):
            return cnt
        if(dp[clipboard][message]!=-1):
            return dp[clipboard][message]
        dp[clipboard][message]=min(compute(message,message,cnt+1,n),compute(clipboard,message+clipboard,cnt+1,n))
        return dp[clipboard][message]
s
    
    def printSmiles(self,smiles):
        for x in range(0,1002):
            for y in range(0,1002):
                dp[x][y]=-1
        ans=compute(0,1,0,smiles)
        return ans 

    
    
    
