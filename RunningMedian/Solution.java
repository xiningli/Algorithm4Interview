import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.util.ArrayList;

public class Solution {

    public class MinHeap {

        private ArrayList<Integer> min_heap;
        private int current_index;
        private int parent_index;
        private int left_c_index;
        private int right_c_index;

        public MinHeap() {
            this.min_heap = new ArrayList<Integer>();
            this.current_index =-99;
            this.parent_index=-99;
            this.left_c_index=-99;
            this.right_c_index=-99;
        }

        private void updateParentIndex (int current_index){
            int tmp=((current_index / 2 + ((current_index % 2 == 0) ? 0 : 1))-1);
            if (tmp==-1){
                this.parent_index= 0;
            }else{
                this.parent_index= tmp;//Here we assume the parent of root is the root itself. 
            }
        }

        private void updateChildrenIndex(int current_index){
            int size = this.min_heap.size();
            int potential_left_index = (current_index+1)*2-1;
            if (potential_left_index > size-1){
                this.left_c_index=-99;
                this.right_c_index=-99;
            }else{
                this.left_c_index = potential_left_index;
                if (potential_left_index+1<=size-1){
                    this.right_c_index = potential_left_index+1;
                }else{
                    this.right_c_index=-99;
                }
            }
        }
        private void swap_insert(){

            //swaping
            int tmp = this.min_heap.get(this.current_index);
            int parent_tmp = this.min_heap.get(this.parent_index);
            this.min_heap.set(this.current_index, parent_tmp) ; 
            this.min_heap.set(this.parent_index, tmp) ;

            this.current_index=this.parent_index;


            this.updateParentIndex(this.current_index);
            if (this.parent_index>=0 && this.min_heap.get(this.current_index) < this.min_heap.get(this.parent_index)) {
                this.swap_insert();
            }
        }

        private void swap_pop(){
            if (this.left_c_index!=-99){
                if (this.right_c_index==-99){
                    if (this.min_heap.get(this.current_index)>this.min_heap.get(this.left_c_index)){
                        int tmp = this.min_heap.get(this.current_index);
                        int left_tmp = this.min_heap.get(this.left_c_index);
                        this.min_heap.set(this.current_index, left_tmp) ; 
                        this.min_heap.set(this.left_c_index, tmp) ;//swaping
                    }
                }else{
                    if(this.min_heap.get(this.current_index)>this.min_heap.get(this.left_c_index) || this.min_heap.get(this.current_index)>this.min_heap.get(this.right_c_index) ){
                        if (this.min_heap.get(this.left_c_index)<=this.min_heap.get(this.right_c_index)){
                            int tmp = this.min_heap.get(this.current_index);
                            int left_tmp = this.min_heap.get(this.left_c_index);
                            this.min_heap.set(this.current_index, left_tmp) ; 
                            this.min_heap.set(this.left_c_index, tmp) ;//swaping
                            this.current_index = this.left_c_index;
                            this.updateChildrenIndex(this.current_index);
                            this.swap_pop();
                        }else{
                            int tmp = this.min_heap.get(this.current_index);
                            int right_tmp = this.min_heap.get(this.right_c_index);
                            this.min_heap.set(this.current_index, right_tmp) ; 
                            this.min_heap.set(this.right_c_index, tmp) ;//swaping
                            this.current_index = this.right_c_index;
                            this.updateChildrenIndex(this.current_index);
                            this.swap_pop();
                        }
                    }
                }
            }
        }

        public void push(int num){
            this.min_heap.add(num);
            this.current_index = this.min_heap.size()-1;
            this.updateParentIndex(this.current_index);
            if (num<this.min_heap.get(this.parent_index)){
                this.swap_insert();
            }	
        }

        public void pop(){
            int last_ele = this.min_heap.get(this.min_heap.size()-1);
            this.min_heap.set(0, last_ele) ; 
            this.min_heap.remove(this.min_heap.size()-1) ;
            this.current_index=0;
            this.updateChildrenIndex(this.current_index);
            this.swap_pop();
        }

        public void printHeap(){
            System.out.println(this.min_heap);
        }

        public int getMin(){
            return this.min_heap.get(0);
        }

    }

    public class MaxHeap {

        private ArrayList<Integer> max_heap;
        private int current_index;
        private int parent_index;
        private int left_c_index;
        private int right_c_index;

        public MaxHeap() {
            this.max_heap = new ArrayList<Integer>();
            this.current_index =-99;
            this.parent_index=-99;
            this.left_c_index=-99;
            this.right_c_index=-99;
        }

        private void updateParentIndex (int current_index){
            int tmp=((current_index / 2 + ((current_index % 2 == 0) ? 0 : 1))-1);
            if (tmp==-1){
                this.parent_index= 0;
            }else{
                this.parent_index= tmp;//Here we assume the parent of root is the root itself. 
            }
        }

