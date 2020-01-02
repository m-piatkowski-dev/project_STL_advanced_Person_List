#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <set>
class PersonIf 
{
   public:
       virtual const std::string & get_name() const = 0;
       virtual const std::string & get_surname() const = 0;
       virtual const std::string & get_address() const = 0;

       virtual const int get_age() const = 0;
       // zwróci string w formacie "YYYY.MM.DD" 
       virtual const std::string get_date_of_birth() const = 0;
       virtual const long long get_pesel() const = 0;
       virtual ~PersonIf()=default;
};

class Person: public PersonIf
{
    public:
    Person() = default;
    Person( const std::string& _name, 
            const std::string& _surname,
            const std::string& _address, 
            const int _age ):
                name(_name), surname(_surname), address(_address), age(_age){}; 
    
    const std::string & get_name() const{return name;} 
    const std::string & get_surname() const{return surname;} 
    const std::string & get_address() const{return address;}  
    const int get_age() const{return age;} 
    const std::string get_date_of_birth() const{return date_of_birth;}  
    const long long get_pesel() const{return pesel;}  
    
    friend std::ostream& operator<<(std::ostream& s,const Person & p)
    {
        s <<p.get_name()<<" "<<p.get_surname()<<" "<<p.get_address()<<" "<<p.get_age()<<std::endl;
        return s;
    };
    
    Person get_random_person()
    {
        const std::array<std::string, 10> imiona{"Anna", "Mariola", "Stefan", "Barbara", "Michal", "Wojciech", "Pawel", "Karol","Roman","Ignacy"};
        const std::array<std::string, 10> nazwiska{"Nowak", "Pawlak", "Moscicki", "Paderewski", "Matejko", "Pilsudski", "Curie", "Wolski","Opel","Kosciuszko"};
        const std::array<std::string, 10> adres{"Szenwalda ", "Wojska Polskiego ", "Niemierzyńska ", "Mickiewicza ", "plac Rodla ", "plac Grunwaldzki ", "Krzywoustego ", "Konopnickiej ", "Traugutta ", "Poniatowskiego "};
        
        return Person(
            imiona[std::rand()%10], 
            nazwiska[std::rand()%10],
            (adres[std::rand()%10])+std::to_string(std::rand()%150+1) +" lat:",
            std::rand()%90+10);
    }
    ~Person()=default;
    private:
    std::string name;
    std::string surname;
    std::string address;
    int age;
    std::string date_of_birth;
    long long pesel;
};

std::set<Person> ludzie;

int main()
{
    std::srand(time(nullptr)); 
    //Person p("Michal", "Piatkowski", 35);

    //std::cout<<p;

    Person s;    
    s=s.get_random_person();
    std::cout<<s;   

    

return 0;
}