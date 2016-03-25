
import Queue

    
class ColorfulRoad:
    def getMin(self,road):
        l=len(road)
        cost=[2000000]*22;
        mymap={'R':0,'G':1,'B':2}
        set=['R','G','B']
        q=Queue.Queue(maxsize=0)
        q.put(0)
        cost[0]=0
        color=0
        while not q.empty():
            p=q.get()
            color=mymap[road[p]]
            for i in range(p+1,l):
                if(road[i]==set[(color+1)%3]):
                    q.put(i)
                    cost[i]=min(cost[i],cost[p]+(i-p)*(i-p))
        if(cost[l-1]==2000000):
            return -1
        else:
            return cost[l-1]
            

    
        
            
    
