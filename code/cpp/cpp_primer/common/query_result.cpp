

#include "query_result.h"

using namespace std;

ostream &Print(ostream &os, const QueryResult &result)
{
    os  << result.sought_word_ << " occurs: " 
        << result.lines_->size()
        << (result.lines_->size() > 1 ? " times" : " time") 
        << endl;
#if 0
     for (const auto &num : *result.lines_)
         cout << " ( " << num + 1 << " ) : "
              << *(result.file_->begin() + num)
              << endl;

     for (const auto &num : *result.lines_)
         cout << " ( " << num + 1 << " ) : "
              << result.file_.Begin().Deref(num)
              << endl;
#endif
    //已经处理了lines_为0的情况
    for (const auto &num : *result.lines_)
        cout << "\nline number: " << num + 1 << " : "
             << *(result.file_->Begin() + num) << endl;

    return os;
}
