
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

#include "student_info.h"

using namespace std;

int main()
{
    vector<ver2::StudentInfo>   students;
    ver2::StudentInfo           record;
    string::size_type           max_len = 0;

    while (record.Read(cin))
    {
        max_len = max(max_len, record.Name().size());
        students.push_back(record);

        char ch;
        std::cout << "continue(Y(y)/N(n))?";
        std::cin >> ch;
        if (ch != 'Y' && ch != 'y')
            break;
    }

    sort(students.begin(), students.end(), ver2::StudentInfo::Compare);

    for (vector<ver2::StudentInfo>::size_type i = 0; i != students.size(); i++)
    {
        cout << setw(max_len + 1) << students[i].Name();

        try {
            double final_grade = students[i].Grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        cout << endl;
    }

    return 0;
}
