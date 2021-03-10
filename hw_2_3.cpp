#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
class Deck {
	public:
		class Card {
			private:
				string m_name;
				int m_value;
				int m_amount = 4;
			public:
				Card (){};
				Card (string name, int value)
				:m_name(name), m_value(value){}
				
				
				string get_name () {
					return m_name;
				}
				
				int get_value () {
					if (m_amount) {
						m_amount--;
						return m_value;
					}
				}
				
				int get_amount () {
					return m_amount;
				}
		};
		
		Card cards[13];
		
		Deck () {
			cards[0] = Card("Two", 2);
			cards[1] = Card("Three", 3);
			cards[2] = Card("Four", 4);
			cards[3] = Card("Five", 5);
			cards[4] = Card("Six", 6);
			cards[5] = Card("Seven", 7);
			cards[6] = Card("Eight", 8);
			cards[7] = Card("Nine", 9);
			cards[8] = Card("Ten", 10);
			cards[9] = Card("Jack", 10);
			cards[10] = Card("Queen", 10);
			cards[11] = Card("King", 10);
			cards[12] = Card("Ace", 11);
		}
		
		int rand_card() {
			srand(time(NULL));
			int r = rand()%13;
			return r;
		}
		
		friend class player;
};

class Player {
	private:
		string m_name;
		int m_score;
		bool m_turn;
	public:
		Player ( string name, int score = 0, bool turn = 0)
		:m_name(name), m_score(score), m_turn(turn) {}
		
		string get_name () {
			return m_name;
		}
		
		int get_score () {
			return m_score;
		}
		
		int set_score (int score) {
			m_score = m_score + score;
		}
		
		int check_turn () {
			return m_turn;
		}
		
		void switch_turn () {
			m_turn==0 ? m_turn = 1 : m_turn = 0;
		}
		
		friend class Deck;
};	

int main () {
	Deck deck;
	Player player("John", 0, 0);
	Player Dealer("Dealer", 0, 1);
	
	cout << "Game is about to start" << endl;
	cout << "Player and Dealer take cards" << endl << endl;
	
	while (player.get_score()<21) {
			char answer;
			cout << "You get " << deck.cards[deck.rand_card()].get_name() <<endl;
			player.set_score(deck.cards[deck.rand_card()].get_value());
			cout << "Your total score is " << player.get_score() << endl;
				
				if (player.get_score()<21) {
					cout << "Want to take one more card? y/n" << endl;
					cin >> answer;
					switch (answer) {
						case 'y': continue;
						case 'n': {
							cout << "Your total score is " << player.get_score() << endl;
							break;
						};
					}
				}
				else if (player.get_score()==21) {
					cout << "BLACK JACK!!!" << endl;
				}
				else { cout << "Sorry, you lose (-_-)" << endl;};
		};
}
