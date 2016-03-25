MAXN=200
fx=[1,-1,0,0]
fy=[0,0,1,-1]
dp=[[[-1 for i in range(MAXN)] for j in range(MAXN)] for p in range(MAXN)]
class BoardEscapeDiv2:
    def isWinning(self,s,x,y,move):
        n=len(s)
        m=len(s[0])
        if move==0: return False
        if s[x][y]=='E': return False
        if dp[x][y][move]!=-1:
            return dp[x][y][move]
        for i in range(4):
            nx=x+fx[i]
            ny=y+fy[i]
            if nx<0 or ny<0 or nx>=n or ny>=m or s[nx][ny]=='#':
                continue
            if not self.isWinning(s,nx,ny,move-1):
                dp[x][y][move]=True
                return True
        dp[x][y][move]=False
        return False

    def findWinner(self,s,k):
        n=len(s)
        m=len(s[0])
        for i in range(n):
            for j in range(m):
                if s[i][j]=='T':
                    x=i
                    y=j
        return "Alice" if self.isWinning(s,x,y,k) else "Bob"
    
