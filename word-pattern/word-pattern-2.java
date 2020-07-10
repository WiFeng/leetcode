class Solution {
    public boolean wordPattern(String pattern, String str) {
        
        String[] stringList = str.split(" ");
        if (pattern.length() != stringList.length) {
            return false;
        }

        Map<Character, String> patternMap = new HashMap<>();
        Map<String, Character> stringMap = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            Character key = pattern.charAt(i);
            if (!patternMap.containsKey(key)) {
                if (stringMap.containsKey(stringList[i])) {
                    return false;
                }
                patternMap.put(key, stringList[i]);
                stringMap.put(stringList[i], key);
                continue;
            }

            if (!patternMap.get(key).equals(stringList[i])) {
                return false;
            }
        }

        return true;
    }
}