
#include "chapter_03.h"
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <fstream>
#include <set>
#include <sstream>

using namespace std;

const int s_int_size = 12;
const int s_string_size = 4;

int     s_ia[s_int_size] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };
string  s_sa[s_string_size] = { "pooh", "piglet", "eeyore", "tigger" };

vector<int>     s_ivec(s_ia, s_ia + s_int_size);
vector<string>  s_svec(s_sa, s_sa + s_string_size);

const int* FindVec(const vector<int> &vec, int val)
{
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == val)
            return &vec[i];

    return 0;
}

void Chapter_03()
{
    //Practice_3_1();
    //Practice_3_6();
    //Practice_3_9();

    //Homework_3_1();
    //Homework_3_2();
    //Homework_3_3();
    Homework_3_4();
}

void Practice_3_1()
{
    const int       *iptr = nullptr;
    const string    *sptr = nullptr;

    iptr = FindVec(s_ivec, s_ivec[5]);
    if (iptr == &s_ivec[5])
        cout << *iptr << endl;
    else
        cout << "test no template func failed, ret: "
             << *iptr << endl;

    iptr = FindVer1(s_ivec, s_ivec[6]);
    if (iptr == &s_ivec[6])
        cout << *iptr << endl;
    else
        cout << "test FindVer1 with int array type func failed, ret: "
             << *iptr << endl;

    sptr = FindVer1(s_svec, s_svec[0]);
    if (sptr == &s_svec[0])
        cout << *sptr << endl;
    else
        cout << "test FindVer1 with char array type func failed, ret: "
             << *sptr << endl;

    iptr = FindVer2(s_ia, s_int_size, s_ia[7]);
    if (iptr == &s_ia[7])
        cout << *iptr << endl;
    else
        cout << "test FindVer2 with int array type func failed, ret: "
             << *iptr << endl;
    
    sptr = FindVer2(s_sa, s_string_size, s_sa[2]);
    if (sptr == &s_sa[2])
        cout << *sptr << endl;
    else
        cout << "test FindVer2 with char array type func failed, ret: "
             << *sptr << endl;

    iptr = FindVer3(s_ia, s_int_size, s_ia[7]);
    if (iptr == &s_ia[7])
        cout << *iptr << endl;
    else
        cout << "test FindVer3 with int array type func failed, ret: "
             << *iptr << endl;
    
    sptr = FindVer3(s_sa, s_string_size, s_sa[2]);
    if (sptr == &s_sa[2])
        cout << *sptr << endl;
    else
        cout << "test FindVer3 with char array type func failed, ret: "
             << *sptr << endl;

    iptr = FindVer4(s_ia, s_ia + s_int_size, s_ia[8]);
    if (iptr == &s_ia[8])
        cout << *iptr << endl;
    else
        cout << "test FindVer4 with int array type func failed, ret: "
             << *iptr << endl;
    
    sptr = FindVer4(s_sa, s_sa + s_string_size, s_sa[3]);
    if (sptr == &s_sa[3])
        cout << *sptr << endl;
    else
        cout << "test FindVer4 with char array type func failed, ret: "
             << *sptr << endl;

    iptr = FindVer4(Begin(s_ivec), End(s_ivec), s_ivec[9]);
    if (iptr == &s_ivec[9])
        cout << *iptr << endl;
    else
        cout << "test FindVer4 with int vector type func failed, ret: "
             << *iptr << endl;
    
    sptr = FindVer4(Begin(s_svec), End(s_svec), s_svec[3]);
    if (sptr == &s_svec[3])
        cout << *sptr << endl;
    else
        cout << "test FindVer4 with char vector type func failed, ret: "
             << *sptr << endl;

    iptr = FindVer5(s_ia, s_ia + s_int_size, s_ia[10]);
    if (iptr == &s_ivec[10])
        cout << *iptr << endl;
    else
        cout << "test FindVer5 with int array type func failed, ret: "
             << *iptr << endl;

    sptr = FindVer5(Begin(s_svec), End(s_svec), s_svec[1]);
    if (sptr == &s_svec[1])
        cout << *sptr << endl;
    else
        cout << "test FindVer5 with char vector type func failed, ret: "
             << *sptr << endl;

    list<int>    slist(s_ia, s_ia + s_int_size);
    list<int>::iterator it = FindVer5(slist.begin(), slist.end(), 1024);
    if (it != slist.end())
        cout << *it << endl;
    else
        cout << "not find appoint val."
             << endl;
}

bool LessThan(int v1, int v2) { return v1 < v2 ? true : false; }
bool GreaterThan(int v1, int v2) { return v1 > v2 ? true : false; } 

