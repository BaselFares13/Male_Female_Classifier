// Basel Fares Ishreiteh - 221063
// Osayed Jameel Nawajaa - 221119

#include <iostream>
#include <vector>
#include <cmath>

const double PI = 3.14;

using namespace std;

class Person {
    public:
        string gender;
        double height;
        double weight;
        double footSize;

        Person(string gender, double height, double weight, double footSize) {
            this->gender = gender;
            this->height = height;
            this->weight = weight;
            this->footSize = footSize;
        }
};

vector<Person*> InsertedData();
double P(string gender);
double mean(string chr, string gender);
double variance(string chr, string gender);
double P(string chr, string gender, double x);
double P_Gender_Given_Height_Weight_FootSize(string gender,double height, double weight, double footSize);

int main()
{
    double height, weight, footSize;
    cout << "***************************** < WELCOME >  *****************************" << endl;
    cout << "Enter An Height: ";
    cin >> height;
    cout << "Enter A Weight: ";
    cin >> weight;
    cout << "Enter A Foot Size: ";
    cin >> footSize;

    cout << "\nMale Probability = " << P_Gender_Given_Height_Weight_FootSize("Male", height, weight, footSize) << endl;
    cout << "Female Probability = " << P_Gender_Given_Height_Weight_FootSize("Female", height, weight, footSize) << "\n" << endl;

    if (P_Gender_Given_Height_Weight_FootSize("Male", height, weight, footSize) > 
    P_Gender_Given_Height_Weight_FootSize("Female", height, weight, footSize))
    {

        cout << "The Person Is Male" << endl;
    }
    else
    {
        cout << "The Person Is Female" << endl;
    }

    return 0;
}

// Data Of People That Inserted
vector<Person *> InsertedData() {
    vector<Person*> Data;
    Data.push_back(new Person("Male", 6.00, 180, 12));
    Data.push_back(new Person("Male", 5.92, 190, 11));
    Data.push_back(new Person("Male", 5.58, 170, 12));
    Data.push_back(new Person("Male", 5.92, 165, 10));
    Data.push_back(new Person("Female", 5.00, 100, 6));
    Data.push_back(new Person("Female", 5.50, 150, 8));
    Data.push_back(new Person("Female", 5.42, 130, 7));
    Data.push_back(new Person("Female", 5.75, 150, 9));

    return Data;
}

// Probability Of Male Or Female  
double P(string gender ) {
    double MaleCount = 0;

    for (auto person : InsertedData()) {
        if (person->gender == gender)
            MaleCount++;
    }

    return MaleCount / InsertedData().size();
}

// Mean Of An Characteristic Values for Males Or Females
double mean(string chr, string gender)
{
    double mean = 0;
    int count = 0;

    for (auto person : InsertedData()) {
        if(person->gender == gender) {
            if(chr == "Height") {
                mean += person->height;
            } else if(chr == "Weight") {
                mean += person->weight;
            } else if(chr == "FootSize"){
                mean += person->footSize;
            }

            count++;
        }
    }

    mean /= count;

    return mean;
}

// Variance Of An Characteristic Values for Males Or Females
double variance(string chr, string gender) {
    double variance = 0;
    double Mean = mean(chr, gender);
    int count = 0;

    for (auto person : InsertedData()) {
        if(person->gender == gender) {
            if(chr == "Height") {
                variance += pow(person->height - Mean, 2);
            } else if(chr == "Weight") {
                variance += pow(person->weight - Mean, 2);
            }
            else if (chr == "FootSize") {
                variance += pow(person->footSize - Mean, 2);
            }

            count++;
        }
    }

    variance /= count;

    return variance;
}

// Probability Of Characteristic = x Given A Gender => Example : Probability Of Height = 5.8 Given Male
double P(string chr, string gender, double x) {
    double var = variance(chr, gender);
    double mu = mean(chr, gender);
    return exp(-pow(x - mu, 2) / (2 * var)) / sqrt(2 * PI * var);
}

// Probability Of The Gender Given Height, Weight, And FootSize 
double P_Gender_Given_Height_Weight_FootSize(string gender, double height, double weight, double footSize) {
    double P_Male = P("Male");
    double P_Female = P("Female");

    double P_Height_Given_Male = P("Height", "Male", height);
    double P_Height_Given_Female = P("Height", "Female", height);
    double P_Weight_Given_Male = P("Weight", "Male", weight);
    double P_Weight_Given_Female = P("Weight", "Female", weight);
    double P_FootSize_Given_Male = P("FootSize", "Male", footSize);
    double P_FootSize_Given_Female = P("FootSize", "Female", footSize);

    double P_Height_Weight_FootSize_Given_Male = P_Height_Given_Male * P_Weight_Given_Male * P_FootSize_Given_Male;
    double P_Height_Weight_FootSize_Given_Female = P_Height_Given_Female * P_Weight_Given_Female * P_FootSize_Given_Female;

    double P_Height_Weight_FootSize = (P_Height_Weight_FootSize_Given_Male * P_Male) + (P_Height_Weight_FootSize_Given_Female * P_Female);

    if(gender == "Male")
        return (P_Height_Weight_FootSize_Given_Male * P_Male) / P_Height_Weight_FootSize;
    else
        return (P_Height_Weight_FootSize_Given_Female * P_Female) / P_Height_Weight_FootSize;
}