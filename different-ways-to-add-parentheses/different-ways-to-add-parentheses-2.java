class Solution {

    private HashMap<String, List<Integer>> map = new HashMap<>();

    public List<Integer> diffWaysToCompute(String input) {
        if (input.length() == 0) {
            return new ArrayList<>();
        }

        if (map.containsKey(input)) {
            return map.get(input);
        }

        List<Integer> result = new ArrayList<>();

        int nums = 0;
        int index;
        for (index = 0; index < input.length() && !isOperator(input.charAt(index)); index++) {
            nums = 10 * nums + (input.charAt(index) - '0');
        }

        if (index == input.length()) {
            result.add(nums);
            return result;
        }

        for (index = 0; index < input.length(); index++) {
            if (isOperator(input.charAt(index))) {
                char op = input.charAt(index);
                List<Integer> result1 = diffWaysToCompute(input.substring(0, index));
                List<Integer> result2 = diffWaysToCompute(input.substring(index + 1, input.length()));
                for (int i = 0; i < result1.size(); i++) {
                    for (int j = 0; j < result2.size(); j++) {
                        int temp = caculate(result1.get(i), op, result2.get(j));
                        result.add(temp);
                    }
                }
            }
        }

        map.put(input, result);
        return result;
    }

    private int caculate(int num1, char op, int num2) {
        int result = 0;
        if (op == '-') {
            result = num1 - num2;
        } else if (op == '+') {
            result = num1 + num2;
        } else if (op == '*') {
            result = num1 * num2;
        }

        return result;
    }

    private boolean isOperator(char c) {
        if (c == '-' || c == '+' || c == '*') {
            return true;
        }
        return false;
    }
}