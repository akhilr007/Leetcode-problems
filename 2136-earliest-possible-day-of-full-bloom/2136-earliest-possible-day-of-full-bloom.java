class Solution {
    private class Plant{
        int plantTime;
        int growTime;
        
        Plant(int plantTime, int growTime){
            this.plantTime = plantTime;
            this.growTime = growTime;
        }
    }
    
    public int earliestFullBloom(int[] plantTime, int[] growTime) {
        
        List<Plant> plant = new ArrayList<>();
        for(int i=0; i<plantTime.length; i++){
            plant.add(new Plant(plantTime[i], growTime[i]));
        }
        
        Collections.sort(plant, (a, b) -> (b.growTime - a.growTime));
        
        int time=0;
        int max=0;
        
        for(int i=0; i<plant.size(); i++){
            time += plant.get(i).plantTime;
            max = Math.max(max, time + plant.get(i).growTime);
        }
        
        return max;
    }
}