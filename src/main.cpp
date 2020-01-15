#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include "std_lib_facilities.h"

int main() {
  string first_name;
  string friend_name;
  string friend_pronoun;
  char friend_sex;
  int age;

  friend_sex = 0;

  cout << "Enter the name of the person you want to write to\n";
  cin >> first_name;
  cout << "Enter the name of one of your friends\n";
  cin >> friend_name;
  cout << "What is your friend's sex? Enter 'm' for male or 'f' for female.\n";
  cin >> friend_sex;
  cout << "What is the age of the letter recipient?\n";
  cin >> age;

  if (friend_sex == 'm') {
    friend_pronoun = "him";
  }

  if (friend_sex == 'f') {
    friend_pronoun = "her";
  }

  cout << "\n";
  cout << "Dear " << first_name << ",\n";
  cout << "\n";
  cout << "    "
       << "How are you? I am fine. I miss you.\n";
  cout << "Today the weather is mild with light showers in the afternoon.\n";
  cout << "I hear you just had a birthday and you are " << age << " years old.\n";

  if (age < 12) {
    cout << "Next year you will be " << age + 1 << ". ";
  }

  if (age == 17) {
    cout << "Next year you will be able to vote. ";
  }

  if (age > 70) {
    cout << "I hope you are enjoying retirement. ";
  }

  cout << "Have you seen " << friend_name << " lately?"
       << " If you see " << friend_name << " please ask " << friend_pronoun << " to call me.\n";

  cout << "\n";
  cout << "Yours sincerely,\n";
  cout << "\n\n";
  cout << "Peter\n";

  if (age <= 0) {
    simple_error("you're kidding!");
  }

  if (age >= 100) {
    simple_error("you're kidding!");
  }

  keep_window_open();
}
