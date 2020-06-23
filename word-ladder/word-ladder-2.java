class Solution {

    private int L;
    private Map<String, List<String>> allComboDict;

    private Integer visitWordNode(
        Queue<Pair<String, Integer>> Q, 
        Map<String, Integer> visited,
        Map<String, Integer> othersVisited) {
     
        Pair<String, Integer> node = Q.remove();
        String word = node.getKey();
        int level = node.getValue();
        for (int i = 0; i < L; i++) {
            String newWord = word.substring(0, i) + "*" + word.substring(i + 1, L);
            for (String adjacentWord : allComboDict.getOrDefault(newWord, new ArrayList<>())) {
                if (othersVisited.containsKey(adjacentWord)) {
                    return level + othersVisited.get(adjacentWord);
                }
                if (!visited.containsKey(adjacentWord)) {
                    visited.put(adjacentWord, level + 1);
                    Q.add(new Pair<>(adjacentWord, level + 1));
                }
            }
        }
        
        return -1;
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        if (!wordList.contains(endWord)) {
            return 0;
        }
        
        L = beginWord.length();
        allComboDict = new HashMap<>();

        wordList.forEach(
            word -> {
                for (int i = 0; i < L; i++) {
                    String newWord = word.substring(0, i) + "*" + word.substring(i + 1, L);
                    List<String> transformations = allComboDict.getOrDefault(newWord, new ArrayList<>());
                    transformations.add(word);
                    allComboDict.put(newWord, transformations);
                }
            }
        );

        Queue<Pair<String, Integer>> Q_begin = new LinkedList<>();
        Q_begin.add(new Pair<>(beginWord, 1));

        Map<String, Integer> visitedBegin = new HashMap<>();
        visitedBegin.put(beginWord, 1);

        Queue<Pair<String, Integer>> Q_end = new LinkedList<>();
        Q_end.add(new Pair<>(endWord, 1));

        Map<String, Integer> visitedEnd = new HashMap<>();
        visitedEnd.put(endWord, 1);

        while (!Q_begin.isEmpty() && !Q_end.isEmpty()) {
            int ans = -1;

            ans = visitWordNode(Q_begin, visitedBegin, visitedEnd);
            if (ans > 0) {
                return ans;
            }

            ans = visitWordNode(Q_end, visitedEnd, visitedBegin);
            if (ans > 0) {
                return ans;
            }
        }

        return 0;

    }
}