vector<int> FilterVer1(const vector<int> &vec, int filter_val, bool (*pred)(int, int))
{
    vector<int> nvec;
    for (int ix = 0; ix < vec.size(); ++ix)
        if (pred(vec[ix], filter_val))
            nvec.push_back(vec[ix]);

    return nvec;
}

int CountOccurs(const vector<int> &vec, int val)
{
    vector<int>::const_iterator it = vec.begin();
    int occurs = 0;

    while ((it = find(it, vec.end(), val)) != vec.end())
    {
        ++occurs;
        ++it;
    }
    
    return occurs;
}

vector<int> FilterVer2(const vector<int> &vec, int val, const less<int> &lt)
{
    vector<int> nvec;
    vector<int>::const_iterator it = vec.begin();

    while ((it = find_if(it, vec.end(), bind2nd(lt, val))) != vec.end())
    {
        nvec.push_back(*it);
        ++it;
    }
    
    return nvec;
}

vector<int> SubVec(const vector<int> &vec, int val)
{
    //排序
    vector<int> local_vec(vec);
    sort(local_vec.begin(), local_vec.end());

    //找出第一复合要求值
    auto find_it = find_if(local_vec.begin(), local_vec.end(),
                           bind2nd(greater<int>(), val));

    //删除元素
    local_vec.erase(find_it, local_vec.end());
    return local_vec;
}

void Practice_3_6()
{
    const int ret_size = 6;
    const int part_val = 10;

    vector<int> vec1 = FilterVer1(s_ivec, part_val, GreaterThan);
    if (vec1.size() != ret_size)
        cout << "test filter ver1 failed. ret size: " << vec1.size() << endl;
    else
        cout << "test filter ver1 ok." << endl;
    
    vector<int> vec2 = FilterVer2(s_ivec, part_val, less<int>());
    cout << "less than 10 vector size: " << vec2.size() << endl;

    int ia2[s_int_size];
    FilterVer3(s_ia, s_ia + s_int_size, ia2, part_val, less<int>());
//    cout << end(ia2) - begin(ia2) << endl;

    vector<int> vec3;
    FilterVer3(s_ia, s_ia + s_int_size, back_inserter(vec3), part_val, less<int>());
    cout << vec3.size() << endl;

    list<string> slist;
    FilterVer3(s_sa, s_sa + s_string_size, back_inserter(slist), "piglet", greater<string>());
    cout << slist.size() << endl;

    auto ret_vec = SubVec(s_ivec, part_val);
    cout << ret_vec.size() << endl;
}

void Practice_3_9()
{
    // istream_iterator<string>    is(cin);
    // istream_iterator<string>    eof;

    // vector<string>  local_vec;
    // copy(is, eof, back_inserter(local_vec));
    // sort(local_vec.begin(), local_vec.end());

    // ostream_iterator<string>    os(cout, "\t");
    // copy(local_vec.begin(), local_vec.end(), os);
    // cout <<endl;

    fstream     in_file("Makefile");
    ofstream    out_file("test.txt");    
    
    if (!in_file || !out_file)
    {
        cout << "open input/output file failed." << endl;
        return ;
    }
    
    istream_iterator<string>    is(in_file);
    istream_iterator<string>    eof;

    vector<string>  vec;
    copy(is, eof, back_inserter(vec));

    sort(vec.begin(), vec.end());

    ostream_iterator<string>    os(out_file, "\n");
    copy(vec.begin(), vec.end(), os);
}

#include <iostream>
#include <fstream>
#include <map>

void InitExclusionSet(set<string> &exs)
{
    static string exclusion_words[26] = {
        "the","and","but","that","then","are","been",
        "can","a","could","did","for", "of",
        "had","have","him","his","her","its","is",
        "were","which","when","with","would"
    };

    exs.insert(exclusion_words, exclusion_words + 26);
}

void ProcessFile(map<string, int> &word_map,
                 const set<string> &exclude_set,
                 ifstream &ifile)
{
    string word;
    while (ifile >> word)
    {
        if (exclude_set.count(word))
            continue;

        word_map[word]++;
    }
}

void UserQuery(const map<string, int> &word_map)
{
    cout << " please enter a search word: ";
    string word;
    cin >> word;

    while (word.size() && word != "q")
    {
        auto it = word_map.find(word);
        if (it != word_map.end())
            cout << "found " << it->first
                 << " occurs " << it->second
                 << " times.\n";
        else
            cout << word << " was not found in text.\n"
                 << " anther search?(q to quit) ";
        cin >> word;
    }
}

void DisplayWordCount(const map<string, int> &word_map, ostream &out)
{
    auto it = word_map.begin();
    while (it != word_map.end())
    {
        out << "< " << it->first
            << ", "
            << it->second << " >\n";
        ++it;
    }
}


