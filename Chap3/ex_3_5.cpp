// Exercise 3-5

#include<iostream>
#include<string>
#include<vector>
#include<climits>

int main(){

    std::vector<std::string> names;
    std::vector<double> final_grades;

    std::string name;
    do{
        std::cout << "\nPlease enter student's name (or 'done' if you are done): ";
        std::cin >> name;
        if(name.compare("done")){
            double sum = 0;
            int count = 0;
            double grade = 0;
            std::cout << "\nPlease enter " << name << "'s homework grades, "
            "separated by <enter>. Enter -1 when you are done." << std::endl;
            while(grade>=0){
                std::cin >> grade;
                if(grade>=0){
                    sum += grade;
                    ++count;
                }
            }
            names.push_back(name);
            final_grades.push_back(sum/count);
        }
        // flush the input stream
        std::cin.clear();
        std::cin.ignore();

    } while (name.compare("done"));

    for(int i=0;i<names.size();++i){
        std::cout << "Name: " << names[i];
        std::cout << ", Final grade: " << final_grades[i] << std::endl;
    }

    return 0;
}

