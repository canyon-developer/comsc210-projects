#include <iostream>
#include <string>

using namespace std;

struct Review {
  float rating;
  string comment;
};

class Movie {
public:
  Movie() { reviews = nullptr; }
  Movie(Movie &movie) {}

  Movie &operator=(Movie &movie) {}
  ~Movie() {}

  void addReview(float rate, string review_comment) {
      Review review;
      review.rating = rate;
      review.comment = review_comment;

  }
private:
  string title;
  Review *reviews;  
};