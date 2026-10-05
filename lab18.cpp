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

  Movie(Movie &movie) { *this = movie; }

  Movie &operator=(Movie &movie) {
      Review *head = movie.getReviews();
      while (head) {
        float rate = head->rating;
        string comment = head->comment;
        addReview(rate, comment);
      }
      return *this;
  }

  ~Movie() {
    Review *current = reviews;
    while (current) {
      Review *deleted = current;
      current = current->next;
      delete deleted;
    }
  }

  Review *getReviews() { return reviews; }

  void addReview(float rate, string review_comment) {
      if (reviews == nullptr) {
          reviews = new Review;
          reviews->rating = rate;
          reviews->comment = review_comment;
          reviews->next = nullptr;
      } else {
          Review *new_review = new Review;
          new_review->rating = rate;
          new_review->comment = review_comment;
          new_review->next = reviews;
          reviews = new_review;
      }
  }

  

private:
  string title;
  Review *reviews;  
};