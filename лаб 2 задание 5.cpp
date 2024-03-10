#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Person {
  string lastName;
  string firstName;
    string middleName;
    string phoneNumber;
    string postalCode;
    string country;
    string region;
    string district;
    string city;
    string street;
    string house;
    string apartment;
    string carBrand;
    string carNumber;
    string techPassportNumber;
};

int main() {
    setlocale(LC_ALL, "RU");
    // Создание текстового файла и запись в него информации о людях и их автомобилях
    std::ofstream file("people.txt");
    if (!file.is_open()) {
        std::cout << "Не удалось создать файл people.txt" << std::endl;
        return 1;
    }

    Person person1 = { "Иванов", "Иван", "Иванович", "+7(123)456-78-90", "111111", "Россия", "Московская область", "Ленинский район", "Москва", "Ленина", "5", "10", "Ваз", "А001ВА", "1234567890" };
    Person person2 = { "Петров", "Петр", "Петрович", "+7(234)567-89-01", "222222", "Россия", "Ленинградская область", "Кировский район", "Санкт-Петербург", "Кирова", "7", "22", "Ваз", "А002ВА", "2345678901" };
    Person person3 = { "Сидоров", "Сидор", "Сидорович", "+7(345)678-90-12", "333333", "Россия", "Ростовская область", "Центральный район", "Ростов-на-Дону", "Ленина", "15", "33", "Toyota", "А003ТО", "3456789012" };

    file << person1.lastName << "; " << person1.firstName << "; " << person1.middleName << "; " << person1.phoneNumber << "; " << person1.postalCode << "; " << person1.country << "; " << person1.region << "; " << person1.district << "; " << person1.city << "; " << person1.street << "; " << person1.house << "; " << person1.apartment << "; " << person1.carBrand << "; " << person1.carNumber << "; " << person1.techPassportNumber << std::endl;
    file << person2.lastName << "; " << person2.firstName << "; " << person2.middleName << "; " << person2.phoneNumber << "; " << person2.postalCode << "; " << person2.country << "; " << person2.region << "; " << person2.district << "; " << person2.city << "; " << person2.street << "; " << person2.house << "; " << person2.apartment << "; " << person2.carBrand << "; " << person2.carNumber << "; " << person2.techPassportNumber << std::endl;
    file << person3.lastName << "; " << person3.firstName << "; " << person3.middleName << "; " << person3.phoneNumber << "; " << person3.postalCode << "; " << person3.country << "; " << person3.region << "; " << person3.district << "; " << person3.city << "; " << person3.street << "; " << person3.house << "; " << person3.apartment << "; " << person3.carBrand << "; " << person3.carNumber << "; " << person3.techPassportNumber << std::endl;

    file.close();
    ifstream file1("people.txt");
    string line2;
    cout << "Изначальный файл" << std::endl;
    while (!file1.eof()) {
       getline(file1, line2);
        cout << line2 << endl;
    }

   string path = "res.txt";
    // Чтение данных про автомобили марки "Ваз" из файла
   ifstream readFile("people.txt");
    if (!readFile.is_open()) {
       cout << "Не удалось открыть файл people.txt" <<endl;
        return 1;
    }
    int ress = 1;
    cout << "данные о машинах" << endl;
    string line;
    while (std::getline(readFile, line)) {
        size_t pos = 0;
       string delimiter = "; ";
        string token;
        int count = 0;
        while ((pos = line.find(delimiter)) !=string::npos) {
            token = line.substr(0, pos);
            line.erase(0, pos + 2);
            count++;
            if (token == "Ваз") {
                cout << "Машина " << ress << endl;
                std::ofstream fout;
                fout.open(path, ofstream::app);
               cout << "Марка автомобиля: " << token << endl;
                fout << "Машина"<<ress<<": " << token<<" ";
                cout << "Номер автомобиля: " << line.substr(0, line.find(delimiter)) << endl;
                fout << line.substr(0, line.find(delimiter)) << " ";
                line.erase(0, line.find(delimiter)+2);
               cout << "Паспорт автомобиля: " << line.substr(0, line.find(delimiter)) << endl;
                fout << line.substr(0, line.find(delimiter)) << "; ";
                ress++;
            }
        }
    }

    readFile.close();

    return 0;
}
