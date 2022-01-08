import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {

    public int solution(int[][] jobs) {

        Arrays.sort(jobs, (o1, o2) -> {
            if (o1[0] != o2[0]) return Integer.compare(o1[0], o2[0]);
            else return Integer.compare(o1[1], o2[1]);
        });

        var pq = new PriorityQueue<int[]>((o1, o2) -> {
            if (o1[1] != o2[1]) return Integer.compare(o1[1], o2[1]);
            else return Integer.compare(o1[0], o2[0]);
        });

        var total = 0;
        var curEndTime = 0;
        var idx = 0;
        
        while (idx < jobs.length) {
            pq.add(jobs[idx++]);
            
            while (!pq.isEmpty()) {
                var curJob = pq.poll();
                
                curEndTime = Math.max(curEndTime, curJob[0]) + curJob[1];
                total += curEndTime - curJob[0];
                
                while (idx < jobs.length && curEndTime >= jobs[idx][0]) {
                    pq.add(jobs[idx++]);
                }
            }
        }
        
        return total / jobs.length;
    }
}
