#include "Card.hpp"
#include "unit_test_framework.hpp"
#include <iostream>

using namespace std;


TEST(test_card_ctor) {
    Card c(ACE, HEARTS);
    ASSERT_EQUAL(ACE, c.get_rank());
    ASSERT_EQUAL(HEARTS, c.get_suit());
}
TEST(test_card)
{
    Card c(TWO, SPADES);
    ASSERT_EQUAL(Card(), c);
    Card c2(THREE, DIAMONDS);
    ASSERT_EQUAL(c2.get_rank(), THREE);
    ASSERT_EQUAL(c2.get_suit(), DIAMONDS);
}
TEST(test_card_trump)
{
    Card c3(JACK, CLUBS);
    ASSERT_EQUAL(c3.get_suit(SPADES), SPADES);
}
TEST(test_ace_face)
{
    Card c(TEN, CLUBS);
    Card c2(JACK, DIAMONDS);
    Card c3(ACE, HEARTS);
    ASSERT_EQUAL(c.is_face_or_ace(), false);
    ASSERT_EQUAL(c2.is_face_or_ace(), true);
    ASSERT_EQUAL(c3.is_face_or_ace(), true);
}
TEST(test_right)
{
    Card c3(JACK, CLUBS);
    ASSERT_EQUAL(c3.is_right_bower(CLUBS), true);
}
TEST(test_left)
{
    Card c3(JACK, CLUBS);
    ASSERT_EQUAL(c3.is_left_bower(SPADES), true);
}
//Below is taken from public tests
TEST(test_card_insertion) {
    Card three_spades = Card(THREE, SPADES);
    ostringstream oss;
    oss << three_spades;
    ASSERT_EQUAL(oss.str(), "Three of Spades");
}

TEST(test_card_extraction) {
    istringstream iss("Three of Spades");
    Card c;
    iss >> c;
    ASSERT_EQUAL(c, Card(THREE, SPADES));
}

// Add more test cases here

TEST_MAIN()
