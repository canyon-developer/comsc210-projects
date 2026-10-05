#include <iostream>
#include <string>

using namespace std;

struct Review {
  float rating;
  string comment;
  Review * next;
};

class Movie {
public:
  Movie() { reviews = nullptr; }
  Movie(Movie &movie) {}

  Movie &operator=(Movie &movie) { return *this; }
  ~Movie() {}

  void addReview(float rate, string review_comment) {
      Review *current = reviews;
      if (current == nullptr) {
        reviews = new Review;
        reviews->rating = rate;
        reviews->comment = review_comment;
        reviews->next = nullptr;
      } else {
        Review *next = current->next;
        while (next) {
          current = next;
          next = next->next;
        }
        Review *new_review = new Review;
        new_review->rating = rate;
        new_review->comment = review_comment;
        new_review->next = nullptr;
        current->next = new_review;
      }
  }
private:
  string title;
  Review *reviews;  
};