        private void updateChildrenIndex(int current_index){
            int size = this.max_heap.size();
            int potential_left_index = (current_index+1)*2-1;
            if (potential_left_index > size-1){
                this.left_c_index=-99;
                this.right_c_index=-99;
            }else{
                this.left_c_index = potential_left_index;
                if (potential_left_index+1<=size-1){
                    this.right_c_index = potential_left_index+1;
                }else{
                    this.right_c_index=-99;
                }
            }
        }
        private void swap_insert(){

            //swaping
            int tmp = this.max_heap.get(this.current_index);
            int parent_tmp = this.max_heap.get(this.parent_index);
            this.max_heap.set(this.current_index, parent_tmp) ; 
            this.max_heap.set(this.parent_index, tmp) ;

            this.current_index=this.parent_index;


            this.updateParentIndex(this.current_index);
            if (this.parent_index>=0 && this.max_heap.get(this.current_index) > this.max_heap.get(this.parent_index)) {
                this.swap_insert();
            }
        }

        private void swap_pop(){
            if (this.left_c_index!=-99){
                if (this.right_c_index==-99){
                    if (this.max_heap.get(this.current_index)<this.max_heap.get(this.left_c_index)){
                        int tmp = this.max_heap.get(this.current_index);
                        int left_tmp = this.max_heap.get(this.left_c_index);
                        this.max_heap.set(this.current_index, left_tmp) ; 
                        this.max_heap.set(this.left_c_index, tmp) ;//swaping
                    }
                }else{
                    if(this.max_heap.get(this.current_index)<this.max_heap.get(this.left_c_index) || this.max_heap.get(this.current_index)<this.max_heap.get(this.right_c_index) ){
                        if (this.max_heap.get(this.left_c_index)>=this.max_heap.get(this.right_c_index)){
                            int tmp = this.max_heap.get(this.current_index);
                            int left_tmp = this.max_heap.get(this.left_c_index);
                            this.max_heap.set(this.current_index, left_tmp) ; 
                            this.max_heap.set(this.left_c_index, tmp) ;//swaping
                            this.current_index = this.left_c_index;
                            this.updateChildrenIndex(this.current_index);
                            this.swap_pop();
                        }else{
                            int tmp = this.max_heap.get(this.current_index);
                            int right_tmp = this.max_heap.get(this.right_c_index);
                            this.max_heap.set(this.current_index, right_tmp) ; 
                            this.max_heap.set(this.right_c_index, tmp) ;//swaping
                            this.current_index = this.right_c_index;
                            this.updateChildrenIndex(this.current_index);
                            this.swap_pop();
                        }
                    }
                }
            }
        }

        public void push(int num){
            this.max_heap.add(num);
            this.current_index = this.max_heap.size()-1;
            this.updateParentIndex(this.current_index);
            if (num>this.max_heap.get(this.parent_index)){
                this.swap_insert();
            }	
        }

        public void pop(){
            int last_ele = this.max_heap.get(this.max_heap.size()-1);
            this.max_heap.set(0, last_ele) ; 
            this.max_heap.remove(this.max_heap.size()-1) ;
            this.current_index=0;
            this.updateChildrenIndex(this.current_index);
            this.swap_pop();
        }

        public void printHeap(){
            System.out.println(this.max_heap);
        }

        public int getMax(){
            return this.max_heap.get(0);
        }

    }    
    

    
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        Solution outerClass = new Solution();
        Solution.MinHeap min_heap_obj = outerClass.new MinHeap();
        Solution.MaxHeap max_heap_obj = outerClass.new MaxHeap();

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] a = new int[n];
        float current_median=0;

        
        for (int i = 0; i < n; i++) {
            int aItem = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
            a[i] = aItem;
            
            if (i==0){
                min_heap_obj.push(aItem);
                current_median = aItem;
                System.out.println(current_median*1.0);
            }else{
                if(aItem<current_median){
                    max_heap_obj.push(aItem);
                }else{
                    min_heap_obj.push(aItem);
                }
                if (min_heap_obj.min_heap.size()>(max_heap_obj.max_heap.size()+1)){
                    int tmp=min_heap_obj.getMin();
                    min_heap_obj.pop();
                    max_heap_obj.push(tmp);
                }
                if (max_heap_obj.max_heap.size()>(min_heap_obj.min_heap.size()+1)){
                    int tmp=max_heap_obj.getMax();
                    max_heap_obj.pop();
                    min_heap_obj.push(tmp);
                }
                
                
                if (min_heap_obj.min_heap.size()==max_heap_obj.max_heap.size()){
                    float total = min_heap_obj.getMin()+max_heap_obj.getMax();
                    current_median = total/2;
                    System.out.println(current_median);
                }else{
                    if(min_heap_obj.min_heap.size()>max_heap_obj.max_heap.size()){
                        current_median = (float) min_heap_obj.getMin();
                        System.out.println(current_median);
                        
                    }else{
                        current_median = (float) max_heap_obj.getMax();
                        System.out.println(current_median);
                    }
                }
                
                
            }
        }

        scanner.close();
    }
}
