import java.util.*;

public class SonamKumari29_SocialNetworkFriendRecommendation {
    private Map<Integer, Set<Integer>> networkMap;

    public SonamKumari29_SocialNetworkFriendRecommendation() {
        this.networkMap = new HashMap<>();
    }

    // Add a new user to the network
    public void addUser(int userId) {
        if (!networkMap.containsKey(userId)) {
            networkMap.put(userId, new HashSet<>());
            System.out.println("User " + userId + " has been added.");
        } else {
            System.out.println("User " + userId + " already exists.");
        }
    }

    // Establish a friendship between two users
    public void addFriendship(int userId1, int userId2) {
        if (networkMap.containsKey(userId1) && networkMap.containsKey(userId2)) {
            networkMap.get(userId1).add(userId2);
            networkMap.get(userId2).add(userId1);
            System.out.println("Friendship established between " + userId1 + " and " + userId2 + ".");
        } else {
            System.out.println("Both users must be registered before creating a friendship.");
        }
    }

    // Generate friend recommendations based on mutual friends
    public void recommendFriends(int userId) {
        if (!networkMap.containsKey(userId)) {
            System.out.println("User not found.");
            return;
        }
        
        Set<Integer> directFriends = networkMap.get(userId);
        Map<Integer, Integer> mutualFriendCounts = new HashMap<>();
        
        // Identify mutual friends (friends of friends who are not already direct friends)
        for (int friend : directFriends) {
            for (int potentialFriend : networkMap.get(friend)) {
                if (potentialFriend != userId && !directFriends.contains(potentialFriend)) {
                    mutualFriendCounts.put(potentialFriend, mutualFriendCounts.getOrDefault(potentialFriend, 0) + 1);
                }
            }
        }
        
        List<Integer> recommendations = new ArrayList<>(mutualFriendCounts.keySet());
        recommendations.sort((a, b) -> mutualFriendCounts.get(b) - mutualFriendCounts.get(a));
        
        System.out.println("Friend recommendations for " + userId + ": " + recommendations);
    }

    // Show a user's direct friends
    public void displayFriends(int userId) {
        if (!networkMap.containsKey(userId)) {
            System.out.println("User not found.");
            return;
        }
        System.out.println("Friends of " + userId + ": " + networkMap.get(userId));
    }

    public static void main(String[] args) {
        SonamKumari29_SocialNetworkFriendRecommendation network = new SonamKumari29_SocialNetworkFriendRecommendation();
        
        // Register users
        network.addUser(1);
        network.addUser(2);
        network.addUser(3);
        
        // Create friendships
        network.addFriendship(1, 2);
        network.addFriendship(2, 3);
        
        // Recommend friends for user 1
        network.recommendFriends(1);
        
        // Display direct friends of user 1
        network.displayFriends(1);
    }
}
