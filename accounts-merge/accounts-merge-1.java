class Solution {
    
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        List<List<String>> result = new ArrayList<>();
        Map<Integer, Set<String>> temp = new HashMap<>();
        Map<Integer, String> tempName = new HashMap<>();

        DSU dsu = new DSU(1000);
        Map<String, String> emailToName = new HashMap<>();
        Map<String, Integer> emailToId = new HashMap<>();

        for (int i = 0; i < accounts.size(); i++) {
            String name = accounts.get(i).get(0);
            for (int j = 1; j < accounts.get(i).size(); j++) {
                String email = accounts.get(i).get(j);
                emailToName.put(email, name);

                if (emailToId.containsKey(email)) {
                    dsu.unionSet(emailToId.get(email), i);
                } else {
                    emailToId.put(email, i);
                }
            }
        }

        for (int i = 0; i < accounts.size(); i++) {
            String name = accounts.get(i).get(0);

            int p = dsu.find(i);
            Set<String> s;
            if (!temp.containsKey(p)) {
                s = new HashSet<String>();
                tempName.put(p, name);
            } else {
                s = temp.get(p);
            }
            
            for (int j = 1; j < accounts.get(i).size(); j++) {
                String email = accounts.get(i).get(j);
                if (s.contains(email)) {
                    continue;
                }
                s.add(email);
            }

            temp.put(p, s);
        }

        for (Integer k : temp.keySet()) {
            List<String> l = new ArrayList<>();
            l.add(tempName.get(k));

            Set<String> s = temp.get(k);
            s.forEach(item -> {
                l.add(item);
            });
            Collections.sort(l);
            result.add(l);
        }
        
        return result;
    }
}

class DSU {

    private int[] set;

    public DSU(int size) {
        set = new int[size];
        for (int i = 0; i < size; i++) {
            set[i] = i;
        }
    }

    public void make(int element, int parent) {
        set[element] = parent;
    }

    public void unionSet(int elementA, int elementB) {
        int p1 = find(elementA);
        int p2 = find(elementB);

        // compress
        set[elementA] = p2;
        set[elementB] = p2;

        set[p1] = p2;
    }

    public int find(int element) {
        while (set[element] != element) {
            element = set[element];
        }
        return set[element];
    }
} 