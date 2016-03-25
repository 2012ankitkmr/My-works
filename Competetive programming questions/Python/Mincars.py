class TrafficCongestionDivTwo:
    def theMinCars(self,treeHeight):
        if(treeHeight%2==0):
            ans=1
        else:
            ans=0
        n=treeHeight
        while(n>0):
            ans+=(pow(2,n)/2)
            n-=2
            
        return ans
        
        

    
