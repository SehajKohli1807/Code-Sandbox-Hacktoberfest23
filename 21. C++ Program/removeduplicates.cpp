#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> removeDuplicates(int*a, int size) {
    vector<int> output;
    unordered_map<int,bool> seen;
    for(int i=0;i<size;i++) {
        if (seen.count(a[i])>0) {
            continue;
        }
        seen[a[i]]=true;
        output.push_back(a[i]);
    }
    return output;
}

int main()
{
  int arr[]={11,45,32,22,11,90,11,5,78,98,22,66,3,22};
  vector<int> v= removeDuplicates(arr,14);
  for(int i=0;i<v.size();i++) {
      cout<<v[i]<<" ";
  }

    return 0;
}
