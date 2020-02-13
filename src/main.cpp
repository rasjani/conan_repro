#include <sstream>
using namespace std;

class Salutation
{
public:
  static string greet(const string& name);
};

string Salutation::greet(const string& name) {
  ostringstream s;
  s << "Hello " << name << "!";
  return s.str();
}

#include <gtest/gtest.h>

TEST(SalutationTest, Static) {
  EXPECT_EQ(string("Hello World!"), Salutation::greet("World"));
}
