import java.util.*;

public class StatArray implements Statistician{
    private int count;
    private int size;
    private int[] items;

    public StatArray() {
        Statistician();
    }

    public void setCount(int count) {
        this.count = count;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public int[] getItems() {
        return items;
    }

    public void setItems(int[] items) {
        this.items = items;
    }

    public void Statistician() {
        items = new int[10];
        setCount(0);
        setSize(10);
    }

    public void doubleTheSize(){
//        int min=2;
//        int[] temp = new int[count*min];
//        for(int i=0;i<count;i++){
//            temp[i] = items[i];
//        }
//        items = temp;
//        count*=min;
        int[] temp = null;
        if(count==size){
            temp = new int[size*2];
            for(int i=0;i<size;i++){
                temp[i] = items[i];
            }
        }
        items =  temp;
        setSize(size*2);
    }

    public void addLast(int elem) {
        if(getCount()==getSize())
            doubleTheSize();
        if(getCount() < getSize()){
            items[count++] = elem;
        }
    }

    public void add(int elem) {
        int i;
        int p=-1;
        if(getCount()==getSize())
            doubleTheSize();
        if(getCount() < getSize()){
            //did not used binary search since there is a chance that it would return the mid
            //of num. who has a lot of frequency.
            for(i=0;i<getCount();i++){
                if(elem<items[i]){
                    p=i;
                    break;
                }
            }
            if(p!=-1){
                for(i=getCount();i>p;i--){
                    items[i] = items[i-1];
                }
                items[p] = elem;
                count++;
            } else{
                items[count++] = elem;
            }
        }
    }

    public void clear() {
        items=null;
        setCount(0);
    }

    public boolean isEmpty() {
        return getCount()==0;
    }

    public boolean contains(int elem) {
        return binarySearch(elem,0,count-1) !=-1;
    }

    public int frequency(int elem) {
        int freq=0;
        for(int i=0;i<getCount();i++){
            if(items[i]==elem)
                freq++;
        }
        return freq;
    }

    public int getCount() {
        return count;
    }

    public int findMin() {
        return items[0];
    }

    public int findMax() {
        return items[getCount()-1];
    }

    public int findRange() {
        return findMax()-findMin();
    }

    public float findMedian() {
        if(getCount()%2!=0)
            return items[getCount()/2];
        else
            return ((items[getCount()/2] + items[getCount()/2 -1]) /2.0f);
    }

    public int findSum() {
        int sum=0;
        for(int i=0;i<getCount();i++){
            sum+=items[i];
        }
        return sum;
    }

    public float findMean() {
        return (float)findSum()/getCount();
    }

    public float findStandardDeviation() {
        int i;
        float up = 0;
        float mean = findMean();
        for(i=0;i<getCount();i++){
            up += Math.pow(((float)items[i] - mean), 2);
        }
        return (float)Math.sqrt(up/(getCount()-1));
    }

    public void removeFirst(int x) {
        int pos = binarySearch(x,0,getCount()-1);
        if(pos!=-1){
            for(int i=pos;i<getCount()-1;i++){
                items[i] = items[i+1];
            }
            count--;
        }
    }

    public void removeAll(int x) {
        int i;
        int p = binarySearch(x,0,getCount()-1);
        while(p != -1){
            for(i = p; i < getCount()-1 ; i++){
                items[i] = items[i+1];
            }
            count--;
            p = binarySearch(x,0,getCount()-1);
        }
    }

    int binarySearch(int x, int first, int last){
        int mid;
        if(first<=last){
            mid = (first+last)/2;
            if(x==items[mid])
                return  mid;
            else
            if (x<items[mid])
                return binarySearch(x,first,mid-1);
            else
                return binarySearch(x,mid+1,last);
        } else
            return -1;
    }


    public String toString() {
        String str="s = [ ";
        for(int i=0; i< count; i++)
            str += items[i] + " ";
        str+="]";
        return str;
    }
}
