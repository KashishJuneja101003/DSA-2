import java.util.*;

class SocialNetwork {
    // Adjacency list representation for the graph
    private Map<Integer, Set<Integer>> friends;

    public SocialNetwork() {
        this.friends = new HashMap<>();
    }

    // Add a new user
    public void addUser(int userId) {
        friends.putIfAbsent(userId, new HashSet<>());
        System.out.println("User " + userId + " added.");
    }

    // Add a friendship between two users
    public void addFriendship(int user1, int user2) {
        if (!friends.containsKey(user1) || !friends.containsKey(user2)) {
            System.out.println("One or both users do not exist.");
            return;
        }
        if (friends.get(user1).contains(user2)) {
            System.out.println("Friendship already exists between " + user1 + " and " + user2 + ".");
            return;
        }
        friends.get(user1).add(user2);
        friends.get(user2).add(user1);
        System.out.println("Friendship established between " + user1 + " and " + user2 + ".");
    }

    // View all friends of a user
    public void viewFriends(int userId) {
        if (!friends.containsKey(userId)) {
            System.out.println("User " + userId + " does not exist.");
            return;
        }
        System.out.print("Friends of " + userId + ": ");
        for (int friendId : friends.get(userId)) {
            System.out.print(friendId + " ");
        }
        System.out.println();
    }

    // Recommend friends for a given user
    public List<Integer> getFriendRecommendations(int userId) {
        if (!friends.containsKey(userId)) {
            System.out.println("User " + userId + " does not exist.");
            return new ArrayList<>();
        }

        Map<Integer, Integer> mutualCount = new HashMap<>(); // To count mutual friends

        // Loop through direct friends
        for (int friendId : friends.get(userId)) {
            // Loop through friends of friends
            for (int potentialFriend : friends.get(friendId)) {
                if (potentialFriend != userId && !friends.get(userId).contains(potentialFriend)) {
                    mutualCount.put(potentialFriend, mutualCount.getOrDefault(potentialFriend, 0) + 1);
                }
            }
        }

        // Create a list of recommendations sorted by the number of mutual friends
        List<Map.Entry<Integer, Integer>> recommendations = new ArrayList<>(mutualCount.entrySet());
        
        // Sort by mutual friends (higher count first), break ties by user ID (lower ID first)
        recommendations.sort((a, b) -> a.getValue().equals(b.getValue()) ? Integer.compare(a.getKey(), b.getKey()) : Integer.compare(b.getValue(), a.getValue()));
        
        // Extract only the user IDs
        List<Integer> result = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : recommendations) {
            result.add(entry.getKey());
        }

        return result;
    }

    public static void main(String[] args) {
        SocialNetwork sn = new SocialNetwork();

        sn.addUser(1);
        sn.addUser(2);
        sn.addUser(3);
        sn.addUser(4);
        sn.addUser(5);

        sn.addFriendship(1, 2);
        sn.addFriendship(2, 3);
        sn.addFriendship(3, 4);
        sn.addFriendship(4, 5);

        System.out.print("\nFriend Recommendations for 1: ");
        List<Integer> recommendations = sn.getFriendRecommendations(1);
        for (int user : recommendations) {
            System.out.print(user + " ");
        }
        System.out.println();

        sn.viewFriends(1);
        sn.viewFriends(3);
    }
}
