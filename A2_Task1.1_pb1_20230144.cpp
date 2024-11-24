#include<iostream>
#include<fstream>

using namespace std;

class LabelGenerator{
    string pref;
    int num;
public:
    LabelGenerator (string name,int x ){
        pref = name;
        num = x;
    }
    virtual string nextLabel() {
        return pref+' '+to_string(num++);
    }
};

class FileLabelGenerator : public LabelGenerator {
    ifstream ifile;
public:
    FileLabelGenerator(string name,int x , string f): LabelGenerator(name,x){
        ifile.open(f);
    }
    string nextLabel() override{
        string lab="";
        ifile>>lab;
        return LabelGenerator::nextLabel()+' '+lab;
    }
};

int main(){
    bool menu=1;
    while (menu) {
        cout << "Choose an option:" << '\n';
        cout << "1.Creat new Labels" << '\n';
        cout << "2.Creat Labels with files" << '\n';
        cout << "3.Exite" << '\n';
        int x;
        cin >> x;
        if (x == 1) {
            string prefix;
            cout << "Enter a prefix:" << '\n';
            cin >> prefix;
            int indx;
            cout << "Enter the intial index:" << '\n';
            cin >> indx;
            int num;
            cout << "Enter number of labels:" << '\n';
            cin >> num;
            LabelGenerator figureNumbers(prefix, indx);
            cout << "Labels: \n";
            for (int i = 0; i < num; i++) {
                cout << figureNumbers.nextLabel() << ", ";
            }
            cout << '\n';
        }
        else if (x == 2) {
            string prefix;
            cout << "Enter a prefix:" << '\n';
            cin >> prefix;
            int indx;
            cout << "Enter the intial index:" << '\n';
            cin >> indx;
            string filename;
            cout << "Enter a File Name:\n";
            cin >> filename;
            int num;
            cout << "Enter number of labels:" << '\n';
            cin >> num;
            FileLabelGenerator figureNumbers(prefix, indx, filename);
            cout << "Labels: ";
            for (int i = 0; i < num; i++) {
                cout << figureNumbers.nextLabel() << ", ";
            }
        }
        else{
            menu=0;
        }
    }
    return 0;
}
