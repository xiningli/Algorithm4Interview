import numpy as np
class Heap_Min:
    def __init__(self):
        self.min_heap = []    
    def _get_parent_index(self,current_index):
        return int(np.ceil( current_index/2.0 ))-1
    
    def _get_children_index(self,current_index):
        size = len(self.min_heap)
        potential_left_index = (current_index+1)*2-1
        if potential_left_index >size-1:
            left_c_index = None
            right_c_index = None
            
        else:
            left_c_index = potential_left_index
            if potential_left_index+1<=size-1:
                right_c_index = potential_left_index+1
            else:
                right_c_index = None
                
            
        return (left_c_index,right_c_index)
            
        
    
    def _swap(self):
        self.min_heap[self.current_index],self.min_heap[self.parent_index]=self.min_heap[self.parent_index],self.min_heap[self.current_index]    
        
        self.current_index=self.parent_index
        self.parent_index = self._get_parent_index(self.current_index)
    
        if (self.parent_index>=0) and (self.min_heap[self.current_index]<self.min_heap[self.parent_index]):
            self._swap()
            
    def _swap_pop(self):

        if self.left_c_index!=None:
            if self.right_c_index==None:
                if self.min_heap[self.current_index]>self.min_heap[self.left_c_index]:
                    self.min_heap[self.current_index],self.min_heap[self.left_c_index] = self.min_heap[self.left_c_index], self.min_heap[self.current_index]
            else:
                if self.min_heap[self.current_index]>self.min_heap[self.left_c_index] or self.min_heap[self.current_index]>self.min_heap[self.right_c_index]:  
                    if self.min_heap[self.left_c_index]<=self.min_heap[self.right_c_index]:
                        
                        
                        self.min_heap[self.current_index],self.min_heap[self.left_c_index]=self.min_heap[self.left_c_index],self.min_heap[self.current_index]
                        self.current_index = self.left_c_index
                        self.left_c_index,self.right_c_index = self._get_children_index(self.current_index)
                        self._swap_pop()
                    else:
                        self.min_heap[self.current_index],self.min_heap[self.right_c_index]=self.min_heap[self.right_c_index],self.min_heap[self.current_index]
                        self.current_index = self.right_c_index
                        self.left_c_index,self.right_c_index = self._get_children_index(self.current_index)
                        self._swap_pop()
            
    def push(self,num):
        self.min_heap.append(num)
        #may be able to improve this part of the code
        if len(self.min_heap)>0:
            self.current_index = len(self.min_heap)-1
            self.parent_index = self._get_parent_index(self.current_index)
            if num<self.min_heap[self.parent_index]:
                self._swap()
    def pop(self):
        self.min_heap[0],self.min_heap[-1] = self.min_heap[-1],self.min_heap[0]
        self.min_heap.pop()
        self.current_index = 0
        
        self.left_c_index,self.right_c_index = self._get_children_index(self.current_index)

        self._swap_pop()
import numpy as np
class Heap_Max:
    def __init__(self):
        self.max_heap = []
    
    def _get_parent_index(self,current_index):
        return int(np.ceil( current_index/2.0 ))-1
    
    
    def _get_children_index(self,current_index):
        size = len(self.max_heap)
        potential_left_index = (current_index+1)*2-1
        if potential_left_index >size-1:
            left_c_index = None
            right_c_index = None
            
        else:
            left_c_index = potential_left_index
            if potential_left_index+1<=size-1:
                right_c_index = potential_left_index+1
            else:
                right_c_index = None
                
            
        return (left_c_index,right_c_index)
            
           
    
    def _swap(self):
        self.max_heap[self.current_index],self.max_heap[self.parent_index]=self.max_heap[self.parent_index],self.max_heap[self.current_index]    
        
        self.current_index=self.parent_index
        self.parent_index = self._get_parent_index(self.current_index)
    
        if (self.parent_index>=0) and (self.max_heap[self.current_index]>self.max_heap[self.parent_index]):
            self._swap()
            
    def _swap_pop(self):

        if self.left_c_index!=None:
            if self.right_c_index==None:
                if self.max_heap[self.current_index]<self.max_heap[self.left_c_index]:
                    self.max_heap[self.current_index],self.max_heap[self.left_c_index] = self.max_heap[self.left_c_index], self.max_heap[self.current_index]
            else:
                if self.max_heap[self.current_index]<self.max_heap[self.left_c_index] or self.max_heap[self.current_index]<self.max_heap[self.right_c_index]:  
                    if self.max_heap[self.left_c_index]>=self.max_heap[self.right_c_index]:
                        
                        
                        self.max_heap[self.current_index],self.max_heap[self.left_c_index]=self.max_heap[self.left_c_index],self.max_heap[self.current_index]
                        self.current_index = self.left_c_index
                        self.left_c_index,self.right_c_index = self._get_children_index(self.current_index)
                        self._swap_pop()
                    else:
                        self.max_heap[self.current_index],self.max_heap[self.right_c_index]=self.max_heap[self.right_c_index],self.max_heap[self.current_index]
                        self.current_index = self.right_c_index
                        self.left_c_index,self.right_c_index = self._get_children_index(self.current_index)
                        self._swap_pop()
            
    def push(self,num):
        self.max_heap.append(num)
        if len(self.max_heap)>0:
            self.current_index = len(self.max_heap)-1
            self.parent_index = self._get_parent_index(self.current_index)
            if num>self.max_heap[self.parent_index]:
                self._swap()
    def pop(self):
        self.max_heap[0],self.max_heap[-1] = self.max_heap[-1],self.max_heap[0]
        self.max_heap.pop()
        self.current_index = 0
        
        self.left_c_index,self.right_c_index = self._get_children_index(self.current_index)

        self._swap_pop()
a = []
n=10
heap_min =Heap_Min()
heap_max =Heap_Max()
current_median = 0


for _ in range(n):
    a_item = int(input())
    a.append(a_item)
    if len(a)==1:
        heap_min.push(a_item)
        current_median = a_item
        print(current_median*1.0)
    else:
        if a_item<current_median:
            heap_max.push(a_item)
        else:
            heap_min.push(a_item)
        if len(heap_min.min_heap)>len(heap_max.max_heap)+1:
            tmp = heap_min.min_heap[0]
            heap_min.pop()
            heap_max.push(tmp)
        if len(heap_max.max_heap)>len(heap_min.min_heap)+1:
            tmp = heap_max.max_heap[0]
            heap_max.pop()
            heap_min.push(tmp)
        
            
        print(heap_min.min_heap)
        print(heap_max.max_heap)
            
        if len(heap_min.min_heap) == len(heap_max.max_heap):
            current_median =  (heap_min.min_heap[0]+heap_max.max_heap[0])/2.0
            print(current_median)
        else:
            if len(heap_min.min_heap)>len(heap_max.max_heap):
                current_median = heap_min.min_heap[0]*1.0
                print(current_median)
            else:
                current_median = heap_max.max_heap[0]*1.0
                print(current_median)

