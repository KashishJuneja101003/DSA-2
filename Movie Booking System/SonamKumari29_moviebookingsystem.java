import java.util.*;
public class SonamKumari29_moviebookingsystem {
    private static class Movie {
        String name;
        String showtime;
        int seats;

        Movie(String name, String showtime, int seats) {
            this.name = name;
            this.showtime = showtime;
            this.seats = seats;
        }
    }
    // HashMap to store movies by their name
    private Map<String, Movie> movies = new HashMap<>();

    // Method to add a new movie
    public void addMovie(String name, String showtime, int seats) {
        movies.put(name, new Movie(name, showtime, seats));
        System.out.println("Movie added successfully.");
    }

    // Method to book a ticket for a specific movie
    public void bookTicket(String name) {
        Movie movie = movies.get(name);
        if (movie != null && movie.seats > 0) {
            movie.seats--;
            System.out.println("Booking confirmed. Seats Left: " + movie.seats);
        } else {
            System.out.println("Booking failed. No seats available.");
        }
    }

    // Method to cancel a ticket for a specific movie
    public void cancelTicket(String name) {
        Movie movie = movies.get(name);
        if (movie != null && movie.seats < 50) { // Assuming max capacity is 50
            movie.seats++;
            System.out.println("Ticket canceled. Seats Left: " + movie.seats);
        } else {
            System.out.println("Cancellation failed. No tickets to cancel.");
        }
    }

    // Method to display all available shows
    public void viewAvailableShows() {
        if (movies.isEmpty()) {
            System.out.println("No shows available.");
        } else {
            for (Movie movie : movies.values()) {
                System.out.println(movie.name + " - Showtime: " + movie.showtime + " - Seats Left: " + movie.seats);
            }
        }
    }

    // Method to search for a movie by its name
    public void searchMovie(String name) {
        Movie movie = movies.get(name);
        if (movie != null) {
            System.out.println("Movie Found: " + movie.name + " - Showtime: " + movie.showtime + " - Seats Left: " + movie.seats);
        } else {
            System.out.println("Movie not found.");
        }
    }

    // Main method for testing the system
    public static void main(String[] args) {
        SonamKumari29_moviebookingsystem system =new SonamKumari29_moviebookingsystem();

        // Sample interactions with the system
        system.addMovie("Inception", "7 PM", 50);
        system.addMovie("Titanic", "6 PM", 30);

        system.bookTicket("Inception");
        system.bookTicket("Titanic");

        system.viewAvailableShows();

        system.cancelTicket("Inception");
        system.cancelTicket("Avatar"); // Non-existent movie

        system.searchMovie("Inception");
        system.searchMovie("Avatar"); // Non-existent movie
    }
}
