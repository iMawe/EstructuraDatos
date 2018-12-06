#include <iostream>
#include <string>

using namespace std;

int pos[128];

struct Node{
    Node(){
        next[0] = next[1] = next[2] = next[3] = NULL;
    }
    
    Node* next[4];
    int Insert(const string & str, int index){
        if (index == str.size()) return 0;
        int toGoInto = pos[str[index]];
        if (next[toGoInto]){
            return next[toGoInto]->Insert(str, index + 1) + 1;
        }
        else{
            next[toGoInto] = new Node();
            next[toGoInto]->Insert(str, index + 1);
            return 0;
        }
    }

    void Delete(){
        for (int i = 0; i < 4; ++i){
            if (next[i] != NULL){
                next[i]->Delete();
                delete next[i];
            }
        }
    }
};


int main(){
    pos['A'] = 0;
    pos['C'] = 1;
    pos['G'] = 2;
    pos['T'] = 3;
    int N;
    cin >> N;
    while (N--){
        Node baseNode;
        string exten = "";
        int aux;
        string word;
        cin >> word;
        
        for (int i = 0; i < word.size(); ++i){
            int tamw = baseNode.Insert(word, i);
            if (tamw > exten.size()){
                exten = word.substr(i, tamw);
                aux = 2;
            }
            else if (tamw == exten.size()){
                string auxT = word.substr(i, tamw);
                if (auxT < exten) exten = auxT;
                else if (auxT == exten) ++aux;
            }
        }
        if (exten == "")
            cout << "No repetitions found!\n";
        else
            cout << exten << ' ' << aux << '\n';
    }
}