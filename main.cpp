
#include <algorithm>
#include <iterator>
#include "SetList.h"
#include "MapArray.h"
#include <fstream>
int main()
{
    ifstream in("stopwords.txt");
    ifstream input("sample_doc.txt");
    ofstream output("frequency.txt");
    vector<string> V1;
    vector<string> V2;
    SetList<string> b;
    MapArray<string,int> M(565);
    copy(istream_iterator<string>(in),istream_iterator<string>(),back_inserter(V1));
    copy(istream_iterator<string>(input),istream_iterator<string>(),back_inserter(V2));
    for_each(begin(V2),end(V2),[&](string &s){transform(s.begin(), s.end(), s.begin(), ::tolower);});
    for_each(begin(V1),end(V1),[&](string &s){b.insert(s);});
    for_each(begin(V2),end(V2),[&](string &s){if(!b.find(s)) M[s]++;});
    for_each(M.begin(),M.end(),[&](pair<string,int> &p){cout <<"The frenquency of " << p.first <<" is " <<  p.second << endl;});
    cout << "Start writing into file " << endl;
    for_each(M.begin(),M.end(),[&](pair<string,int> &p){output <<"The frenquency of " << p.first <<" is " <<  p.second << endl;});
    cout << "Finished!" << endl;

    return 0;
}