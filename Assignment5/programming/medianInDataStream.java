
import java.util.Collections;
import java.util.PriorityQueue;


class MedianInDataStream{

    PriorityQueue<Integer> minHeap; // for greater half
    PriorityQueue<Integer> maxHeap; // for smaller half

    public MedianInDataStream() {
        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
    }

    public void insert(int num) {
        maxHeap.offer(num);

        minHeap.offer(maxHeap.poll());

        if(maxHeap.size() < minHeap.size()){
            maxHeap.offer(minHeap.poll());
        }
    }

    public double getMedian() {
        double median;

        if(minHeap.size() == maxHeap.size()){
            median = (minHeap.peek() + maxHeap.peek()) / (double)2;
        }else{
            median = minHeap.size() > maxHeap.size() ? minHeap.peek() : maxHeap.peek();
        }
        return median;
    }

    public static void main(String[] args) {

        MedianInDataStream m = new MedianInDataStream();

        m.insert(1);
        assert m.getMedian() == 1.0;

        m.insert(2);
        assert m.getMedian() == 1.5;

        m.insert(3);
        assert m.getMedian() == 2.0;

        m.insert(4);
        assert m.getMedian() == 2.5;

        m.insert(5);
        assert m.getMedian() == 3.0;

        System.out.println("All tests passed!");
    }
}