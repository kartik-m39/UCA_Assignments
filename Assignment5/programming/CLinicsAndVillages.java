
import java.util.PriorityQueue;

class Triplet{
    int population;
    double load;
    int clinics;

    Triplet(int population, double load, int clinics){
        this.population = population;
        this.load= load;
        this.clinics = clinics;
    }
}

class ClinicsAndVillages{

    PriorityQueue<Triplet> pq;

    public double minimiseMaxLoad(int[] arr, int k){

        pq = new PriorityQueue<>((a,b) -> Double.compare(b.load, a.load));  // max-Heap

        for(int i : arr){
            pq.offer(new Triplet(i, i, 1));
            k--;
        }

        while(k > 0){
            Triplet data = pq.poll();

            double newLoad = data.population / (double)(data.clinics + 1);
            // System.out.println(newLoad);
            pq.offer(new Triplet(data.population, newLoad, data.clinics+1));

            k--;
        }

        return pq.peek().load;
    }


    public static void main(String[] args) {
        
        ClinicsAndVillages obj = new ClinicsAndVillages();

        double ans = obj.minimiseMaxLoad(new int[]{200, 20, 50}, 5);

        System.out.printf("%.2f%n",ans);
    }
}