void Homework_3_1()
{
    ifstream    in_file("moo_cat.txt");
    ofstream    out_file("moo_cat.map");

    if (!in_file || !out_file)
    {
        cerr << "unalbe to open file!" << endl;
        return ;
    }
    
    set<string> exclude_set;
    InitExclusionSet(exclude_set);

    map<string, int>    word_count;
    ProcessFile(word_count, exclude_set, in_file);

    //UserQuery(word_count);
    DisplayWordCount(word_count, out_file);
}


class StrSizeComp
{
public:
    bool operator()(const string &s1, const string &s2)
    {
        return s1.size() < s2.size();
    }
};

void Homework_3_2()
{
    ifstream    in_file("moo_cat.txt");
    ofstream    out_file("moo_cat.out");

    if (!in_file || !out_file)
    {
        cerr << "unalbe to open file!" << endl;
        return ;
    }

    vector<string>  text;
    string          word;
    while (in_file >> word)
    {
        cout << word << ' ';
        text.push_back(word);
    }

    sort(text.begin(), text.end(), StrSizeComp());

    for (auto it = text.begin(); it != text.end(); ++it)
        cout << *it << "\n";
}


typedef vector<string> vstring;
typedef string::size_type ssize_type;

void InitFamilyMap(ifstream &in, map<string, vstring> &family)
{
    string line;
    while (getline(in, line, '\n'))
    {
        string  fam_name;
        vstring childs;
        ssize_type pos = 0, prev_pos = 0, line_size = line.size();

//        cout << "text line: " << line << endl;
//        while ((pos = line.find_first_of(' ', pos)) != string::npos)
//        {
//            if (!prev_pos)
//                fam_name = line.substr(prev_pos, pos - prev_pos);
//            else
//                childs.push_back(line.substr(prev_pos, pos - prev_pos));

//            prev_pos = ++pos;
//        }

//        //最后一个名字
//        if (prev_pos < line_size)
//            childs.push_back(line.substr(prev_pos, pos - prev_pos));

        stringstream ss(line);
        ss >> fam_name;

        string child_name;
        while (ss >> child_name)
            childs.push_back(child_name);

        cout << "family name: " << fam_name
             << ", childrens count: " << childs.size()
             << endl;

        if (!family.count(fam_name))
            family[fam_name] = childs;
        else
            cerr << "family: " << fam_name
                 << " already in our map!\n";
    }
}

void DisplayMap(const map<string, vstring> &familes, ostream &out)
{
    auto it = familes.begin();
    while (it != familes.end())
    {
        out << "the family " << it->first;
        if (it->second.empty())
            out << " has no children.\n";
        else
        {
            auto iter = it->second.begin();
            out << "\n";
            while (iter != it->second.end())
            {
                out << '\t'<< *iter << endl;
                ++iter;
            }
        }
        ++it;
    }
}

typedef map<string, vstring> svec_map;
void QueryMap(const string &family, svec_map familes)
{
    svec_map::const_iterator cit = familes.find(family);
    if (cit == familes.cend())
    {
        cerr << "sorry, family: " << family
             << " is not occurs int current map\n";
        return ;
    }

    cout << "the " << family << " family ";
    if (!cit->second.size())
        cout << "has no children!\n";

    else
    {
        cout << "has " << cit->second.size() << " childrens.\n";
        auto citer = cit->second.begin();
        while (citer != cit->second.end())
        {
            cout << "\t" << *citer << "\n";
            ++citer;
        }
    }
}

void Homework_3_3()
{
    ifstream    name_file("families.txt");
    if (!name_file)
    {
        cerr << "open name file failed.\n";
        return ;
    }

    svec_map    familes;
    InitFamilyMap(name_file, familes);

    string      name;
    while (1)
    {
        cout << "please enter a family name or q to quit: ";
        cin >> name;
        if (name == "q")
            break;

        QueryMap(name, familes);
    }

    DisplayMap(familes, cout);
}

class EvenElem
{
public:
    bool operator()(const string &s)
    {
        return s.size() % 2 ? false : true;
    }
};

void Homework_3_4()
{
    ifstream    name_file("families.txt");
    if (!name_file)
    {
        cerr << "open input name file failed.\n";
        return ;
    }

    ofstream even_file("even_file"),
             odd_file("odd_file");
    if (!even_file || !odd_file)
    {
        cerr << "open out file failed.\n";
        return ;
    }

    istream_iterator<string>    in(name_file), eof;
    vector<string>  input;

    copy(in, eof, back_inserter(input));
    vector<string>::iterator div = partition(input.begin(), input.end(), EvenElem());

    ostream_iterator<string> even_it(even_file, "\n"),
                             odd_it(odd_file, "\t");

    copy(input.begin(), div, even_it);
    copy(div, input.end(), odd_it);
}
