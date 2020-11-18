class Solution {
    final int MAX_VISIT = 20000;
 
    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        Set<String> blockedSet = new HashSet<>();
        for (int[] point : blocked) {
            blockedSet.add(getKey(point));
        }
        return canVisit(blockedSet, source, getKey(target)) && canVisit(blockedSet, target, getKey(source));
    }
    
    String getKey(int[] point) {
        return point[0] + "," + point[1];
    }
    
    boolean canVisit(Set<String> blocked, int[] source, String targetKey) {
        Set<String> visited = new HashSet<>();
        dfs(blocked, source, targetKey, visited);
        return visited.size() >= MAX_VISIT || visited.contains(targetKey);
    }
    
    void dfs(Set<String> blocked, int[] curr, String targetKey, Set<String> visited) {
        int i = curr[0], j = curr[1];
        if (i < 0 || j < 0 || i >= 1e6 || j >= 1e6) { return; }
        
        String key = getKey(curr);
        if (blocked.contains(key)) { return; }
        if (visited.size() >= MAX_VISIT || visited.contains(targetKey)) { return; }
        
        if (visited.contains(key)) { return; }
        visited.add(key);
        
        for (int[] next : new int[][] {{i-1 ,j}, {i+1, j}, {i, j-1}, {i, j+1}}) {
            dfs(blocked, next, targetKey, visited);
        }
    }
}