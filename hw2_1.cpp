#include <iostream>
#include <string>
 
using namespace std;
static int st_count = 0; 			//счетчик студентов

class Person {
	private:
		
		string m_name;
		char* m_sex;
		int m_age;
		int m_weight;
	
	public:
	
		Person (string name, char* sex, int age, int weight)					//Конструктор Person;
		:m_name(name), m_sex(sex), m_age(age), m_weight(weight) {}
		
		void set_name (string name) {
			m_name = name;
		}
		
		void set_age (int age) {
			m_age = age;
		}
		
		void set_weight (int weight) {
			m_weight = weight;
		}
		
		friend class Student;
};

class Student : public Person {
	private:
	
		int m_ed_year;
		
	public:
	
		Student (string name, char* sex, int age, int weight, int ed_year)
		:Person(name, sex, age, weight), m_ed_year(ed_year) {st_count++;}
		
		void set_ed_year (int ed_year) {
			m_ed_year = ed_year;
		}
		
		void increase_ed_year (int ed_year) {
			m_ed_year++;
		}
		
		void print () {
			cout << "Student name: "<< m_name << endl << 
			"Sex: "<< m_sex << endl << 
			"Age: " << m_age << endl << 
			"Weight: "<< m_weight << endl << 
			"Year of study: " <<m_ed_year << endl;
		}
};

int main () {
	int num;
	
	Student student1("Alex", "m", 18, 75, 2);
	Student student2("Marley", "f", 17, 47, 1);
	Student student3("Tom", "f", 20, 78, 4);
	
	cout << "Number of students is " << st_count << endl << endl;
	cout << "Select your student: ";
	cin >> num;
	cout << endl;
	
	switch (num) {
		case 1: 
			student1.print();
			break;
		case 2: 
			student2.print();
			break;
		case 3: 
			student3.print ();
			break;
		default:
			cout << "There is no such student" << endl;
			break;
	}
}
