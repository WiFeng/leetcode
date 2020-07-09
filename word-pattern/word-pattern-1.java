class Solution {
    public boolean wordPattern(String pattern, String str) {
        
        String[] stringList = str.split(" ");

        if (pattern.length() != stringList.length) {
            return false;
        }

        ArrayList<String> stringUnique = new ArrayList<>();
        Map<String, ArrayList<Integer>> stringMap = new HashMap<>();

        ArrayList<Character> patternUnique = new ArrayList<>();
        Map<Character, ArrayList<Integer>> patternMap = new HashMap<>();

        for (int i = 0; i < stringList.length; i++) {
            if (!stringMap.containsKey(stringList[i])) {
                stringUnique.add(stringList[i]);
            }
            ArrayList<Integer> strIndexList = stringMap.getOrDefault(stringList[i], new ArrayList<>());
            strIndexList.add(i);
            stringMap.put(stringList[i], strIndexList);

            if (!patternMap.containsKey(pattern.charAt(i))) {
                patternUnique.add(pattern.charAt(i));
            }
            ArrayList<Integer> patIndexList = patternMap.getOrDefault(pattern.charAt(i), new ArrayList<>());
            patIndexList.add(i);
            patternMap.put(pattern.charAt(i), patIndexList);
        }

        for (int i = 0; i < stringUnique.size(); i++) {
            ArrayList<Integer> strIndexList = stringMap.get(stringUnique.get(i));
            ArrayList<Integer> patIndexList = patternMap.get(patternUnique.get(i));
            if (!strIndexList.equals(patIndexList)) {
                return false;
            }
        }

        return true;
    }
}